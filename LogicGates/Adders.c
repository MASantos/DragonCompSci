#include<stdio.h>

int bitFullAdd(int a, int b ,int* c){
        int s = (a^b)^*c;
        *c = ((a^b)&*c)^(a&b);
        return s;
}

//2-bits full adder
void bbitFullAdd(int* a0, int* a1, int* b0, int* b1, int* c){
	*a0 = bitFullAdd( *a0, *b0, c) ;
	*a1 = bitFullAdd( *a1, *b1, c) ;
}

void tbitFullAdd( int* a0, int* a1, int* a2, int* b0, int* b1, int* b2, int* c){
	/* 
	 * We can either use 1-bit full adder 3 times in a row or use 2 bits adder and 1bit adder
	*a0 = bitFullAdd( *a0, *b0, c) ;
	*a1 = bitFullAdd( *a1, *b1, c) ;
	*/
	bbitFullAdd( a0, a1, b0, b1, c);
	*a2 = bitFullAdd( *a2, *b2, c) ;
}

int main(){
	int a2=0 , a1 = 1 , a0 = 1;
	int b2=1 , b1 = 0 , b0 = 1;
	int c = 1;

	printf("a2=%d a1=%d a0=%d c=%d\nb2=%d b1=%d b0=%d\n------------\n",a2,a1,a0,c,b2,b1,b0);

	/*
	printf("\nAdding just first 2 bits\n");
	bbitFullAdd( &a0, &a1, &b0, &b1, &c); 

	printf("S1=%d S0=%d C=%d\n",a1,a0,c);
	*/

	printf("\nAdding all 3 bits\n");
	tbitFullAdd( &a0, &a1, &a2, &b0, &b1, &b2, &c);

	printf("S2=%d S1=%d S0=%d C=%d\n",a2,a1,a0,c);

	return 0;
}
