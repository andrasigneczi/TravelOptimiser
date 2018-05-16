// TODO: 
//     : QSettings usage
//     : egy bekapcsolható funkció, ami klikkelésre az adott pozíciótól +- irányba fel-le automatikusan kigenerálja a kisképeket
//     : a trainingdatába.

#include "screencopy.h"
#include <QPainter>
#include <QMouseEvent>
#ifdef __LINUX__
#include <unistd.h>
#endif
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QtGui/QImage>
//#include <png2arma.h>
#include <QScreen>
#include <QApplication>
#include <QtCore/QSettings>
#include "logistic_regression.h"
#include "support_vector_machine.h"

const int small_image_width = 24;
const std::string training_sets_folder = "./training_sets/";
int copy_box_size = 80;
double minimize_rate = (double)small_image_width/(double)copy_box_size;
const std::string training_set_prefix = "TH11_plus_BG";
double training_set_y = 0.;
double lambda = 0.1;
int iteration = 1000;
int scanStepSize = 4;
arma::mat thetaSizes{(double)small_image_width*small_image_width, 10000, 2};

ScreenCopy::ScreenCopy(QWidget *parent) : QWidget(parent)
{
    move(100,0);
    resize(1200,780);
    setMouseTracking(true);
    mouseX = 0;
    mouseY = 0;
    mousePressed = false;
    mousePressedX = 0;
    mousePressedY = 0;
    mCanvasSize = QRect(0,0,0,0);
    mTrainingset.load(training_sets_folder + training_set_prefix + "_trainingset.bin");
    mResultset.load(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
}

void ScreenCopy::capture() {
    QScreen* screen = qApp->primaryScreen();
    QRect g = screen->geometry();
    if( mCanvasSize == QRect(0,0,0,0)) {
        mScreenshot = screen->grabWindow(0,g.x(),g.y(),g.width(),g.height());
    } else {
        mScreenshot = screen->grabWindow(0,mCanvasSize.x(),mCanvasSize.y(),mCanvasSize.width(),mCanvasSize.height());
    }
    mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate,Qt::SmoothTransformation)
                    .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
    mGrayMiniCopy.save("minicopy.png");
    mScreenshot.save("screenshot.png");
    updateTrainingSetStat();
}

void ScreenCopy::paintEvent(QPaintEvent* pe) {

    QPainter p(this);
    p.drawPixmap(0,0,mScreenshot);
    //p.setCompositionMode(QPainter::CompositionMode_SourceOver);
    p.fillRect(0,0,1500,100, QBrush(QColor("#444444")));
    p.setFont(QFont("times",18));
    p.setPen(QPen(QColor("#ff0000")));
    p.drawText(QRect(0,0,500,30), Qt::AlignLeft, (std::to_string(mouseX) + " " + std::to_string(mouseY)).c_str());
        //p.drawText(QRect(0,30,500,30), Qt::AlignLeft, (std::to_string(mousePressedX) + " " + std::to_string(mousePressedY)).c_str());
//    p.drawText(QRect(0,30,500,30), Qt::AlignLeft, QString("detected th numbers:") + " " + std::to_string(mPredictions.size()).c_str());

    int textpos = 0;
    for( auto it = mTrainingSetStat.begin(); it != mTrainingSetStat.end(); ++it ){
        if( it->first == training_set_y ){
            p.setFont(QFont("times",18,QFont::Bold));
            p.setPen(QPen(QColor("#ffff00")));
        } else {
            p.setFont(QFont("times",18, QFont::Normal));
            p.setPen(QPen(QColor("#ff0000")));
        }
        p.drawText(QRect(textpos,30,500,100), Qt::AlignLeft, y2String(it->first) +
                   "=>" + QString::number( it->second ));
        textpos += 250;
    }

    if( mTrainingSetStat.find(training_set_y) == mTrainingSetStat.end()){
        p.setFont(QFont("times",18,QFont::Bold));
        p.setPen(QPen(QColor("#ffff00")));
        p.drawText(QRect(textpos,30,500,100), Qt::AlignLeft, y2String( training_set_y ) +
                   "=>0");
        textpos += 250;
    }

    p.setPen(QPen(QColor("#ffffff"),1,Qt::SolidLine));
    for( size_t i = 0; i < mPredictions.size(); ++i ){
        if( mPredictions[i].y == training_set_y ){
            p.drawRect(mPredictions[i].rect);
            p.drawText(mPredictions[i].rect, Qt::AlignLeft, y2String( mPredictions[i].y ));
        }
    }

    p.setPen(QPen(QColor("#ff6600"),2,Qt::DotLine));
    p.drawRect(mouseX, mouseY, copy_box_size, copy_box_size);
    QWidget::paintEvent(pe);
}

