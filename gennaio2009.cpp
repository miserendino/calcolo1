#include <iostream>
#include "lib.hpp"

int main(){
double prova[100];
load(prova,100);
quicksort2(prova,100);
std::cout << "Ecco il vettore ordinato in senso descrescente" << std::endl;
for(unsigned int i=0;i<100;++i){
  std::cout << prova[i] << std::endl;
}

quicksort1(prova,100);
std::cout << "Ecco il vettore ordinato in senso crescente" << std::endl;
for(unsigned int i=0;i<100;++i){
  std::cout << prova[i] << std::endl;
}

  return 0;
}
