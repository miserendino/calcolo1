#include <iostream>
#include "lib.hpp"
#include <fstream>
#define NN 100
int main(){

          std::ofstream output;
          output.open("dati.dat");
          for(int i=0;i<NN;++i){
            output << i << std::endl;
          }
  return 0;
}
