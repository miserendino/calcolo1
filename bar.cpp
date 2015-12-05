#include <iostream>
#include "lib.hpp"
#include<cmath>
#include<fstream>

 
int main(){
double x[200],y[200];
  loadR2(x,y,200);
bubblesortx2dimcr(x,y,200);
std::cout << "Ecco le coppie ordinate in ordine crecente rispetto alle x" << std::endl;
for(int i=0;i<200;++i){
  std::cout << x[i] << " " << y[i] << std::endl;
}
bubblesortx2dimdcr(x,y,200);
std::cout << "Ecco le coppie ordinate in ordine decrecente rispetto alle x" << std::endl;
for(int i=0;i<200;++i){
  std::cout << x[i] << " " << y[i] << std::endl;
}
#if 0
bubblesorty2dimdcr(x,y,200);
std::cout << "Ecco le coppie ordinate in ordine decrecente rispetto alle y" << std::endl;
for(int i=0;i<200;++i){
  std::cout << x[i] << " " << y[i] << std::endl;
}
bubblesorty2dimcr(x,y,200);
std::cout << "Ecco le coppie ordinate in ordine crecente rispetto alle y" << std::endl;
for(int i=0;i<200;++i){
  std::cout << x[i] << " " << y[i] << std::endl;
}
#endif
return 0;
}
