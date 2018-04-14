#include "png2arma.h"
#include <png2arma.h>

namespace Png2Arma_ns {

void runTests(const char* fileName)
{
        Png2Arma pa;
        pa.read_png_file(fileName);
        arma::mat trainingSet(1,24*3);
        pa.process_file(trainingSet);
        pa.close();
        trainingSet.shed_row(0);
        trainingSet.save("coc_training_set.bin");
        std::cout << "Training set size: " << size(trainingSet);
        //pa.write_png_file(argv[2]);
}

}// Png2Arma_ns