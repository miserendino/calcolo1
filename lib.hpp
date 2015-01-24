#include <iostream>
#include <fstream>                          // ATTENZIONE abilitare il supporto allo standard 11 nel makefile
#include <utility>
using namespace std;
#ifndef __LIB_HPP__

//dichiarazione di tutte le funzioni

        template <typename TD>                                      /* TD sta per type of data */
    void bubblesort(TD*, unsigned int );
        template <typename TD>
    void quicksort1(TD*, unsigned int );
        template <typename TD>
    void quicksort2(TD*, unsigned int );
        template <typename TD>
    void scambia( TD*, TD*);
        template <typename TD>
    void strangesort(TD*, unsigned int);
        template <typename TD>
    void bubblesortx2dimdcr(TD* x,TD* y, unsigned int);
        template <typename TD>
    void bubblesortx2dimcr(TD* x,TD* y, unsigned int);
        template <typename TD>
    void bubblesorty2dimcr(TD* x,TD* y, unsigned int);
        template <typename TD>
    void bubblesorty2dimdcr(TD* x,TD* y, unsigned int);
        template <typename TD>
    void loadR2(TD *,TD *,unsigned int);
        template <typename TD>
    void load_dispari(TD *, unsigned int);
    unsigned int conta();
        template <typename TD>
    void loadxerr(TD *,TD*, TD*,unsigned int);
        template <typename TD>
    void loadyerr(TD *,TD*, TD*,unsigned int);
        template <typename TD>
    void load(TD*,unsigned int );
        template <typename TD>
    void oddevensort(TD *, int );
        template <typename TD>
  void scambia( TD* a,TD* b) 
  {
    TD temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

// dichiarazione della struttura punto-bidimensionale

template <typename TD>
struct puntoR2
{
  TD* x,y;
};

//definizione di tutte le funzioni

//funzioni di ordinamento
template <typename TD>
void bubblesort(TD* v, unsigned int number_of_data) {
  for( int i=0; i<number_of_data-1; ++i ) {   
    if ( v[i]>v[i+1] ) {                         // in tutte queste funzioni bubblesort abbiamo nel ciclo for
      for (int j=i+1; j>0; --j) {                // number_of_data-1 perchè con l'if raggiungiamo l'i+1esimo vettore
	if (v[j]<v[j-1] )swap(v[j],v[j-1]);
        else break;
      }
    }
  }
}

// funzione bubblesort per ordinate in modo crescente punti in R2 rispetto all'ascissa

template <typename TD>
void bubblesortx2dimcr(TD* x,TD* y, unsigned int number_of_data) {
  for( int i=0; i<number_of_data-1; ++i ) {
    if ( x[i]>x[i+1] ) {
      for (int j=i+1; j>0; --j) {
	if (x[j]<x[j-1] ){
    swap(x[j],x[j-1]);
    swap(y[j],y[j-1]);
  }
    else break;
      }
    }
  }
}

// funzione che scambia tutti gli elementi di posto dispari con i rispettivi elementi di posto pari

template <typename TD>
void oddevensort(TD a[], int number_of_data)
{
   for (int i = 0; i < number_of_data; ++i)
    {
      if (i & 1)
        {
      for (int j = 2; j < number_of_data; j+=2)
         if (a[j] < a[j-1])
         swap(a[j-1], a[j]);
      else
      for (int j = 1; j < number_of_data; j+=2)
         if (a[j] > a[j-1])
         swap(a[j-1], a[j]);
        }
    }
}

// funzione che dato un vettore unidimensionale, ordina in ordine decrescente tutti gli elementi di posto pari e in ordine crescente tutti gli elementi di posto dispari

template<typename TD>
void strangesort1(TD v[],unsigned int number_of_data){
unsigned int Odd,Even;
  if(number_of_data%2==0){            
    Odd=number_of_data/2;             // capisco quanti sono gli elementi pari e dispari
    Even=number_of_data/2;
  }
  else {
   Odd=number_of_data/2;
   Even=number_of_data/2+1;
  }
unsigned int l=0,j=0,w=0,q=0;
TD odd[Odd],even[Even];
#ifdef DEBUG
std::cout << "Il valore di Odd è " << Odd << " , il valore di Even è " << Even << std::endl;
#endif
for(unsigned int i=0;i<number_of_data;++i){
 while(i%2==0){
#ifdef DEBUG
   std::cout << "Il numero corrispondente a un posto pari è " << v[i] <<  std::endl;
#endif
   even[j]=v[i];
   ++j;
   break;
     }        
 while(i%2!=0)
   {
#ifdef DEBUG
   std::cout << "Il numero corrispondente a un posto dispari è " << v[i] <<  std::endl;
#endif
   odd[l]=v[i];
     ++l;
     break;
    } 
 }

quicksort2(even,Even);   //ordino in ordine crescente gli elementi pari
quicksort1(odd,Odd);     //ordino in ordine decrescente gli elementi dispari
#ifdef DEBUF
std::cout << "Ecco i numeri pari" << std::endl;
for(unsigned int i=0;i<Even;++i){
  std::cout << even[i] << std::endl;
}
std::cout << "Ecco i numeri dispari" << std::endl;
for(unsigned int i=0;i<Odd;++i){
  std::cout << odd[i] << std::endl;
}
#endif
for(unsigned int i=0;i<number_of_data;++i){
 while(i%2==0){
  v[i]=even[w];           //riassegno i nuovi elementi riordinati al loro posto
   ++w;
   break;
     }        
 while(i%2!=0)
   {
     v[i]=odd[q];
     ++q;
     break;
      } 
    }

std::cout << endl;
std::cout << "Ecco ordinati in ordine crescente tutti gli elementi di posto dispari e in ordine decrescente tutti gli elementi di posto pari" << std::endl;
std::cout << std::endl;

for(unsigned int i=0;i<number_of_data;++i){
  std::cout << "Al posto " << i << " abbiamo " << v[i] << std::endl;
  }
}

// funzione che dato un vettore unidimensionale, ordina in ordine crescente tutti gli elementi di posto pari e in ordine decrescente tutti gli elementi di posto dispari

template<typename TD>
void strangesort2(TD v[],unsigned int number_of_data){
unsigned int Odd,Even;
  if(number_of_data%2==0){            
    Odd=number_of_data/2;             // capisco quanti sono gli elementi pari e dispari
    Even=number_of_data/2;
  }
  else {
   Odd=number_of_data/2;
   Even=number_of_data/2+1;
  }
unsigned int l=0,j=0,w=0,q=0;
TD odd[Odd],even[Even];
#ifdef DEBUG
std::cout << "Il valore di Odd è " << Odd << " , il valore di Even è " << Even << std::endl;
#endif
for(unsigned int i=0;i<number_of_data;++i){
 while(i%2==0){
#ifdef DEBUG
   std::cout << "Il numero corrispondente a un posto pari è " << v[i] <<  std::endl;
#endif
   even[j]=v[i];
   ++j;
   break;
     }        
 while(i%2!=0)
   {
#ifdef DEBUG
   std::cout << "Il numero corrispondente a un posto dispari è " << v[i] <<  std::endl;
#endif
   odd[l]=v[i];
     ++l;
     break;
    } 
 }

quicksort1(even,Even);   //ordino in ordine crescente gli elementi pari
quicksort2(odd,Odd);     //ordino in ordine decrescente gli elementi dispari
#ifdef DEBUF
std::cout << "Ecco i numeri pari" << std::endl;
for(unsigned int i=0;i<Even;++i){
  std::cout << even[i] << std::endl;
}
std::cout << "Ecco i numeri dispari" << std::endl;
for(unsigned int i=0;i<Odd;++i){
  std::cout << odd[i] << std::endl;
}
#endif
for(unsigned int i=0;i<number_of_data;++i){
 while(i%2==0){
  v[i]=even[w];           //riassegno i nuovi elementi riordinati al loro posto
   ++w;
   break;
     }        
 while(i%2!=0)
   {
     v[i]=odd[q];
     ++q;
     break;
      } 
    }

std::cout << endl;
std::cout << "Ecco ordinati in ordine crescente tutti gli elementi di posto pari e in ordine decrescente tutti gli elementi di posto dispari" << std::endl;
std::cout << std::endl;

for(unsigned int i=0;i<number_of_data;++i){
  std::cout << "Al posto " << i << " abbiamo " << v[i] << std::endl;
  }
}

// funzione bubblesort per ordinate in modo crescente punti in R2 rispetto all'ordinata

template <typename TD>
void bubblesorty2dimcr(TD* x,TD* y, unsigned int number_of_data) {
  for( int i=0; i<number_of_data-1; ++i ) {
    if ( y[i]>y[i+1] ) {
      for (int j=i+1; j>0; --j) {
	if (y[j]<y[j-1] ){
    swap(x[j],x[j-1]);
    swap(y[j],y[j-1]);
  }
    else break;
      }
    }
  }
}

// funzione bubblesort per ordinate in modo decrescente punti in R2 rispetto all'ascissa

template <typename TD>
void bubblesortx2dimdcr(TD* x,TD* y, unsigned int number_of_data) {
  for( int i=0; i<number_of_data-1; ++i ) {
    if ( x[i]<x[i+1] ) {
      for (int j=i+1; j>0; --j) {
	if (x[j]>x[j-1] ){
    swap(x[j],x[j-1]);
    swap(y[j],y[j-1]);
  }
    else break;
      }
    }
  }
}


// funzione bubblesort per ordinate in modo decrescente punti in R2 rispetto all'ordinata

template <typename TD>
void bubblesorty2dimdcr(TD* x,TD* y, unsigned int number_of_data) {
  for( int i=0; i<number_of_data-1; ++i ) {
    if ( y[i]<y[i+1] ) {
      for (int j=i+1; j>0; --j) {
	if (y[j]>y[j-1] ){
    swap(x[j],x[j-1]);
    swap(y[j],y[j-1]);
  }
    else break;
      }
    }
  }
}

// quicksort che ordina in modo crescente

template <typename TD>
void quicksort1(TD* v,unsigned int number_of_data) {
   int i=0, j;
   TD separator;
   if (number_of_data < 2) return;
   separator = v[number_of_data/2];
   j=number_of_data-1;
    while (j>i) {
     while ( v[i]<separator ) i++;
     while ( v[j]>separator ) j--;
     if (i<j) {
       swap( v[i], v[j] );
       i++;
     }
   } 
  quicksort1(v,i);
  quicksort1(v+i,number_of_data-i);
}

// quicksort che ordina in modo decrescente

template <typename TD>
void quicksort2(TD* v,unsigned int number_of_data) {
  int i=0, j;
  TD separator;
  if (number_of_data < 2) return;
  separator = v[number_of_data/2];  
  j=number_of_data-1;
  while (j>i) {
    while ( v[i]>separator ) i++;
    while ( v[j]<separator ) j--;
    if (i<j) {
      swap( v[i], v[j] );
      i++;
    }
  } 
  quicksort2(v,i);
  quicksort2(v+i,number_of_data-i);
}

// funzione conta 

unsigned int conta(){
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre i numeri" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  while(!input.good()){
    std::cerr << "Errore nell'apertura del file:" << std::endl;
    std::cout << "Si prega di reinserire il nome del file" << std::endl;
    std::cin >> namefile;
    input.open(namefile);
  }
  double tmp;
  unsigned int number_of_data=0;
  input >> tmp;
  while(!input.eof()){
    ++number_of_data;
    input >> tmp;
  }
input.close();       //ricordarsi di chiudere lo stream
  return number_of_data;
}

