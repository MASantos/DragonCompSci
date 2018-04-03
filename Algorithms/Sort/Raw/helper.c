#include"helper.h"

// BEGIN HELPER FUNCTIONS
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
int ipow(int base, int exp){
	int result = 1;
	while ( exp ) {
		if ( exp & 1 ) result *= base ;
		base *= base ;
		exp >>= 1 ;
	}
	return result ;
}

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

//END OF HELPER FUNCTIONS
