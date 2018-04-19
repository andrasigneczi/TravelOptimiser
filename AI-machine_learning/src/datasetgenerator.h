#ifndef __DATASETGENERATOR_H__
#define __DATASETGENERATOR_H__

#include <string>
#include <vector>
#include <map>
#include <armadillo>


class DatasetGenerator {
public:
    DatasetGenerator( std::string filePrefix ) : mFilePrefix( filePrefix ){};
    void generateDataset( std::string fileListPath, std::string pathModifier, size_t width, size_t height, bool gray, size_t maxTrainingsetSize, 
                                size_t maxTestItemCountPerLabel, std::string folderPattern );
private:
    void png2DataSet( std::string fileListPath, std::string pathModifier, std::string folderPattern, size_t width, size_t height, bool gray );
    void separateTrainingAndTestSet( size_t maxTrainingsetSize, size_t maxTestItemCountPerLabel );
    void saveResult();
    void reset();
    
    arma::mat mDataSet;
    arma::mat mTestSet;
    arma::mat mTestSetResult;
    arma::mat mTrainingSet;
    arma::mat mTrainingSetResult;
    std::vector<std::string> mTrainingSetFileNames;
    std::vector<std::string> mTestSetFileNames;
    std::map<int,std::string> mRowFileNameMap;
    std::string mFilePrefix;
};

#endif // __DATASETGENERATOR_H__