#include<stdio.h>
#include<stdlib.h>

/*
ADT:: Linked list of integers
Idea: Each entry of a l-list contains some data (w/ specific data type!) and a pointer to
      the next entry of the l-list.

      Main Interfaces:
	insert:: Idea: inserts a data element into the l-list 'list' as (new) element pos-th
		 Detail: the previous (pos-1-th) element gets its pointer resassigned to new data element.
		         the new data elemen gets its pointer reassigned to the original value of the 
			 previous element's pointer

			 Induction Hypothesis: We can insert i<=n elements
			 Reduction step: list( n+1, data in k) = list( elem 0->k-1)->next = &(data,next)
					and
			                 data.next = list(elem k->n)
			 Base case:  empty list. Just assign (data,next) to list and return the latter
			 
		PSEUDO-CODE
		Algorithm: insert( list, data, pos)
		Input: data (integer), pos (position along l-list), list (pointer to l-list) 
		       Each elem of list is (data, next_ptr)
		Output: pointer to new l-list
		
		BEGIN  insert( data, pos, list)
			if list empty and pos != 0 :  print error and return empty list
		
			nentry = create node (data, null) //null signals end of l-list
			
			if pos = 0 and list empty: return &nentry //means address of nentry
		
			i = 0
			current = l
			while  i < pos :
				current = current-> next	
				i++
			nentry->next = current->next
			current->next =  &nentry
			return l
		END insert
			
		Warning: This code doesn't deal with memory management: deleted entries left still around in memory!
			
	remove:: Idea: removes the pos-th entry of the l-list
		 Detail: the previous (pos-1) entry gets its pointer reassiged to point to the element
			 the original pos-th element was pointing to.

		 PSEUDO-CODE
		 Algorithm: delete( pos, list )
		 Input:  pos (pos along l-list), list (pointer to l-list) 
		 Output: pointer to new-list

		 BEGIN delete( pos, list)
			if list empty : return empty
			if pos = 0 : 
				list = list->next 
				return list
			i = 0 
			current = l
			while  i < pos-1 :
				curent = current-> next
				i++
			//current is now pointing to pos-1; current->next = pos ; (current-next)-next = pos+1
			current->next = (current->next)->next 
			return list
		 END delete
	
	length:: Idea: returns the number of elements in the linked list
		 Detail: O(n) loop through the list

	printLL: Idea: print the list
		 Detail: Simple linear loop over the list

/////////////////////

	Specifics for C:
	Each entry of our l-list will be of type
	
	struct node {
	  int data;
	  struct node* next;
	}
*/

struct node {
	int data;
	struct node* next;
};

/*
Without this extra declaration here the following return statement gives an error when compiling:
 It makes a reference to function insert before even being declared or defined.
Whence, we can either move the definition of newLList to beyond that of insert or 
add this extra declartion.

We'll opt for the latter to showcase how this extra definition works.
*/
struct node*  insert(int , size_t , struct node* );


struct node* newLList(){     //simulates a "constructor": user doesn't need to explicitly first define the llist as null
	return insert(0,1, NULL) ; //these values make the first check of insert true and we get a null pointer
}

struct node*  insert(int a, size_t pos, struct node* l ){
	if ( l == NULL  && pos >0 ) return NULL ;

	struct node* nentry = (struct node*) calloc(1,sizeof(struct node));
	nentry -> data = a;
	nentry -> next = NULL;

	if ( pos == 0  && l==NULL) {
		l =  nentry;
		return l;
	} 

	size_t i = 0;
	struct node* current = l;
	while( i < pos ){
		if ( current == NULL ) {
			printf("ERROR: inserting beyond the limits of the linked list: i=%lu,  pos=%lu\n",i,pos);
			return l;
		} 
		current = current->next;
		i++;
	}
	nentry->next = current->next;
	current->next = nentry;
	return l;
}

struct node* delete(size_t pos, struct node* l ){
	if ( l == NULL ) return l; //maybe we should flag this as an error?
	size_t i = 0;
	struct node* current = l;
	while( i < pos-1) {
		if ( current == NULL ) {
			printf("ERROR: Attempt deleting beyond the limits of the linked list: i=%lu,  pos=%lu\n",i,pos);
			return l;
		} 
		current = current->next;
		i++;
	}
	current->next = (current->next)->next;
	return l;
}

size_t length( struct node* L){
	size_t n=0;
	struct node* ll_ptr = L;
	while ( ll_ptr != NULL ){
		n++;
		ll_ptr = ll_ptr->next;
	}
	return n;
}

void printLL(struct node* L){
	struct node* ll_ptr = L;
	printf("L-List (%lu) = ",length(L));
	while ( ll_ptr != NULL ){
		printf("%d ",ll_ptr->data);
		ll_ptr = ll_ptr->next;
	}
	printf("\n");
}

int main(){
	struct node* L = newLList();
	printf("Inserting data....");	
	L=insert(4,0,L);
	L=insert(3,0,L);
	L=insert(7,0,L);
	printf("Done.\n");
	printLL(L);
	printf("Deleting data....");	
	L=delete(5,L);
	printf("Done.\n");
	printLL(L);
	printf("Deleting data....");	
	L=delete(1,L);
	printf("Done.\n");
	printLL(L);

}
