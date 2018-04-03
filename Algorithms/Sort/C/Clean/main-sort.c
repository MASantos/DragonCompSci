#include"helper.h"
//#define __BUBBLESORT__
#define __SELECTIONSORT__
//#define __INSERTIONSORT__
//#define __QUICKSORT__
#include"SortingAlgorithms.h"

/*
Generic main.c for sorting algorithms

BUILD INSTRUCTIONS:
1) Select the right define macro above
2) Select the right sortf definition below
3) Make sure the call to sort in main has the right (number of) arguments
4) Compile as gcc -o 'you-sorting-algo'  main-sort.c helper.c *Sort.c
   Example: gcc -o BubbleSortRec main-sort.c helper.c *Sort.c

*/

//sortf sort = &BubbleSortRec ;
sortf sort = &SelectionSort ;
//sortf sort = &InsertionSortRec ;
//sortf sort = &qSortRec ;
 
int main(int argc , char** argv){
        float r[9] = {87, -3, 1, 6, -17, 3, 2, 1,7} ;
        printf("Sorting ") ;
        printArray( r , 9) ;
	//Change the following according to signature of sortf above
        sort(r,9) ;
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
	
	//Change the following according to signature of sortf above
        qSort(r,0,N);
        //printArray(r,30);
        free( r );
*/
        return 0;
}
