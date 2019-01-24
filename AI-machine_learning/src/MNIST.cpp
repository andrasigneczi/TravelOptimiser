#include "MNIST.h"
#include <ios>
#include "Util.h"

Mnist::Mnist(std::string folderName)
: mTrainingImgFileName(folderName   + "/train-images-idx3-ubyte")
, mTrainingLabelFileName(folderName + "/train-labels-idx1-ubyte")
, mTestImgFileName(folderName       + "/t10k-images-idx3-ubyte")
, mTestLabelFileName(folderName     + "/t10k-labels-idx1-ubyte")
{
    
}

// c9.io is Little Endian
//
// lscpu | grep "Byte Order"
// $ Byte Order:            Little Endian
uint32_t Mnist::readBigEndian(std::ifstream& stream) {
    uint32_t retv;
    char* p = (char*)&retv;
    
    int num = 1;
    if(*(char *)&num == 1) {
        // Little-Endian
        for(int i = 3; i >= 0; --i)
            stream.read(p + i, 1);
    } else {
        // Big-Endian
    for(int i = 0; i <= 3; ++i)
        stream.read(p + i, 1);
    }
    return retv;
}

void Mnist::load(Mnist::Type type, size_t num) {
    std::ifstream image;
    std::ifstream label;

    uint32_t msb;
    uint32_t numberOfLabels;
    uint32_t numberOfImages;
    uint32_t rows, cols;


    arma::mat4D* X;
    arma::mat*   Y;

    std::cout << mTrainingImgFileName << "\n";
    std::cout << mTrainingLabelFileName << "\n";
    std::cout << mTestImgFileName << "\n";
    std::cout << mTestLabelFileName << "\n";
    if(type == TRAINING) {
        image.open(mTrainingImgFileName.c_str(), std::ios::in | std::ios::binary); // Binary image file
        label.open(mTrainingLabelFileName.c_str(), std::ios::in | std::ios::binary ); // Binary label file
        X = &mX;
        Y = &mY;
    } else {
        image.open(mTestImgFileName.c_str(), std::ios::in | std::ios::binary); // Binary image file
        label.open(mTestLabelFileName.c_str(), std::ios::in | std::ios::binary ); // Binary label file
        X = &mXtest;
        Y = &mYtest;
    }

    // reading headers
    if(image.is_open()) {
        std::cout << "image is open\n";
    }
    msb = readBigEndian(label);
    UNUSED(msb);
    numberOfLabels = readBigEndian(label);
    msb = readBigEndian(image);
    numberOfImages = readBigEndian(image);
    rows = readBigEndian(image);
    cols = readBigEndian(image);

    numberOfImages = numberOfImages < num ? numberOfImages : num;
    numberOfLabels = numberOfLabels < num ? numberOfLabels : num;

    std::cout  << "rows: " << rows << std::endl;
    std::cout  << "cols: " << cols << std::endl;
    std::cout  << "number of labels: " << numberOfLabels << std::endl;
    std::cout  << "number of images: " << numberOfImages << std::endl;
    
    *X = arma::mat4D(numberOfImages, arma::zeros(rows, cols, 1));
    *Y = arma::zeros(1, numberOfLabels);

    // Reading label
    char number;
    for (uint32_t q = 0; q < numberOfLabels; ++q) {
        label.read(&number, sizeof(unsigned char));
        (*Y)(0, q) = (unsigned char)number;
    }

	// Reading image
    for (uint32_t q = 0; q < numberOfImages; ++q) {
        for (uint32_t j = 0; j < rows; ++j) {
            for (uint32_t i = 0; i < cols; ++i) {
                image.read(&number, sizeof(unsigned char));
    			(*X)[q](i, j, 0) = (unsigned char)number; 
            }
    	}
    }
    
	std::cout << "Image:" << std::endl;
    for (uint32_t j = 0; j < rows; ++j) {
        for (uint32_t i = 0; i < cols; ++i) {
            std::cout.width(3);
            if((*X)[0](i, j, 0) == 0) {
                std::cout << " ";
            } else {
                std::cout << (*X)[0](i, j, 0);
            }
        }
        std::cout << std::endl;
    }

}

void Mnist::getTrainingData(arma::mat4D& X, arma::mat& Y) {
    X = mX;
    Y = mY;
}

void Mnist::getTestData(arma::mat4D& X, arma::mat& Y) {
    X = mXtest;
    Y = mYtest;
}

void Mnist::getTrainingData(arma::mat& X, arma::mat& Y) {
    //X = arma::mat(mX[0].n_rows * mX[0].n_cols, mX.size());
    X = arma::mat();

    for(size_t i = 0; i < mX.size(); ++i) {
        X = arma::join_rows(X, arma::vectorise(mX[i].slice(0)));
    }
    Y = mY;
}

void Mnist::getTestData(arma::mat& X, arma::mat& Y) {
    X = arma::mat();

    for(size_t i = 0; i < mX.size(); ++i) {
        X = arma::join_rows(X, arma::vectorise(mXtest[i].slice(0)));
    }
    Y = mYtest;
}

void Mnist::begin(int batchSize) {
    
}

void Mnist::isEnd() {
    
}

void Mnist::next(arma::mat4D& X, arma::mat& Y) {
    
}

void Mnist::printTestImage(int index) {
    for (uint32_t j = 0; j < mXtest[0].n_rows; ++j) {
        for (uint32_t i = 0; i < mXtest[0].n_cols; ++i) {
            std::cout.width(3);
            if(mXtest[index](i, j, 0) == 0) {
                std::cout << " ";
            } else {
                std::cout << mXtest[index](i, j, 0);
            }
        }
        std::cout << std::endl;
    }
}
