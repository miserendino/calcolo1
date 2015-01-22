#include <iostream> 
#include <random>
#include <fstream>
int main(){
    const int nrolls=10000;  // number of experiments

        std::default_random_engine generator;
          std::uniform_real_distribution<double> distribution(0.0,1.0);
          std::ofstream output;
          output.open("dati.dat");
              for (int i=0; i<nrolls; ++i) {
                    double number = distribution(generator);
                    output << number << "  ";
                    output << number <<  std::endl;
              }
  return 0;
}
