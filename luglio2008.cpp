#include <iostream>
#include <fstream>
#include "lib.hpp"
using namespace std;
int main(){
  int prova=conta();
  std::cout << "i numeri nel file sono " << prova << std::endl;
  int v[5];
  load_dispari(v,10);

  return 0;
}
