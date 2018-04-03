#include"helper.h"

/* SELECTION SORT function 
  return type could be void
  We will make it return the number of swaps done
*/
unsigned long int SelectionSort(float* ar, size_t n){
	/*
	  Selection Sort
	  iteratively swap mininum of remaining slice
	  Modifies original array

	  n := length of array ar
	*/
	if  ( n < 2 )  return 0 ;
	// i absolute position of first element of slice starting at i: ar[i:]
	unsigned long int swaps = 0;
	size_t i = 0 ;
	size_t jm ; 
	float m, tmp;
	while (1) { //do-until loop
		m = findMin( ar, n , i ) ;
		//finds absolute index of 1st instance of m in slice starting at i
		jm = findIndex(m, ar, n , i)  ;
		tmp = ar[i];
		ar[i] = m;
		//jm is absolute position in ar, NOT relative to slice size. No need to Add i for absolute position in ar
		//ar[jm+i]= tmp 
		ar[jm]= tmp ;
		//printf( "DEBUG: jm=%lu i=%lu ",jm,i ); printArray(ar, n);
		i+=1;
		if ( jm != i ) swaps++;
		if (i == n)  break ;
	}
	return swaps ;
}

