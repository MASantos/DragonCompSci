/*
ADT: Priority Queue
A priority queue is a heap with efficient  insertion and deletion of elements
A Deletion is always that of the highest key element.

Note, a Heap is a tree satisfying:
 1. degree of all nodes is 2 (i.e., it's a Binary tree)
 2. Each node satisfies the heap property, namely, its key is >= children's keys

In this example we will use an implicit representation for trees, i.e., that of
an array, such that the left and right children of a node j (starting by 1) are located at positions 2*j 
and 2*j+1, respectively, in the array.

Example: The following is an unbalanced Heap. T=[19,12,8,9,1,-1,-1,1,8]
            19
          /    \
         12     8
       /   \
      9     1
     / \
    1   8
Notice that wee must insert a "reserved" key value for signaling an absence of a child-node. 
Here we do it using -1 (assuming all keys are positive values. If the elements contain pointers
to struct, the this could be a NULL pointer).

Gaps in the array of an implicit representation of a tree (like those -1s) will denote an unbalanced tree.
However, the way insertion is implemented for a priority queue will NEVER lead to such an unbalanced tree.

Example: The same keys in a balanced heap. T=[19,12,9,8,8,1,1]
            19
          /    \
         12     9
       /   \   / \
      8     8 1   1

Example: Another balanced heap w/ the same keys. T=[19,12,9,8,8,1,1]
            19
          /    \
         8     12
       /   \   / \
      1     8 1   9

Note about the indexing of T: 
Usually array indices start by 0. What is then the relation between a node and its children? 
Clearly it's not 
			i, 2i and 2i+1
as this doesn't even hold true for the root. We would get 0, 0, 1 instead of 0, 1, 2

For j=[1,2,3...], we say
	parent		node	left 	right
	floor( j/2 )    j	2j       2j+1.
But that doesn't actually work for j=1 : floor( 1/2 ) == 0 != 1!!

Consider the rest (j>1) and index i starting by 0, i.e, j=i+1
floor( j/2 )		j       2j      2j+1   (sequences start by 1)
floor( (i+1)/2 )	i+1     2i+2    2i+3
--------------------------------
floor( (i-1)/2 )	i       2i+1    2i+2   (sequence starts by 0)
But this doesn't actually work for i=0 either if i is unsigned; it works if i is int!!
(See C-basics material intdiv.c )

We will treat case i=0 thus separately, as we will be using size_t (aka, unsigned long) for i.


Algorithm: Remove element of a priority queue
	Idea: Remove root and put in its place the last element of (array) T. Then propagate down that element till T is again a heap.
	
	Detail: We propagate it down by swapping it at each step with the largest of its two children. We stop when none of them is larger.

	PSEUDO-CODE:
	Algorithm: remove(T)
	Input: T ( array: Heap in implicit representation)
	Output: r ( root element of T)
                T' ( T w/o the root)

	BEGIN remove(T):
		if T empty return T
		Assume n entries.
		n <- len(T)
		r=T[0] (store root as it will be returned at the end)
		T[0] = T[n-1] and drop copy T[n-1] -> T has n-1 entries now
		i=0
		while T[i] < T[ 2i+1) ] or T[2i+2] 
		     swap T[i] with the largest of the children
		     i <- 2i+1 or 2i+2 depending on prevous step
		return r and T
	END

	Complexity: In each step we do 2 comparisons (plus 2 swaps ) and there are log_2(n) steps, hence O(log n)

Algorithm: Insert an element into a priority queue.
	Idea: Added it to the end and propagate it while it's larger than its root

	PSEUDO-CODE:
	Algorithm: insert(e,T)
	Input: e (key of a data  element) T (array: Heap in implicit  representation)
	Output: T' ( T heap array w/ new element)

	BEGIN insert(e,T):
		if T == NULL : return T=[e]
		n <- len(T)
		Push e at end of T.
		i = n 
		while T[i] > root  ( that's T[ i/2 ] (for i even) or T[ (i-1)/2 ] (for i odd) )
			swap i w/ its root 
			i <- i/2  or (i-1)/2
		return T
	END
*/

/*
Remarks for implementation in C:
The C library stdio.h already has a function called 'remove'. 
We will thus call our 'remove' 'delete' in order to avoid a clash.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node entry;
typedef entry* PQueue ;
struct node { 
	size_t key;
	int	data;
}; 

entry* insert(entry*, PQueue*, size_t* );  // passing around pointers so function can modify arguments inside. No need for T = insert(a, T, n) 

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
			*T = (PQueue) calloc(1,sizeof(entry)) ; //technically we should check if mem alloc failed...Skip for simplicity => segmentation fault if fails
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
	while(  (*T)[i].key > (*T)[parent].key  ){
		tmp = (*T)[parent];
		(*T)[parent] = (*T)[i] ;
		(*T)[i] = tmp;
		i = parent;
		parent = (i==0)*i+(i>0)*(i-1)/2 ; 
	}
	return *T;
}

entry delete(PQueue* T, size_t* n){ //see comment for insert.
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

//printing a Priority Queue
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
	//For the sake of simplicity, here the entries' data will be same as key
	int v[7] = {1,1,8,8,12,9,19};
	printf("Building Priority Queue with keys: ");
	size_t i ;
	for(i=0; i< 7 ; i++) printf("%d ",v[i]);
	printf("\n");	
	entry e; 
	for( i = 0 ; i < 7 ; ){ //insert will increment i
		e.key = (size_t) v[i];
		e.data = v[i];
		insert(&e,&T,&i);
	}
	printPQueue(T,i); // at this point i = 7 after the end of loop
	e = delete(&T,&i);
	printf("Removed root: key=%lu  value=%d\n",e.key,e.data);
	printPQueue(T,i); // at this point i = 6 after removal of root
	//
	printf("\nRebuilding heap T again with keys: ");
	int u[7] = {1,9,8,1,19,8,12};
	for(i=0; i< 7 ; i++) printf("%d ",u[i]);
	printf("\n");	
	//free(T); //we would need to free previous mem alloc before resetting T
	//T = newPriorityQueue(); //resetting T 
	for( i = 0 ; i < 7 ; ){ 
		e.key = (size_t) u[i];
		e.data = u[i];
		insert(&e,&T,&i);
	}
	printPQueue(T,i); 
	e = delete(&T,&i);
	printf("Removed root: key=%lu  value=%d\n",e.key,e.data);
	printPQueue(T,i); 
	e = delete(&T,&i);
	printf("Removed root: key=%lu  value=%d\n",e.key,e.data);
	printPQueue(T,i); 

	return 0;
}