//funzione carica solo elementi di posto dispari di un array monodimensionale

template <typename TD>
void load_dispari(TD * v, unsigned int number_of_data){     //number_of_data rappresenta tutti i valori dell'array!!!
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre i tuoi " << number_of_data/2 << " numeri (il primo elemento dell'array ha posto 0)" << std::endl;
  char namefile[30];
  cin >> namefile;
  TD tmp;
  input.open(namefile);
  while(!input.good()){
    std::cerr << "Errore nell'apertura del file:" << std::endl;
    std::cout << "Si prega di reinserire il nome del file" << std::endl;
    std::cin >> namefile;
    input.open(namefile);
  }
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

//funzione che carica coppie di dati non affetti da errore (punto in R2)

template <typename TD>
void loadR2(TD* x,TD* y,unsigned int dim){          //dim indica la lunghezza o solo delle ascisse o solo delle coordinate!
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre le " << dim << " coppie di numeri" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  while(!input.good()){
    std::cerr << "Errore nell'apertura del file:" << std::endl;
    std::cout << "Si prega di reinserire il nome del file" << std::endl;
    std::cin >> namefile;
    input.open(namefile);
  }
  for(unsigned int e=0;e<dim;++e){
    input >> x[e] >> y[e];
#ifdef DEBUG 
    std::cout << x[e] << "  " << y[e] << std::endl;
#endif
  }
  input.close();
}

// funzione che carica una coppia di coordinate cartesiane di cui solo la x è soggetta ad errore

template <typename TD>
void loadxerr(TD* x,TD* y,TD* errx, unsigned int number_of_data){
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre le " << number_of_data << " coppie di numeri con errore sull'ascissa" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  while(!input.good()){
    std::cerr << "Errore nell'apertura del file:" << std::endl;
    std::cout << "Si prega di reinserire il nome del file" << std::endl;
    std::cin >> namefile;
    input.open(namefile);
  }
for(unsigned int a=0;a<number_of_data;++a){
  input >> x[a] >> y[a] >> errx[a];
#ifdef DEBUG 
    std::cout << x[a] << "  " << y[a] << " " << errx[a] << std::endl;
#endif
}
input.close();
}

