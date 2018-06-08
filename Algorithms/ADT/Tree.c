#include<stdio.h>
#include<stdlib.h>

typedef struct Tree Tree;
struct Tree { 
	size_t key;
	int	data;
	Tree* l;
	Tree* r;
}; 

void printTree(Tree* t){
	if ( t==NULL ) return;
	printf(" (%lu, %d)\n",t->key,t->data);
	printTree(t->l);
	printTree(t->r);
}

int main(){
	Tree leaf2 = {2,99,NULL,NULL};
	Tree leaf3 = {3,33,NULL,NULL};
	Tree leaf1 = {1,66,&leaf3,NULL};
	Tree t = {
		0, 666,
		 &leaf1,
		 &leaf2
	};
	printTree(&t);
	return 0;
}

