#include<stdio.h>

void incrprt(size_t* n ){
	*n = *n + 1;
}
int main(){
	size_t n = 1;
	printf("start:: n = %lu\n",n);
	incrprt(&n);
	printf("n = %lu\n",n);
	incrprt(&n);
	printf("n = %lu\n",n);
	return 0;
}
