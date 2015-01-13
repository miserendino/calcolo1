#include <iostream>
#include <fstream>
#ifndef __ORDINAMENTI.HPP__
        template <typename TD>
    void bubblesort( unsigned int number_of_data, TD v);
        template <typename TD>
    void quicksort( unsigned int number_of_data, TD* v);
        template <typename TD>
    void scambia( TD*, TD*);

    template <typename TD>
  void scambia( TD* a,TD* b) 
  {
    TD temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

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


#endif
