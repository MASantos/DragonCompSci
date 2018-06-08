#include<stdio.h>
#include<stdlib.h> //needed for calloc

struct node {
	int key;
	int value;
}; 

int main(){
	struct node a1 , a0 = { 0, -66 };
	a1 = a0;
	printf("a1: (%d,%d)\n",a1.key,a1.value);
	struct node* a2 = (struct node*) calloc(1,sizeof(struct node)); 
	*a2 = a0;
	printf("a2: (%d,%d)\n",a2->key,a2->value);
	return 0;
}