void ScreenCopy::mouseMoveEvent(QMouseEvent*me) {
    mouseX = me->x();
    mouseY = me->y();
    // globalX, globalY
    repaint();
    QWidget::mouseMoveEvent(me);
}

void ScreenCopy::mousePressEvent(QMouseEvent*me) {
    mousePressed = true;
    mousePressedX = me->x();
    mousePressedY = me->y();
    if( me->modifiers() == Qt::ControlModifier){
        std::cout << "dbg\n" << std::flush;
        QPainter p1(&mScreenshot);
        p1.fillRect(mousePressedX, mousePressedY, copy_box_size, copy_box_size,QBrush(QColor("#000000")));
        QPainter p2(&mGrayMiniCopy);
        p2.fillRect(mousePressedX*minimize_rate, mousePressedY*minimize_rate, small_image_width, small_image_width,QBrush(QColor("#000000")));
        mGrayMiniCopy.save("mGrayMiniCopy.png");
    } else {
        saveSelectedRect();
    }
    repaint();
    QWidget::mousePressEvent(me);
    //sleep(1);

    // add rect connect to training set with the label
    // rerun the training

    //close();
}

void ScreenCopy::mouseReleaseEvent(QMouseEvent*me) {
    mousePressed = false;
    QWidget::mouseReleaseEvent(me);
}

void ScreenCopy::keyPressEvent(QKeyEvent*ke) {
    if( ke->key() == Qt::Key_Escape) {
        ke->accept();
        close();
        return;
    }
    else if( ke->key() >= Qt::Key_0 && ke->key() <= Qt::Key_9) {
        ke->accept();
        training_set_y = ke->key() - Qt::Key_0;
        if( ke->modifiers() == Qt::ControlModifier)
            training_set_y += 10;
        std::cout << "y=" << training_set_y << "\n" << std::flush;
        repaint();
        return;
    }
    else if( ke->key() == Qt::Key_Space) {
        ke->accept();
        mCanvasSize = geometry();
        std::cout << "Canvas size: " << mCanvasSize.x() << ";" << mCanvasSize.y() << ";" << mCanvasSize.width() << ";" << mCanvasSize.height()
                  << "\n" << std::flush;
        return;
    }
    else if( ke->key() == Qt::Key_Plus) {
        ++copy_box_size;
        minimize_rate = (double)small_image_width/(double)copy_box_size;
        std::cout << "New copy_box_size: " << copy_box_size << std::endl << std::flush;
        mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate,Qt::SmoothTransformation)
                        .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
        repaint();
        return;
    }
    else if( ke->key() == Qt::Key_Minus) {
        --copy_box_size;
        minimize_rate = (double)small_image_width/(double)copy_box_size;
        std::cout << "New copy_box_size: " << copy_box_size << std::endl << std::flush;
        mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate,Qt::SmoothTransformation)
                        .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
        repaint();
        return;
    }
    QWidget::keyPressEvent(ke);
}

