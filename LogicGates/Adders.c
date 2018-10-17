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

int main(){
	int a1 = 0 , a0 = 1;
	int b1 = 0 , b0 = 1;
	int c = 1;

	printf("a1=%d a0=%d c=%d\nb1=%d b0=%d\n------------\n",a1,a0,c,b1,b0);

	bbitFullAdd( &a0, &a1, &b0, &b1, &c); 

	printf("S1=%d S0=%d C=%d\n",a1,a0,c);

	return 0;
}
