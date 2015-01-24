#include <iostream>
#include <utility>
#include "lib.hpp"

int main(){
  unsigned int number_of_data=90;
double v[number_of_data];
load(v,number_of_data);
for(unsigned int i=0;i<number_of_data;++i){
  std::cout << "Al posto " << i << " abbiamo " << v[i] << std::endl;
}

strangesort1(v,number_of_data);
strangesort2(v,number_of_data);
  return 0;
}