void ScreenCopy::trainNeuralNetwork() {
    if( mTrainingset.n_cols == 0 )
        return;

    srand (time(NULL));

    NeuralNetwork nn(thetaSizes, mTrainingset, mResultset, lambda, mThYMapper);

    //std::cout << "dbg1\n";
    arma::mat initial_nn_params;
    srand (time(NULL));
    for( size_t i = 0; i <= thetaSizes.n_cols-2; ++i ) {
        // Randomly initialize the weights to small values
        arma::mat initial_Theta = nn.randInitializeWeights(thetaSizes(0,i), thetaSizes(0,i+1));

        // Unroll parameters
        //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
        if( i == 0 )
            initial_nn_params = arma::vectorise( initial_Theta );
        else
            initial_nn_params = join_cols( initial_nn_params, arma::vectorise( initial_Theta ));
    }
    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    //std::cout << "Cost: " << frv.mCost;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(mTrainingset,thetas);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == mResultset))*100. << "\n";

    thetaSizes.save( training_sets_folder + training_set_prefix + "_trained_theta_sizes.bin" );
    frv.m_NNPparams.save( training_sets_folder + training_set_prefix + "_trained_thetas.bin" );
}

void ScreenCopy::trainLogisticRegression() {
    if( mTrainingset.n_cols == 0 )
        return;

    double lambda = 1e-3;
    LogisticRegression lr(mTrainingset, mResultset, lambda, true, 3 );

    lr.trainOneVsAll(2,200,true);
    lr.saveThetaAndFeatureScaling("log_reg");
}

void ScreenCopy::scanScreenshot() {
    arma::mat thetaSizes;
    arma::mat theta;
    arma::mat X, y;

    thetaSizes.load( training_sets_folder + training_set_prefix + "_trained_theta_sizes.bin" );
    theta.load( training_sets_folder + training_set_prefix + "_trained_thetas.bin" );
    NeuralNetwork nn(thetaSizes, X, y, lambda, mThYMapper);
    std::vector<arma::mat> thetas {nn.extractThetas(theta)};

    mPredictions.clear();
    int bgcounter = 0;
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = nn.predict(img,thetas);
            if( pred(0,0) == 1.0 ){
                //std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
                mPredictions.push_back({1,QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
            } else if( pred(0,0) == 0.0 ){
                ++bgcounter;
            } else {
                std::cout << "What is this? " << pred(0,0) << "\n" << std::endl;
            }
        }
    }
    std::cout << "bgcounter: " << bgcounter << "\n" << std::flush;
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
    /*
    if( mPredictions.size() < 20 ) {
        for_each(mPredictions.begin(),mPredictions.end(),
          [&](const QRect& r) {std::cout << r.x() << ";" << r.y() << ";" << r.width() << ";" << r.height() << "\n" << std::flush; });
    }
    */
}

void ScreenCopy::scanScreenshot_lr() {
    arma::mat X, y;

    LogisticRegression lr;
    lr.setFeatureMappingDegree(3);
    lr.loadThetaAndFeatureScaling("log_reg");
    mPredictions.clear();
    int bgcounter = 0;
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = lr.predictOneVsAll(img,true);
            if( pred(0,0) == 0.0 ){
                ++bgcounter;
            } else  if(pred(0,1) > 0.5){
                //std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
                mPredictions.push_back({pred(0,0),QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
                std::cout << pred(0,1) << "\n" << std::flush;
            }
        }
    }
    std::cout << "bgcounter: " << bgcounter << "\n" << std::flush;
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
    /*
    if( mPredictions.size() < 20 ) {
        for_each(mPredictions.begin(),mPredictions.end(),
          [&](const QRect& r) {std::cout << r.x() << ";" << r.y() << ";" << r.width() << ";" << r.height() << "\n" << std::flush; });
    }
    */
}

void ScreenCopy::scanScreenshot_svm() {
    arma::mat X, y;

    struct svm_model *model = svm_load_model("svm_model.bin");
    support_vector_machine svm;
    svm.loadFeatureScaling("coc_");
    
    mPredictions.clear();
    int bgcounter = 0;
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = svm.predict(img,model);
            if( pred(0,0) == 0.0 ){
                ++bgcounter;
            } else  if(pred(0,1) > 0.5){
                //std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
                mPredictions.push_back({pred(0,0),QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
                std::cout << pred(0,1) << "\n" << std::flush;
            }
        }
    }
    std::cout << "bgcounter: " << bgcounter << "\n" << std::flush;
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
}

