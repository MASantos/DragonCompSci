#include<stdio.h>


/*
 * Goal: 1-bit full Adder
 * Name: bitFullAdd(a,b,c)
 * Input: a (bit-1), b(bit-2), c(initial carry value)
 * Output: s = (a^b)^c (xor of a,b,c); c' = [(a^b)&c]^(a&b)
 *
 * Truth Table for bitFullAdd:
 *
 * a|b|c|s|c'| |a^b|(a^b)&c|a&b
 * -|-|-|-|- | ||
 * 0|0|1|1|0 | |0|0|0
 * 0|1|1|0|1 | |1|1|0
 * 1|0|1|0|1 | |1|1|0
 * 1|1|1|1|1 | |0|0|1
 *
 * We will make the return value provide the sum S. C' will be stored inside the argument C,
 * Hence, C must be passed by reference. It's input value will be thus overriden.
 */


int bitFullAdd(int a, int b ,int* c){
	int s= (a^b)^*c;
	*c = ((a^b)&*c)^(a&b);
	return s;
	
}

int main(){
	int a=0,b=1;
	int s=0,c=1;
	printf("%d+%d (c:%d)=",a,b,c);
	s=bitFullAdd(a,b,&c);
	printf("%d (c':%d)\n",s,c);

	return 0;
}

