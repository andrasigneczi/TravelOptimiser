#include "png2arma.h"
#include <png2arma.h>
#include <iomanip>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <string>
#include <CostAndGradient.h>
//#include <stdio.h>

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
	std::map<int,std::string> rowFileNameMap;
	int rowNumber = 0;
	while (!file.eof() /*&& rowNumber < 20*/) {
	    file >> line;
	    line = trim( line );
	    if( line.length() == 0 ){
	        break;
	    }
	    std::string newFileName = std::string("../COC/") + line;
        pa.read_png_file( newFileName.c_str());
        arma::mat ts = pa.process_file(24,24, true);
        pa.close();
        if( ts.n_cols == 0 ) {
            //remove( newFileName.c_str());
            continue;
        }
        
        // Trace the data with the linked row number and the filename
        rowFileNameMap.emplace(rowNumber,line);
        arma::mat rowTrace{(double)rowNumber};
        ts = join_rows( ts, rowTrace );
        ++rowNumber;
        
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
    
    arma::mat dataSet = join_rows( trainingSet, trainingSetResult );
    std::cout << "Data set size (with row numnbers): " << size(dataSet);
    
    dataSet = shuffle(dataSet);
    
    arma::mat testSet;
    arma::mat testSetResult;
    std::map<double,int> levelPerItemCount;
    std::vector<std::string> trainingSetFileNames;
    std::vector<std::string> testSetFileNames;
    trainingSet.clear();
    trainingSetResult.clear();
    
    // We need to prepare a training set and a test set. The test set should contains at least 3 sample/TH
    for( size_t i = 0; i < dataSet.n_rows; ++i ) {
        auto it = levelPerItemCount.find( dataSet(i,dataSet.n_cols-1));
        // The first two image from every TH level will be inserted into the training set
        arma::mat y{dataSet(i,dataSet.n_cols-1)};
        arma::mat x = dataSet.row(i).cols(0,dataSet.n_cols-3);

        //if( y(0,0) == -1 )
        //    y(0,0) = CostAndGradient::NOT_FOUND;
        
        // separating the trace information
        int row = dataSet(i,dataSet.n_cols-2);
        //std::cout << rowFileNameMap[row] << " " << y(0,0) << "\n";

        if( it == levelPerItemCount.end()) {
            levelPerItemCount.emplace(y(0,0),1);
            if( testSet.n_rows == 0 ) {
                testSet = x;
                testSetResult = y;
            } else {
                testSet = join_cols( testSet, x);
                testSetResult = join_cols( testSetResult, y);
            }
            testSetFileNames.push_back( rowFileNameMap[row] );
        } else {
            ++it->second;
            // The first two image from every TH level will be inserted into the training set
            if( it->second < 30 /*|| y(0,0) == CostAndGradient::NOT_FOUND*/ ){
                testSet = join_cols( testSet, x);
                testSetResult = join_cols( testSetResult, y);
                testSetFileNames.push_back( rowFileNameMap[row] );
            } else {
                if( trainingSet.n_rows == 0 ) {
                    trainingSet = x;
                    trainingSetResult = y;
                } else {
                    trainingSet = join_cols( trainingSet, x);
                    trainingSetResult = join_cols( trainingSetResult, y);
                }
                trainingSetFileNames.push_back( rowFileNameMap[row]);
            }
        }
    }
    trainingSet.save("coc_trainingset.bin");
    trainingSetResult.save("coc_trainingset_result.bin");

    testSet.save("coc_testset.bin");
    testSetResult.save("coc_testset_result.bin");
    
    std::cout << "Training set size: " << size(trainingSet);
    std::cout << "Training set result size: " << size(trainingSetResult);
    std::cout << "Test set size: " << size(testSet);
    std::cout << "Test set result size: " << size(testSetResult);
    
    // saving the filenames
    std::ofstream  fileOut1("coc_trainingset_filelist.txt");
    std::for_each( trainingSetFileNames.begin(), trainingSetFileNames.end(), [&fileOut1](const std::string& v ){ fileOut1 << v << std::endl; });
    fileOut1.close();

    std::ofstream  fileOut2("coc_testset_filelist.txt");
    std::for_each( testSetFileNames.begin(), testSetFileNames.end(), [&fileOut2](const std::string& v ){ fileOut2 << v << std::endl; });
    fileOut2.close();
    
    //pa.write_png_file(argv[2]);
}

}// Png2Arma_ns