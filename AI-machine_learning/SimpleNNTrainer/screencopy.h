#ifndef SCREENCOPY_H
#define SCREENCOPY_H

#include <QWidget>
#include <armadillo>
#include <neural_network.h>
#include <map>

// Simple mapper from 0...
class TH_YMappper : public NeuralNetwork::YMappperIF {
public:
    double fromYtoYY(double y) override {
        return y;
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
    void trainLogisticRegression();
    void scanScreenshot();
    void scanScreenshot_lr();
    QRect getCanvasSize() { return mCanvasSize; }
    void capture();
    void extractTrainingSet();
    void updateTrainingSetStat();
    void deleteTrainingSet();
    void saveTrainingSet();

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
    arma::mat mTrainingsetNewCollection;
    arma::mat mResultset;
    arma::mat mResultsetNewCollection;
    TH_YMappper mThYMapper;
    std::vector<QRect> mPredictions;
    QRect mCanvasSize;
    std::map<int,int> mTrainingSetStat;
};

#endif // SCREENCOPY_H
