#include "screencopy.h"
#include <QPainter>
#include <QMouseEvent>
#include <unistd.h>
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QtGui/QImage>
#include <png2arma.h>
#include <QScreen>
#include <QApplication>

const int small_image_width = 30;
const std::string training_sets_folder = "./training_sets/";
const int copy_box_size = 100;
const double minimize_rate = (double)small_image_width/(double)copy_box_size;
const std::string training_set_prefix = "TH1_bg";
double training_set_y = 0.;

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
    mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate)
                    .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
    mGrayMiniCopy.save("minicopy.png");
    mScreenshot.save("screenshot.png");
    repaint();
}

void ScreenCopy::paintEvent(QPaintEvent* pe) {

    QPainter p(this);
    p.drawPixmap(0,0,mScreenshot);
/*
    p.fillRect(0,0,500,60, QBrush(QColor("#444444")));
    p.setFont(QFont("times",22));
    p.setPen(QPen(QColor("#ff0000")));
    p.drawText(QRect(0,0,500,30), Qt::AlignLeft, (std::to_string(mouseX) + " " + std::to_string(mouseY)).c_str());
        //p.drawText(QRect(0,30,500,30), Qt::AlignLeft, (std::to_string(mousePressedX) + " " + std::to_string(mousePressedY)).c_str());
    p.drawText(QRect(0,30,500,30), Qt::AlignLeft, QString("detected th numbers:") + " " + std::to_string(mPredictions.size()).c_str());
*/
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
        return;
    }
    else if( ke->key() == Qt::Key_Space) {
        ke->accept();
        mCanvasSize = geometry();
        std::cout << "Canvas size: " << mCanvasSize.x() << ";" << mCanvasSize.y() << ";" << mCanvasSize.width() << ";" << mCanvasSize.height()
                  << "\n" << std::flush;
        return;
    }
    QWidget::keyPressEvent(ke);
}

void ScreenCopy::trainNeuralNetwork() {
    if( mTrainingset.n_cols == 0 )
        return;

    double lambda = 0.1;
    int iteration = 100;
    srand (time(NULL));

    arma::mat thetaSizes{(double)mTrainingset.n_cols, 2000, 100, 2};
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
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == mResultset))*100. << "\n";

    thetaSizes.save( training_sets_folder + training_set_prefix + "_trained_theta_sizes.bin" );
    frv.m_NNPparams.save( training_sets_folder + training_set_prefix + "_trained_thetas.bin" );
}

void ScreenCopy::scanScreenshot() {
    arma::mat thetaSizes;
    arma::mat theta;
    arma::mat X, y;
    double lambda = 0;

    thetaSizes.load( training_sets_folder + training_set_prefix + "_trained_theta_sizes.bin" );
    theta.load( training_sets_folder + training_set_prefix + "_trained_thetas.bin" );
    NeuralNetwork nn(thetaSizes, X, y, lambda, mThYMapper);
    std::vector<arma::mat> thetas {nn.extractThetas(theta)};

    mPredictions.clear();

    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += 1) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += 1) {

            for( size_t i = 0; i < small_image_width; ++i ) {
                for( size_t j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = nn.predict(img,thetas);
            if( pred(0,0) == 1.0 ){
                //std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
                mPredictions.push_back(QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size));
            }
        }
    }
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
    if( mPredictions.size() < 20 ) {
        for_each(mPredictions.begin(),mPredictions.end(),
          [&](const QRect& r) {std::cout << r.x() << ";" << r.y() << ";" << r.width() << ";" << r.height() << "\n" << std::flush; });
    }
}

void ScreenCopy::saveSelectedRect() {
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );

    for( size_t i = 0; i < small_image_width; ++i ) {
        for( size_t j = 0; j < small_image_width; ++j ) {
            QRgb rgb = mGrayMiniCopy.pixel( mousePressedX *minimize_rate  + j, mousePressedY *minimize_rate+ i );
            img(0, i * small_image_width + j ) = rgb;
        }
    }
    mGrayMiniCopy.copy(mousePressedX *minimize_rate, mousePressedY *minimize_rate, small_image_width, small_image_width)
                      .save("selectedrect.png");

    if( mTrainingset.n_cols == 0 )
        mTrainingset = img;
    else
        mTrainingset.insert_rows(mTrainingset.n_rows, img);
    mResultset.insert_rows(mResultset.n_rows, arma::mat{training_set_y}); // TODO: TH level
    mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
}

void ScreenCopy::saveTiles() {
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += small_image_width) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += small_image_width) {

            for( size_t i = 0; i < small_image_width; ++i ) {
                for( size_t j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            if( mTrainingset.n_cols == 0 )
                mTrainingset = img;
            else
                mTrainingset.insert_rows(mTrainingset.n_rows, img);
            mResultset.insert_rows(mResultset.n_rows, arma::mat{training_set_y}); // TODO: TH level
        }
    }
    mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
}
