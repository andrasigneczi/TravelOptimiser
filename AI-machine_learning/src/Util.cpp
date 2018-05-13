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

void prepareTrainingAndValidationSet(const arma::mat& X, const arma::mat& y, arma::mat& Xtraining, arma::mat& Ytraining, arma::mat& Xval, arma::mat& Yval) {
    arma::mat dataset = join_rows( X, y );
    shuffle(dataset);
    Util::removeDuplication(dataset);

    // 70% of every single label will be taken into the training set,
    // the others will be put into the validation set
    std::map<const double,size_t> dataSetStat;
    for( size_t i = 0; i < dataset.n_rows; ++i ){
        auto it = dataSetStat.find(y(i,0));
        if( it != dataSetStat.end()) {
            ++it->second;
        } else {
            dataSetStat.emplace((int)y(i,0),1);
        }
    }

    size_t row_num = 0;
    std::for_each(dataSetStat.begin(),dataSetStat.end(),[&row_num](std::pair<const double,size_t>&x){ x.second *= .7; row_num += x.second; });
    Xtraining = arma::mat(row_num, X.n_cols);
    Ytraining = arma::mat(row_num, 1);
    Xval = arma::mat(dataset.n_rows - row_num, X.n_cols);
    Yval = arma::mat(dataset.n_rows - row_num, 1);

    for( size_t i = 0, curr_row_t = 0, curr_row_v = 0; i < dataset.n_rows; ++i ) {
        std::cout << "row: " << i << "\r" << std::flush;
        double yv = dataset(i,dataset.n_cols - 1);
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

} // namespace Util
