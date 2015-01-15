#include <iostream> 
#include <random>
#include <fstream>
int main(){
    const int nrolls=10000;  // number of experiments

        std::default_random_engine generator;
          std::geometric_distribution<int> distribution(0.3);

          std::ofstream output;
          output.open("prova");
              for (int i=0; i<nrolls; ++i) {
                    double number = distribution(generator);
                    output << number << "  ";
                    output << number <<  std::endl;
              }
  return 0;
}
