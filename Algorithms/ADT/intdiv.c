#include<stdio.h>

int main(){
	size_t i =7, p= i/2, c,d;
	c = 0; d = (c-1)/2 ;
	printf("For unsigned long int:%lu/2 = %lu\n",i,p);
	printf("                     (%lu-1)/2 = %lu/2 = %lu\n",c,c-1,d);
	unsigned int e  =  0, f  =  (e-1)/2 ;
	printf("For unsigned int: (%d-1)/2 = %d/2 = %d\n",e,e-1,f);
	int g  =  0, h  =  (g-1)/2 ;
	printf("For int: (%d-1)/2 = %d/2 = %d\n",g,g-1,h);
	return 0;
}
