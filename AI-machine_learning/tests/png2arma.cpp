#include "png2arma.h"
#include <png2arma.h>
#include <iomanip>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include "datasetgenerator.h"

namespace Png2Arma_ns {

void runTests()
{
    DatasetGenerator dg( "coc_" );
    dg.generateDataset( "../COC/trainingset_filelist.txt", "../COC/", 24, 24, true, 
                                        60000, 700, "/TH/" );
}

}// Png2Arma_ns