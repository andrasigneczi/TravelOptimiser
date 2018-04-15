#include "png2arma.h"
#include <png2arma.h>
#include <iomanip>
#include <set>
#include <fstream>
#include <iostream>
#include <string>

namespace Png2Arma_ns {

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void runTests()
{
    arma::mat trainingSet;
    arma::mat trainingSetResult(1,1);
    Png2Arma pa;
	std::ifstream  file("../COC/trainingset_filelist.txt", std::ios::in);
	std::string line;
	while (!file.eof()) {
	    file >> line;
	    line = trim( line );
	    if( line.length() == 0 ){
	        break;
	    }
	    std::string newFileName = std::string("../COC/") + line;
        pa.read_png_file( newFileName.c_str());
        arma::mat ts = pa.process_file(24,24, true);
        pa.close();
        if( ts.n_cols == 0 )
            continue;
        
        // read the TH number
        size_t pos1 = newFileName.find( "/TH/" );
        size_t pos2 = newFileName.find( "/", pos1 + 4 );
        double y = std::atoi(newFileName.substr(pos1 + 4, pos2 ).c_str());
        
        if( trainingSet.n_cols == 0 ) {
            trainingSet = ts;
            trainingSetResult(0,0) = y;
        } else {
            trainingSet = join_cols( trainingSet, ts );
            trainingSetResult = join_cols( trainingSetResult, arma::mat {y});
        }
        line = "";
    }
    trainingSet.save("coc_trainingset.bin");
    trainingSetResult.save("coc_trainingset_result.bin");
    std::cout << "Training set size: " << size(trainingSet);
    std::cout << "Training set result size: " << size(trainingSetResult);
    //pa.write_png_file(argv[2]);
}

}// Png2Arma_ns