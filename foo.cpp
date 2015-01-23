#include <iostream>
#include <utility>
#include "lib.hpp"
#define NN 10

int main(){
double v[NN];
load(v,NN);
for(int i=0;i<NN;++i){
  std::cout << "Al posto " << i << " abbiamo " << v[i] << std::endl;
}
unsigned int Odd,Even;
if(NN%2==0){
  Odd=NN/2;
  Even=NN/2+1;
}
else {
  Odd=NN/2;
  Even=NN/2;
}
unsigned int l=0,j=0;
double odd[Odd],even[Even];
std::cout << "I valori di Odd e Even sono " << std::endl;
std::cout << Odd << " " << Even << std::endl;
for(int i=0;i<NN;++i){
 while(i%2==0){
   std::cout << "Il numero corrispondente a un posto pari è " << v[i] <<  std::endl;
   even[j]=v[i];
   ++j;
   break;
     }        
 while(i%2!=0)
   {
   std::cout << "Il numero corrispondente a un posto dispari è " << v[i] <<  std::endl;
     odd[l]=v[i];
     ++l;
     break;
    } 
 }


quicksort1(even,Even);
quicksort1(odd,Odd);
#if 0
for(int i=0;i<NN/2;++i){
  std::cout << even[i] << " " << odd[i]  << std::endl;
}
#endif
  return 0;
}
