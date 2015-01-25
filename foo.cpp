#include <iostream>
#include <utility>
#include "lib.hpp"

int main(){
  /*
  unsigned int number_of_data=90;
double v[number_of_data];
load(v,number_of_data);
for(unsigned int i=0;i<number_of_data;++i){
  std::cout << "Al posto " << i << " abbiamo " << v[i] << std::endl;
}

strangesort1(v,number_of_data);
strangesort2(v,number_of_data);
*/
double r[100];
double_randomgen(100,r,0.,100.);
double a[100];
double_randomgen(100,a,0.,100.);
std::cout << std::endl;
selectionsort1(a,100);
std::cout << "Ecco i numberi ordinati con il selection sort in ordine crescente" << std::endl;
std::cout << std::endl;
for(int i=0;i<100;++i){
  std::cout << a[i] << std::endl;
}
selectionsort2(a,100);
std::cout << "Ecco i numberi ordinati con il selection sort in ordine decrescente" << std::endl;
std::cout << std::endl;
for(int i=0;i<100;++i){
  std::cout << a[i] << std::endl;
}
  return 0;
}
