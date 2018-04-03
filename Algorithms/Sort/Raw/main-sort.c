#include"helper.h"

void bubbleSortRec(float* A, size_t N) ;

int main(int argc , char** argv){
        float r[9] = {87, -3, 1, 6, -17, 3, 2, 1,7} ;
        printf("Sorting ") ;
        printArray( r , 9) ;
        bubbleSortRec(r,9) ;
        printf("Original array now: ");
        printArray( r , 9) ;

/*
        long MX = ipow(2,31)-1 ;
        size_t N = 128000 ; // even >~ 10^7 12800000 ;
        if ( argc > 1 ) N = (size_t) strtol(argv[1], NULL, 0) ;
        float* r = (float*) calloc(N, sizeof(float) ) ;
        if ( !r ) printf("ERROR : cannot allocate memory\n");
        size_t i ;
        for( i = 0 ; i < N ; i++ ) *(r+i) = random()*100.0/MX ;
        qSort(r,0,N);
        //printArray(r,30);
        free( r );
*/
        return 0;
}
