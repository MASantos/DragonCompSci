#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "mtxmult.h"

int main(int argc, char** argv){
	double A[] = {1.0,2.0,3.0,4.0, 5.0,6.0,7.0,8.0,9.0}; 
	const size_t asz[2]={3,3};
	pmtx(A,3,3,"A");
	printf("Single thread\n");
	pmtx( mtxsq(A,asz),3,3,"A^2");
	return 0;
}
