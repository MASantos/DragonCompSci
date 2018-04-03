#include"helper.h"

/* QUICK SORT 

*/

size_t partition(float* A, size_t l, size_t r ){
	size_t p = l ; 
	float tmp = 0 ; 
	size_t i ;
	//printf("DEBUG: Qsort l:%lu, r:%lu, p:%lu :  A= ",l,r,p); printArray(A,9) ;
	for( i = p+1 ; i <= r ; i++ ){
		if ( *(A+i) > *(A+p) ) continue ;
		tmp = *(A+ (p+1) ) ;
		*(A+(p+1)) = *(A+i) ;
		*(A+i)  = tmp ;

		tmp = *(A+ (p+1) ) ;
		*(A+ (p+1) ) = *(A+p);
		*(A+p) = tmp ;
		p++;
		//printf("DEBUG: Qsort l:%lu, r:%lu, p:%lu, i:%lu :  A= ",l,r,p,i); printArray(A,9) ;
	}
	return p ; 
}

void qSortRec(float* A, size_t l, size_t r){
	if ( r <= l ) return ;
	size_t p = partition(A,l,r);
	qSortRec(A,l,p-1);
	qSortRec(A,p+1,r);
}

