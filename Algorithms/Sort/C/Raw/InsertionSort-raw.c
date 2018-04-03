#include"helper.h"

/* INSERTION SORT
Here we called it R(ecursive) Swap, or Rswap, as that's how we implement it.

*/

float* InsertionSortRec(float* ar, size_t n){
	if ( n<2) return ar; //Base case n=1 :=> nothing to do

	printf("DEbug: i: ar[%zu]  : ",n); printFarray(ar, n);

	//Constructing and sorting slice ar[0,n-1]
	float* ar1 = (float*) calloc(n-1,sizeof(float));
	size_t i;
	for( i =0 ; i< n-1 ; i++){
		ar1[i] = ar[i] ;	
	}
	InsertionSortRec( ar1 , n-1) ;
	//In C we can't just return pointer to local variable to be used after scope ends
	// whence lets store sorted list back into original array and return this
	for( i =0 ; i< n-1 ; i++){
		ar[i] = ar1[i] ;	
	}
	// At this point we have : ar = InsertionSortRec( ar[:n-1] ) ++ [ ar[n-1] ]
	unsigned int  flip ;
	do{
		flip = 0 ; 
		if ( ar[i] < ar[ i-1 ] ){
			float tmp = ar[i-1];
			ar[i-1] = ar[i] ;
			ar[i] = tmp;
			flip = 1 ;
			i-- ;				
		}	
	} while ( i > 0 && flip) ;

	printf("DEbug: a: ar[%zu]  : ",n); printFarray(ar, n);
	return ar ;
}

int main(){

	float r[9] = {87, -3, 1, 6, -17, 3, 2, 1,7} ;
	size_t n = 9 ;
	printf("Sorting ") ;
	printFarray(r, n );
	InsertionSortRec(r, n)  ;
	printFarray(r, n );
	return 0;
}
