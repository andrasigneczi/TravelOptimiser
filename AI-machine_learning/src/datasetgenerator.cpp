#include "datasetgenerator.h"
#include "Util.h"
#include "png2arma.h"
#include <iomanip>
#include <map>
#include <fstream>
#include <iostream>

void DatasetGenerator::generateDataset( std::string fileListPath, std::string pathModifier, size_t width, size_t height, bool gray, size_t maxTrainingsetSize, 
                                size_t maxTestItemCountPerLabel, std::string folderPattern ) {
    reset();
    png2DataSet( fileListPath, pathModifier, folderPattern, width, height, gray );
    separateTrainingAndTestSet( maxTrainingsetSize, maxTestItemCountPerLabel );
    saveResult();
    //pa.write_png_file(argv[2]);
}

void DatasetGenerator::png2DataSet( std::string fileListPath, std::string pathModifier, std::string folderPattern, size_t width, size_t height, bool gray ) {
    Png2Arma pa;
	std::ifstream  file(fileListPath, std::ios::in);
	std::string line;
	int rowNumber = 0;
	while (!file.eof()) {
	    file >> line;
	    line = Util::trim( line );
	    if( line.length() == 0 ){
	        break;
	    }
	    std::string newFileName = pathModifier + line;
        pa.read_png_file( newFileName.c_str());
        arma::mat ts = pa.process_file(width,height,gray);
        pa.close();
        if( ts.n_cols == 0 ) {
            continue;
        }
        
        // Trace the data with the linked row number and the filename
        mRowFileNameMap.emplace(rowNumber,line);
        arma::mat rowTrace{(double)rowNumber};
        ts = join_rows( ts, rowTrace );
        ++rowNumber;
        
        // read the TH number
        size_t pos1 = newFileName.find( folderPattern );
        size_t pos2 = newFileName.find( "/", pos1 + 4 );
        double y = std::atoi(newFileName.substr(pos1 + 4, pos2 ).c_str());
        arma::mat Y{y};
        
        if( mDataSet.n_cols == 0 ) {
            mDataSet = join_rows( ts, Y );
        } else {
            mDataSet = join_cols( mDataSet, join_rows( ts, Y ));
        }
        line = "";
    }
    
    std::cout << "Data set size (with row numnbers): " << size(mDataSet);
}

void DatasetGenerator::separateTrainingAndTestSet( size_t maxTrainingsetSize, size_t maxTestItemCountPerLabel ) {
    mDataSet = shuffle(mDataSet);
    mDataSet = shuffle(mDataSet);

    std::map<double,size_t> levelPerItemCount;
    
    // We need to prepare a training set and a test set. The test set should contains at least 3 sample/TH
    for( size_t i = 0; i < mDataSet.n_rows; ++i ) {
        auto it = levelPerItemCount.find( mDataSet(i,mDataSet.n_cols-1));
        // The first two image from every TH level will be inserted into the training set
        arma::mat y{mDataSet(i,mDataSet.n_cols-1)};
        arma::mat x = mDataSet.row(i).cols(0,mDataSet.n_cols-3);

        // separating the trace information
        int row = mDataSet(i,mDataSet.n_cols-2);
        //std::cout << mRowFileNameMap[row] << " " << y(0,0) << "\n";

        if( it == levelPerItemCount.end()) {
            levelPerItemCount.emplace(y(0,0),1);
            if( mTestSet.n_rows == 0 ) {
                mTestSet = x;
                mTestSetResult = y;
            } else {
                mTestSet = join_cols( mTestSet, x);
                mTestSetResult = join_cols( mTestSetResult, y);
            }
            mTestSetFileNames.push_back( mRowFileNameMap[row] );
        } else {
            ++it->second;
            // The first two image from every TH level will be inserted into the training set
            if( it->second < maxTestItemCountPerLabel /*|| y(0,0) == CostAndGradient::NOT_FOUND*/ ){
                mTestSet = join_cols( mTestSet, x);
                mTestSetResult = join_cols( mTestSetResult, y);
                mTestSetFileNames.push_back( mRowFileNameMap[row] );
            } else {
                if( maxTrainingsetSize <= mTrainingSet.n_rows )
                    break;
                if( mTrainingSet.n_rows == 0 ) {
                    mTrainingSet = x;
                    mTrainingSetResult = y;
                } else {
                    mTrainingSet = join_cols( mTrainingSet, x);
                    mTrainingSetResult = join_cols( mTrainingSetResult, y);
                }
                mTrainingSetFileNames.push_back( mRowFileNameMap[row]);
            }
        }
    }
}

void DatasetGenerator::reset() {
    mDataSet.clear();
    mTestSet.clear();
    mTestSetResult.clear();
    mTrainingSet.clear();
    mTrainingSetResult.clear();
    mTrainingSetFileNames.clear();
    mTestSetFileNames.clear();
    mRowFileNameMap.clear();
}

void DatasetGenerator::saveResult() {
    mTrainingSet.save(mFilePrefix + "trainingset.bin");
    mTrainingSetResult.save(mFilePrefix + "trainingset_result.bin");

    mTestSet.save(mFilePrefix + "testset.bin");
    mTestSetResult.save(mFilePrefix + "testset_result.bin");
    
    std::cout << "Training set size: " << size(mTrainingSet);
    std::cout << "Training set result size: " << size(mTrainingSetResult);
    std::cout << "Test set size: " << size(mTestSet);
    std::cout << "Test set result size: " << size(mTestSetResult);
    
    // saving the filenames
    std::ofstream  fileOut1(mFilePrefix + "trainingset_filelist.txt");
    std::for_each( mTrainingSetFileNames.begin(), mTrainingSetFileNames.end(), [&fileOut1](const std::string& v ){ fileOut1 << v << std::endl; });
    fileOut1.close();

    std::ofstream  fileOut2(mFilePrefix + "testset_filelist.txt");
    std::for_each( mTestSetFileNames.begin(), mTestSetFileNames.end(), [&fileOut2](const std::string& v ){ fileOut2 << v << std::endl; });
    fileOut2.close();
}
