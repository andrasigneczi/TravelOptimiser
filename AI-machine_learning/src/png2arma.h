#ifndef __PNG2ARMA_H__
#define __PNG2ARMA_H__

#include <armadillo>
#include <string>

#define PNG_DEBUG 3
#include <png.h>

class Png2Arma {
public:
    void read_png_file(const char* file_name);
    void write_png_file(const char* file_name);
    arma::mat process_file( size_t width, size_t height, bool gray);
    int getWidth() const { return mWidth; }
    int getHeight() const { return mHeight; }
    void close();
    
private:
    size_t mWidth, mHeight;
    png_byte mColorType;
    png_byte mBitDepth;
    png_structp mPngPtr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep * row_pointers;
    std::string mFileName;
};

#endif