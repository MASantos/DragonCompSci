
#include "mtxmult_mp.h"

int main(int argc, char** argv){
	size_t nbproc = NUM_PROCESS;
	if( argc > 1 ){
		nbproc = (size_t) atol(argv[1]);
	}
	printf("Max # threads: %zu\n",nbproc);

	double A[] = {1.0,2.0,3.0,4.0, 5.0,6.0,7.0,8.0,9.0}; 
	const size_t asz[2]={3,3};
	pmtx(A,3,3,"A");
	printf("Single thread\n");
	pmtx( mtxsq(A,asz),3,3,"A^2");
	pmtx( mtxsq_thr(A,asz,nbproc),3,3,"A^2");
	return 0;
}
