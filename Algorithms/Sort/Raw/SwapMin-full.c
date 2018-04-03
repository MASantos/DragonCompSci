#include<stdio.h>
#include<float.h>
#include<stdlib.h>

#define RNDMX 2^31-1

/*
SELECTION SORT

We called it with the more explicit name SwapMin(imum). See below
*/

//Helper functions
//Find minimum value in slice of array of floats
float findMin(float* ar, size_t n, size_t i){
	float m = FLT_MAX ; 
	for( ; i< n ; i++){
		if ( ar[i] < m ) m = ar[i] ;	
	}
	return m ;
}

//Find index of the first instance of value m in slice of array of floats. Returns -1 if not found
size_t findIndex(float m , float* ar, size_t n , size_t is){
	size_t i ;
	for( i = is ; i< n ; i++) {
		if( m == ar[i] ) return i ;
	}
	return (size_t) (-1) ;
}

//prints array of floats
void printArray(float* ar, size_t n ){
	printf("[");
	size_t i ;
	for(i=0; i< n-1; i++){
		//printf("%f, ",ar[i]) ;
		printf("%f, ",*(ar+i)) ;
	}
	//printf("%f]",ar[i]) ;
	printf("%f]",*(ar+i)) ;
	printf("\n");
}

//Integer exponentiation
int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

//END OF HELPER FUNCTIONS

/* SELECTION SORT function 
  return type could be void
  We will make it return the number of swaps done
*/
unsigned long int selectionSort(float* ar, size_t n){
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

int main(){
/*
	float r[9] = {87, -3, 1, 6, -17, 3, 2, 1,7} ;
	printf("Sorting ") ;
	printArray( r , 9) ;
	printf( "Swaps: %lu\n", selectionSort(r,9) ) ;
	printf("Original array now: ");
	printArray( r , 9) ;
*/
	long MX = ipow(2,31)-1 ; 
	size_t N = 128000 ; 
	float* r = (float*) calloc(N, sizeof(float) ) ;
	size_t i ;
	for( i = 0 ; i < N ; i++ ) *(r+i) = random()*100.0/MX ;
	selectionSort(r,N);
	//printArray(r,30);
	return 0;
}

