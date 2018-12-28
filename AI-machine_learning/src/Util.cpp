#include  "Util.h"
#include <set>

namespace Util {
    
std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void plotMatrix( QCustomPlot* customPlot, const arma::mat& matrix ) {
  // add two new graphs and set their look:
  customPlot->addGraph();
  customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
  customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
  customPlot->addGraph();
  customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
  // generate some points of data (y0 for first, y1 for second graph):
  QVector<double> x(matrix.n_rows), y0(matrix.n_rows), y1(matrix.n_rows);
  for (size_t i=0; i<matrix.n_rows; ++i)
  {
    x[i] = matrix(i,0);
    y0[i] = matrix(i,1);
    y1[i] = matrix(i,2);
  }
  // configure right and top axis to show ticks but no labels:
  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
  customPlot->xAxis2->setVisible(true);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setVisible(true);
  customPlot->yAxis2->setTickLabels(false);
  // make left and bottom axes always transfer their ranges to right and top axes:
//  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
//  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  // pass data points to graphs:
  customPlot->graph(0)->setData(x, y0);
  customPlot->graph(1)->setData(x, y1);
  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
  customPlot->graph(0)->rescaleAxes();
  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
  customPlot->graph(1)->rescaleAxes(true);
  // Note: we could have also just called customPlot->rescaleAxes(); instead
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

  customPlot->resize(1200,780);
  customPlot->show();
}

void removeDuplication(arma::mat& dataset) {
    QCryptographicHash hash(QCryptographicHash::Md5);
    std::set<QByteArray> hashes;
    std::vector<size_t> marked;
    for( size_t m = 0; m < dataset.n_rows; ++m ) {
        for( size_t j = 0; j < dataset.n_cols; ++j ) {
            double v = dataset(m, j);
            hash.addData((char*)&v, (int)sizeof(v));
        }
        if( hashes.find(hash.result()) != hashes.end()) {
            marked.push_back(m);
        }
        hash.reset();
    }

    for( auto it = marked.rbegin(); it != marked.rend(); ++it ) {
        // remove a row from dataset
        dataset.shed_row(*it);
    }
}

void prepareTrainingAndValidationSet(const arma::mat& X, const arma::mat& y, arma::mat& Xtraining, arma::mat& Ytraining, arma::mat& Xval, arma::mat& Yval,
                                                       std::set<double> ignored_labels, size_t itemLimitPerLabel, const double percentage) {
    arma::mat dataset = join_rows( X, y );
    dataset = shuffle(dataset);
    Util::removeDuplication(dataset);

    // 70% of every single label will be taken into the training set,
    // the others will be put into the validation set
    size_t accepted_num = 0;
    std::map<const double,size_t> dataSetStat;
    for( size_t i = 0; i < dataset.n_rows; ++i ){
        double yv = y(i,0);
        auto it = dataSetStat.find(yv);
        if( it != dataSetStat.end()) {
            ++it->second;
            ++accepted_num;
        } else {
            if(ignored_labels.find(yv) == ignored_labels.end()){
                dataSetStat.emplace(yv,1);
                ++accepted_num;
            }
        }
    }

    size_t row_num = 0;
    std::for_each(dataSetStat.begin(),dataSetStat.end(),
                    [&row_num,itemLimitPerLabel,percentage](std::pair<const double,size_t>&x){
                        x.second *= percentage;
                        if(itemLimitPerLabel > 0 && x.second > itemLimitPerLabel)
                            x.second = itemLimitPerLabel;
                        row_num += x.second;
                    });
    Xtraining = arma::mat(row_num, X.n_cols);
    Ytraining = arma::mat(row_num, 1);
    Xval = arma::mat(accepted_num - row_num, X.n_cols);
    Yval = arma::mat(accepted_num - row_num, 1);

    for( size_t i = 0, curr_row_t = 0, curr_row_v = 0; i < dataset.n_rows; ++i ) {
        std::cout << "row: " << i << "\r" << std::flush;

        double yv = dataset(i,dataset.n_cols - 1);
        if(ignored_labels.find(yv) != ignored_labels.end()){
            continue;
        }

        arma::mat x = dataset.rows(i,i).cols(0,dataset.n_cols-2);
        auto it = dataSetStat.find(yv);
        if(it->second > 0 ) {
            --it->second;
            if( curr_row_t >= row_num )
                throw "prepareTrainingAndValidationSet";
            Xtraining.row(curr_row_t) = x;
            Ytraining.row(curr_row_t) = arma::mat{yv};
            ++curr_row_t;
        } else {
            if( curr_row_v >= Xval.n_rows )
                throw "prepareTrainingAndValidationSet";
            Xval.row(curr_row_v) = x;
            Yval.row(curr_row_v) = arma::mat{yv};
            ++curr_row_v;
        }
    }
}

arma::mat mapFeature( const arma::mat& X1, const arma::mat& X2, int degree ){
    arma::mat out = arma::mat(X1.n_rows, 0);
    for( int i = 1; i <=degree; ++i ){
        for( int j = 0; j <= i; ++j ) {
            //(X1.^(i-j)).*(X2.^j);
            out = join_rows(out, arma::pow(X1,i-j)%(arma::pow(X2,j)));
        }
    }
    return out;
}

int getLabelCount( const arma::mat& y ) {
    std::set<double> labels;
    for(size_t i = 0; i < y.n_rows; ++i)
        labels.insert(y(i,0));
    return labels.size();
}

arma::mat plus( arma::mat x, arma::mat y ) {
    if( x.n_cols == y.n_cols && y.n_rows == 1 ) {
        for( size_t i = 0; i < x.n_rows; ++i ){
            x.row(i) += y.row(0);
        }
        return x;
    } else if( x.n_rows == y.n_rows && y.n_cols == 1) {
        for( size_t i = 0; i < x.n_cols; ++i ){
            x.col(i) += y.col(0);
        }
        return x;
    } else if( x.n_cols == y.n_cols && x.n_rows == 1 ) {
        for( size_t i = 0; i < y.n_rows; ++i ){
            y.row(i) += x.row(0);
        }
        return y;
    } else if( x.n_rows == y.n_rows && x.n_cols == 1) {
        for( size_t i = 0; i < y.n_cols; ++i ){
            y.col(i) += x.col(0);
        }
        return y;
    } else {
        throw "Illegal size for broadcasting plus\n";
    }
    return x;
}

arma::mat minus( arma::mat x, arma::mat y ) {
    if( x.n_cols == y.n_cols && y.n_rows == 1 ) {
        for( size_t i = 0; i < x.n_rows; ++i ){
            x.row(i) -= y.row(0);
        }
    } else if( x.n_rows == y.n_rows && y.n_cols == 1) {
        for( size_t i = 0; i < x.n_cols; ++i ){
            x.col(i) -= y.col(0);
        }
    } else {
        throw "Illegal size for broadcasting minus\n";
    }
    return x;
}

arma::mat div( arma::mat x, arma::mat y ) {
    if( x.n_cols == y.n_cols && y.n_rows == 1 ) {
        for( size_t i = 0; i < x.n_rows; ++i ){
            x.row(i) /= y.row(0);
        }
    } else if( x.n_rows == y.n_rows && y.n_cols == 1) {
        for( size_t i = 0; i < x.n_cols; ++i ){
            x.col(i) /= y.col(0);
        }
    } else {
        throw "Illegal size for broadcasting div\n";
    }
    return x;
}

arma::mat mul( arma::mat x, arma::mat y ) {
    if( x.n_cols == y.n_cols && y.n_rows == 1 ) {
        for( size_t i = 0; i < x.n_rows; ++i ){
            x.row(i) %= y.row(0);
        }
        return x;
    } else if( x.n_rows == y.n_rows && y.n_cols == 1) {
        for( size_t i = 0; i < x.n_cols; ++i ){
            x.col(i) %= y.col(0);
        }
        return x;
    } else if( x.n_cols == y.n_cols && x.n_rows == 1 ) {
        for( size_t i = 0; i < y.n_rows; ++i ){
            y.row(i) %= x.row(0);
        }
        return y;
    } else if( x.n_rows == y.n_rows && x.n_cols == 1) {
        for( size_t i = 0; i < y.n_cols; ++i ){
            y.col(i) %= x.col(0);
        }
        return y;
    } else {
        throw "Illegal size for broadcasting mul\n";
    }
    return x;
}

bool saveMat(std::ofstream& output, const arma::mat& m) {
    output.write((const char*)&m.n_rows,      sizeof(m.n_rows));
    output.write((const char*)&m.n_cols,      sizeof(m.n_cols));
    for(size_t i = 0; i < m.n_rows; ++i) {
        for(size_t j = 0; j < m.n_cols; ++j) {
            output.write((const char*)&m(i,j),      sizeof(m(i,j)));
        }
    }
    return true;
}

bool saveMat(std::ofstream& output, const arma::umat& m) {
    output.write((const char*)&m.n_rows,      sizeof(m.n_rows));
    output.write((const char*)&m.n_cols,      sizeof(m.n_cols));
    for(size_t i = 0; i < m.n_rows; ++i) {
        for(size_t j = 0; j < m.n_cols; ++j) {
            output.write((const char*)&m(i,j),      sizeof(m(i,j)));
        }
    }
    return true;
}
arma::mat loadMat(std::ifstream& input) {
    size_t rows, cols;
    input.read((char*)&rows,    sizeof(rows));
    input.read((char*)&cols,    sizeof(cols));

    arma::mat ret(rows, cols);
    for(size_t i = 0; i < ret.n_rows; ++i) {
        for(size_t j = 0; j < ret.n_cols; ++j) {
            input.read((char*)&ret(i,j),    sizeof(ret(i,j)));
        }
    }
    return ret;
}

arma::umat loadUMat(std::ifstream& input) {
    size_t rows, cols;
    input.read((char*)&rows,    sizeof(rows));
    input.read((char*)&cols,    sizeof(cols));

    arma::umat ret(rows, cols);
    for(size_t i = 0; i < ret.n_rows; ++i) {
        for(size_t j = 0; j < ret.n_cols; ++j) {
            input.read((char*)&ret(i,j),    sizeof(ret(i,j)));
        }
    }
    return ret;
}

bool saveStringUMap(std::ofstream& output, const UStringMatMap& m) {
    size_t s = m.size();
    output.write((const char*)&s, sizeof(s));
    for(auto& it : m) {
        size_t length = it.first.length();
        output.write((const char*)&length, sizeof(length));
        output.write((const char*)it.first.c_str(), length);
        saveMat(output, it.second);
    }
    return true;
}

bool saveVectorStringUMap(std::ofstream& output, const std::vector<UStringMatMap>& v) {
    size_t s = v.size();
    output.write((const char*)&s, sizeof(s));
    for(auto& obj : v) {
        saveStringUMap(output, obj);
    }
    return true;
}

bool loadStringUMap(std::ifstream& input, UStringMatMap& m) {
    size_t s;
    input.read((char*)&s,    sizeof(s));

    m.clear();
    for(size_t i = 0; i < s; ++i) {
        size_t length;
        char* str;
        input.read((char*)&length,    sizeof(length));
        str = new char[length + 1];
        input.read(str, length);
        str[length] = 0;
        m.emplace(str, loadMat(input));
        delete [] str;
    }
    return true;
}

bool loadVectorStringUMap(std::ifstream& input, std::vector<UStringMatMap>& v) {
    size_t s;
    input.read((char*)&s,    sizeof(s));

    v.clear();
    for(size_t i = 0; i < s; ++i) {
        UStringMatMap obj;
        loadStringUMap(input, obj);
        v.push_back(obj);
    }
    return true;
}

} // namespace Util

