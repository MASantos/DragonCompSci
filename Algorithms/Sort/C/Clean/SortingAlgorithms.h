
//Declare your sorting function

//Bubble Sort Recursive version
void BubbleSortRec(float* A, size_t N) ;
/*Adapt the following to suit signature of your sorting function
   In main define as 'sortf sort = &bubbleSortRec ;'
  and use as '(*sortf)(A,N) ;
*/
#ifdef __BUBBLESORT__
typedef void (*sortf)(float*, size_t) ;
#endif

//Selection Sort
void SelectionSort(float* A, size_t N) ;
#ifdef __SELECTIONSORT__
typedef void (*sortf)(float*, size_t) ;
#endif

//Insertion Sort Recursive
void InsertionSortRec(float* A , size_t N) ;
#ifdef __INSERTIONSORT__
typedef void (*sortf)(float*, size_t) ;
#endif

//Quick Sort Recursive
void qSortRec(float* A, size_t l, size_t r) ;
#ifdef __QUICKSORT__
typedef void (*sortf)(float*, size_t, size_t) ;
#endif