// funzione che carica una coppia di coordinate cartesiane di cui solala y è soggetta ad errore

template <typename TD>
void loadyerr(TD* x,TD* y,TD* erry, unsigned int number_of_data){
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre le " << number_of_data << " coppie di numeri con errore sulla ordinata" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  while(!input.good()){
    std::cerr << "Errore nell'apertura del file:" << std::endl;
    std::cout << "Si prega di reinserire il nome del file" << std::endl;
    std::cin >> namefile;
    input.open(namefile);
  }
for(unsigned int a=0;a<number_of_data;++a){
  input >> x[a] >> y[a] >> erry[a];
#ifdef DEBUG 
    std::cout << x[a] << "  " << y[a] << " " << erry[a] << std::endl;
#endif
}
input.close();
}

//funzione che carica un vettore monodimensionale

template <typename TD>
  void load(TD* x,unsigned int dim){
  std::ifstream input;
  std::cout << "inserisci il file da cui vuoi estrarre i " << dim << " numeri" << std::endl;
  char namefile[30];
  cin >> namefile;
  input.open(namefile);
  while(!input.good()){
    std::cerr << "Errore nell'apertura del file:" << std::endl;
    std::cout << "Si prega di reinserire il nome del file" << std::endl;
    std::cin >> namefile;
    input.open(namefile);
  }
for(unsigned int a=0;a<dim;++a){
  input >> x[a];
#ifdef DEBUG 
    std::cout << x[a] << std::endl;
#endif
}
input.close();
}

#endif
