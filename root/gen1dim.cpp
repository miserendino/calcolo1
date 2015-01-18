#include <iostream> 
#include <random>
#include <fstream>
int main(){
    const int nrolls=100;  // number of experiments

        std::default_random_engine generator;
          std::gamma_distribution<double> distribution(2.0,2.0);


          std::ofstream output;
          output.open("prova");
              for (int i=0; i<nrolls; ++i) {
                    double number = distribution(generator);
                    output << number <<  std::endl;
              }
  return 0;
}
