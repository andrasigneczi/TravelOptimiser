#ifndef __PNG2ARMA_H__
#define __PNG2ARMA_H__

#include <armadillo>

class Png2Arma {
public:
    void read_png_file(const char* file_name);
    void write_png_file(const char* file_name);
    void process_file(arma::mat& storage);
    void close();
};

#endif