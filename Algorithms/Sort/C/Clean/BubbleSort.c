#include"helper.h"

void bubbleSortRec(float* A, size_t N){
	if ( N == 1 ) return ;

	bubbleSortRec( (A+1), N-1) ;
	
	float tmp ;
	size_t i ;
	for( i = 0 ; i < N-1 ; i++){
		if ( *(A+i) > *(A+i+1) ) {
			tmp = *(A+i+1) ;
			*(A+i+1) = *(A+i) ;
			*(A+i)  = tmp ; 
		}
	}
}

