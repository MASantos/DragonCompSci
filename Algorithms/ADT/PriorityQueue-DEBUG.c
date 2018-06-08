/*
ADT: Priority Queue

Example of DEBUGGING using Pre-processor macros and options (https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html)

For DEBUGGING information compile as    gcc -D DEBUG PriorityQueue-DEBUG.c -o PriorityQueue-DEBUG

For NO debugging information compile as gcc          PriorityQueue-DEBUG.c -o PriorityQueue-DEBUG

Remarks for implementation in C:
The C library stdio.h already has a function called 'remove'. 
We will thus call our 'remove' 'delete' in order to avoid a clash.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node entry;
typedef entry* PQueue ;
struct node { 
	size_t key;
	int	data;
}; 

entry* insert(entry*, PQueue*, size_t* );

PQueue newPriorityQueue(){ //constructor proxy
	PQueue T = NULL;
	return insert(NULL,&T,0);
}

PQueue insert(entry* e, PQueue* T, size_t* n){ // Note: Here T is pointer to a PQueue, not a PQueue! Hence, *T is a PQueue.
	if ( e == NULL ) return *T;
	if ( *T == NULL ) {
		if( e == NULL ) {
			*n=0;
			*T = (PQueue) calloc(0,sizeof(entry)) ;
		}
		else{
			*n = 1;
			*T = (PQueue) calloc(1,sizeof(entry)) ;
			(*T)[0]= *e ;
		}
		return *T;
	}
	*n = *n + 1;
	//In order to push a new entry to the end of an array, C requires us to reallocated the 
	//memory chunk associated to our array. In doing so we will be asking for 1 more entry space.
	*T = (PQueue) realloc(*T,*n);  
	if ( *T == NULL ) { 
		printf("ERROR: Could not allocate memory for new element of Priority Queue\n");
		exit(1);
	}
	(*T)[*n-1] = *e;

	entry tmp;
	size_t i  = *n-1;
	size_t parent = (i==0)*i+(i>0)*(i-1)/2 ; //integer division. Hence works for both i even and odd. Careful: can't use (i-1)/2 for unsigned int/long!
#if DEBUG
	printf("DEBUG: insert : start descent loop : n / i / parent: %lu / %lu / %lu\n",*n,i,parent);
	printf( "DEBUG: \tT[%lu].key=%lu >? T[%lu].key=%lu...",i, (*T)[i].key , parent, (*T)[parent].key  );
#endif
	while(  (*T)[i].key > (*T)[parent].key  ){
		tmp = (*T)[parent];
		(*T)[parent] = (*T)[i] ;
		(*T)[i] = tmp;
		i = parent;
		parent = (i==0)*i+(i>0)*(i-1)/2 ; 
#if DEBUG
		printf( "yes!\n\tDEBUG: \tT[%lu].key=%lu >? T[%lu].key=%lu...",i, (*T)[i].key , parent, (*T)[parent].key  );
#endif
	}
#if DEBUG
	printf("no\n");
#endif
	return *T;
}

entry delete(PQueue* T, size_t* n){
	if ( *T == NULL ) {
		*n = 0;
		entry none = { 0, -1};
		return none;
	}
	entry prev_top = (*T)[0] ;
	*n = *n - 1; //new size 
	(*T)[0] = (*T)[*n] ;
	*T = (PQueue) realloc(*T,*n); //we could skip this for speed, but then memory usage is higher. Your choice.
	size_t i = 0, left, right, child_lg; //mchild = child w/ largest key
	int swap = 1 ; //flag
	entry tmp ;
	while( swap && (i < *n) ){
		left = 2*i+1;
		right= 2*i+2; 
		swap = 0;
		child_lg = right;
		if( (*T)[left].key > (*T)[right].key ){
			child_lg = left;
		}
		if( (*T)[i].key < (*T)[child_lg].key ){
			swap = 1;
			tmp = (*T)[child_lg];
			(*T)[child_lg] = (*T)[i];
			(*T)[i] = tmp;
			i = child_lg;
		}
	}
	return prev_top;
}

void prntPQ(PQueue T, size_t ,size_t );

void printPQueue(PQueue T, size_t n){
	size_t i = 0;
	if ( T == NULL ) i = n;
	prntPQ(T, i, n);
}

void prntPQ(PQueue T, size_t i,size_t n){
	if( i == n ){ 
		printf("\n");
		return;
	}		
	printf(" (%lu, %d)  ",T->key,T->data);
	prntPQ( (T+1), i+1,n);
}

int main(){
	PQueue T = newPriorityQueue(); // T = (PQueue*) NULL
#if DEBUG
	printf("DEBUG: Instantiated new priority queue at T=0x%lu\n",(unsigned long)T);
#endif
	printPQueue(T,0);
	//For the sake of simplicity, here the entries' data will be same as key
	int v[7] = {1,1,8,8,12,9,19};
	entry* e = calloc(1, sizeof(entry) ); 
	size_t i ;
	for( i = 0 ; i < 7 ; ){ //insert will increment i
		e->key = (size_t) v[i];
		e->data = v[i];
#if DEBUG
		printf("DEBUG: inserting entry %lu : k=%lu\n",i,e->key);
#endif
		insert(e,&T,&i);
#if DEBUG
		printf("DEBUG: inserted %lu entries: T[0]=(%lu,%d)\n",i,T->key,T->data);
#endif
	}
	printPQueue(T,i); // at this point i = 7 after the end of loop
	*e = delete(&T,&i);
	printf("Removed root: key=%lu  value=%d\n",e->key,e->data);
	printPQueue(T,i); // at this point i = 6 after removal of root
	return 0;
}

