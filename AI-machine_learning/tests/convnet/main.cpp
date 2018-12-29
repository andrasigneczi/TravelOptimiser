#include "convnet.h"
#include <iostream>

int main (int argc, char* argv[]) {
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    try {
        convLayerTest();
    } catch(const char* str) {
        std::cerr << str;
    }
    //std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
}
