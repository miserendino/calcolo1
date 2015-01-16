#include <iostream>
#include <fstream>
using namespace std;
#ifndef __LIB_HPP__

//dichiarazione di tutte le funzioni

        template <typename TD>
    void bubblesort( unsigned int number_of_data, TD v);
        template <typename TD>
    void quicksort( unsigned int number_of_data, TD* v);
        template <typename TD>
    void scambia( TD*, TD*);
        template <typename TD>
    void loadR2(TD *,TD *,unsigned int);
        template <typename TD>
void load_dispari(TD *, unsigned int);
    unsigned int conta();

    template <typename TD>
  void scambia( TD* a,TD* b) 
  {
    TD temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//definizione di tutte le funzioni

//funzioni di ordinamento
template <typename TD>
void bubblesort(unsigned int number_of_data, TD* v) {
  for( int i=0; i<number_of_data-1; ++i ) {
    if ( v[i]>v[i+1] ) {
      for (int j=i+1; j>0; --j) {
	if (v[j]<v[j-1] )scambia(v[j],v[j-1]);
        else break;
      }
    }
  }
}

template <typename TD>
void quicksort( int number_of_data, TD* v) {
  int i=0, j;
  TD separator;
  if (number_of_data < 2) return;
  separator = v[number_of_data/2];  
  j=number_of_data-1;
  while (j>i) {
    while ( v[i]<separator ) i++;
    while ( v[j]>separator ) j--;
    if (i<j) {
      scambia( v[i], v[j] );
      i++;
    }
  } 
  quicksort(i,v);
  quicksort(number_of_data-i,v+i);
}

// funzione conta 

unsigned int conta(){
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre i numeri" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  double tmp;
  unsigned int number_of_data=0;
  input >> tmp;
  while(!input.eof()){
    ++number_of_data;
    input >> tmp;
  }
  return number_of_data;
input.close();       //ricordarsi di chiudere lo stream
}

//funzione carica solo elementi di posto dispari di un array monodimensionale

template <typename TD>
void load_dispari(TD * v, unsigned int number_of_data){     //number_of_data rappresenta tutti i valori dell'array!!!
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre i tuoi " << number_of_data/2 << " numeri" << std::endl;
  char namefile[30];
  cin >> namefile;
  TD tmp;
  input.open(namefile);
for(unsigned int i=0;i<number_of_data;++i){
  if(i%2!=0){
      input >> v[i];
      std::cout << v[i] << std::endl;
      }
  else {
    input >> tmp;
    }
  }
  input.close();
}

//funzione che carica coppie di dati (punto in R2)

template <typename TD>
void loadR2(TD* x,TD* y,unsigned int dim){          //dim indica la lunghezza o solo delle ascisse o solo delle coordinate!
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre le " << dim << " coppie di numeri" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  for(unsigned int e=0;e<dim;++e){
    input >> x[e] >> y[e];
#ifdef DEBUG 
    std::cout << x[e] << "  " << y[e] << std::endl;
#endif
  }
  input.close();
}
template <typename TD>
struct puntoR2
{
  TD* x,y;
};
#endif