void ScreenCopy::saveSelectedRect() {

    int yp = mousePressedY *minimize_rate - scanStepSize;
    if( yp < 0 ) yp = 0;
    int xp = mousePressedX *minimize_rate - scanStepSize;
    if( xp < 0 ) xp = 0;

    for( int imgCountY = 0; imgCountY < 2* scanStepSize; ++imgCountY ) {
        for( int imgCountX = 0; imgCountX < 2* scanStepSize; ++imgCountX ) {
            arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp  + imgCountX + j, yp + imgCountY + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            //mGrayMiniCopy.copy(mousePressedX *minimize_rate, mousePressedY *minimize_rate, small_image_width, small_image_width)
            //                  .save("selectedrect.png");
            if( mTrainingsetNewCollection.n_cols == 0 )
                mTrainingsetNewCollection = img;
            else
                mTrainingsetNewCollection.insert_rows(mTrainingsetNewCollection.n_rows, img);
            mResultsetNewCollection.insert_rows(mResultsetNewCollection.n_rows, arma::mat{training_set_y}); // TODO: TH level
        }
    }

    //mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    //mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::saveTiles() {
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += small_image_width) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += small_image_width) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            if( mTrainingsetNewCollection.n_cols == 0 )
                mTrainingsetNewCollection = img;
            else
                mTrainingsetNewCollection.insert_rows(mTrainingsetNewCollection.n_rows, img);
            mResultsetNewCollection.insert_rows(mResultsetNewCollection.n_rows, arma::mat{training_set_y}); // TODO: TH level
        }
    }
    //mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    //mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::extractTrainingSet() {
    //std::cout <<  mTrainingset.n_rows << ";" << mTrainingset.n_cols << "\n" << std::flush;
    QImage img(small_image_width,small_image_width, QImage::Format_RGB32);
    char name[100];
    for( size_t i = 0; i < mTrainingset.n_rows; ++i ) {
        for( size_t j = 0; j < mTrainingset.n_cols; ++j ) {
            img.setPixel(j%small_image_width,j/small_image_width, mTrainingset(i, j));
        }
        sprintf(name, "tmp/%u_%04lu.png", (unsigned)mResultset(i,0), (unsigned long)i);
        img.save(name);
    }
}

void ScreenCopy::updateTrainingSetStat(){
    mTrainingSetStat.clear();
    for( size_t i = 0; i < mResultset.n_rows; ++i ){
        auto it = mTrainingSetStat.find(mResultset(i,0));
        if( it != mTrainingSetStat.end()) {
            ++it->second;
        } else {
            mTrainingSetStat.emplace((int)mResultset(i,0),1);
        }
    }
    for( size_t i = 0; i < mResultsetNewCollection.n_rows; ++i ){
        auto it = mTrainingSetStat.find(mResultsetNewCollection(i,0));
        if( it != mTrainingSetStat.end()) {
            ++it->second;
        } else {
            mTrainingSetStat.emplace((int)mResultsetNewCollection(i,0),1);
        }
    }
    repaint();
}

void ScreenCopy::deleteTrainingSet() {
    mTrainingset.clear();
    mTrainingsetNewCollection.clear();
    mResultset.clear();
    mResultsetNewCollection.clear();
    //mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    //mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    saveTrainingSet();
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::saveTrainingSet() {
    mTrainingset.insert_rows(mTrainingset.n_rows, mTrainingsetNewCollection);
    mTrainingsetNewCollection.clear();
    mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");

    mResultset.insert_rows(mResultset.n_rows, mResultsetNewCollection);
    mResultsetNewCollection.clear();
    mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
}

QString ScreenCopy::y2String(int y){
    switch(y){
    case 0:return "BG";
    case 1:return "TH11";
    case 2:return "TH8";
    case 3:return "TH9";
    case 4:return "TH7";
    case 5:return "TH10";
    default:return "????";
    }
    return "";
}
