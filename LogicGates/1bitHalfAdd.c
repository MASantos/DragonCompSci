#include<stdio.h>

/*
 *Bit manipulation:
 & AND
 | OR
 ^ XOR
 <<n Left-shift n positions
 >>n Right-shift n positions
 */

int main(){
	int a=1, b=0;
	int s=0,c=0;

	//1-bit half adder
	s=a^b;
	c=a&b;

	printf("%d+%d = %d (c:%d)\n",a,b,s,c);
	
	return 0;
}