namespace arma {
#if ARMA_VERSION_MAJOR == 6
    arma::mat index_max(const arma::mat& A,int dim ) {
        // dim=0, return a row vector (of type urowvec or umat), with each column containing the index of the extremum value in the corresponding column of M
        // dim=1, return a column vector (of type uvec or umat), with each row containing the index of the extremum value in the corresponding row of M
        arma::mat p;
        arma::mat M = arma::max(A,dim);
        std::cerr << __FUNCTION__ << " M:" << size(M) << "\n";
        if( dim == 0 ) {
            p = arma::zeros(1, A.n_cols);
        
            for( size_t i=0; i < A.n_cols; ++i ) {
                arma::uvec result = arma::find( A.col(i)==M(0,i) );
                p(0,i) = result(0,0);
            }
        } else {
            p = arma::zeros(A.n_rows,1);

            for( size_t i=0; i < A.n_rows; ++i ) {
                arma::uvec result = arma::find( A.row(i)==M(i,0) );
                p(i,0) = result(0,0);
            }
        }
        return p;
    }
#endif // ARMA_VERSION_MAJOR == 6

    std::vector<arma::cube> randn(int a, int b, int c, int d) {
        return std::vector<arma::cube>(a, arma::randn(b, c, d));
    }

    std::vector<arma::cube> randu(int a, int b, int c, int d) {
        return std::vector<arma::cube>(a, arma::randu(b, c, d));
    }

} // namespace arma

std::string size(const std::vector<arma::cube>& c) {
    return std::to_string(c.size()) + "x" + std::to_string(c[0].n_rows)
            + "x" + std::to_string(c[0].n_cols) + "x" +
            std::to_string(c[0].n_slices);
}

std::ostream& operator<<(std::ostream& o, std::vector<arma::cube>& c4) {
    for(arma::cube& c : c4) {
        o << c << "\n";
    }
    return o;
}
