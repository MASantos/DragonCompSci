#include<stdio.h>
#include<stdlib.h>

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
// END HELPER FUNCTIONS

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

void qSort(float* A, size_t l, size_t r){
	if ( r <= l ) return ;
	size_t p = partition(A,l,r);
	qSort(A,l,p-1);
	qSort(A,p+1,r);
}

int main(){
/*
        float r[9] = {87, -3, 1, 6, -17, 3, 2, 1,7} ;
        printf("Sorting ") ;
        printArray( r , 9) ;
        qSort(r,0,9-1) ;
        printf("Original array now: ");
        printArray( r , 9) ;
*/

        long MX = ipow(2,31)-1 ;
        size_t N = 12800000 ; 
        float* r = (float*) calloc(N, sizeof(float) ) ;
        size_t i ;
        for( i = 0 ; i < N ; i++ ) *(r+i) = random()*100.0/MX ;
        qSort(r,0,N);
        //printArray(r,30);
	free( r );
	return 0;
}
