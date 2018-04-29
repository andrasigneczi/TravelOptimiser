#ifndef SCREENCOPY_H
#define SCREENCOPY_H

#include <QWidget>
#include <armadillo>
#include <neural_network.h>
#include <map>

// Simple mapper from 0...
class TH_YMappper : public CostAndGradient::YMappperIF {
public:
    arma::mat fromYtoYY(double y, size_t num_labels ) override {
        arma::mat yy = arma::zeros(1,num_labels);
        yy(0,y) = 1;
        return yy;
    }

    double fromYYtoY( size_t index ) override {
        return index;
    }
};

class ScreenCopy : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenCopy(QWidget *parent = 0);

    void paintEvent(QPaintEvent* pe) override;
    void mouseMoveEvent(QMouseEvent*me) override;
    void mousePressEvent(QMouseEvent*me) override;
    void mouseReleaseEvent(QMouseEvent*me) override;
    void keyPressEvent(QKeyEvent*ke) override;
    void saveTiles();
    void trainNeuralNetwork();
    void scanScreenshot();
    QRect getCanvasSize() { return mCanvasSize; }
    void capture();
    void extractTrainingSet();
    void updateTrainingSetStat();
    void deleteTrainingSet();

signals:

public slots:

private:
    void saveSelectedRect();

    QPixmap mScreenshot;
    QImage mGrayMiniCopy;
    int mouseX;
    int mouseY;
    bool mousePressed;
    int mousePressedX;
    int mousePressedY;

    arma::mat mTrainingset;
    arma::mat mResultset;
    TH_YMappper mThYMapper;
    std::vector<QRect> mPredictions;
    QRect mCanvasSize;
    std::map<int,int> mTrainingSetStat;
};

#endif // SCREENCOPY_H
