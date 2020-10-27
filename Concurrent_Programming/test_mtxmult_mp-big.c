
#include "mtxmult_mp.h"
#include <math.h>
#include <string.h>

int main(int argc, char** argv){
	size_t nbproc = NUM_PROCESS;
	if( argc < 3){
		printf("Usage: %s nrows ncols [ nbproc (%zu) ] [-ns]\n\n-ns\t\tno single-thread\n",\
			argv[0],nbproc);
		return -1;
	}
	size_t nrows = (size_t) atol(argv[1]);
	size_t ncols = (size_t) atol(argv[2]);
	if( argc > 3 ){
		nbproc = (size_t) atol(argv[3]);
	}
	int skip_single_thread=0;
	if ( argc > 4 && strcmp("-ns",argv[4])==0){
		skip_single_thread=1;
	}
	printf("Max # threads: %zu\n",nbproc);
	printf("Random array size %zux%zu\n",nrows,ncols);
	//orig matrix in shared memory makes no difference due to COW and being
	//used just for reading by children
	double *A2, *A = mmap(NULL,nrows*ncols*sizeof(double),PROT_READ | PROT_WRITE,\
											MAP_SHARED | MAP_ANONYMOUS, -1, 0); 
	//double *A2, *A = (double*) calloc(nrows*ncols, sizeof(double));
	srand(1234567);
	for(size_t i = 0 ; i < nrows*ncols ; i++){
		 A[i] = floor((10.0*rand())/RAND_MAX) ;
	}
	const size_t asz[2]={nrows,ncols};
	pmtx(A,nrows,ncols,"A");
	time_t begin ;
	if( !skip_single_thread ){
		printf("Single thread\n");
		begin = time(NULL);
		//pmtx( mtxsq(A,asz),nrows,ncols,"A^2");
		A2=mtxsq(A,asz);
		printf("Time: %zu sec.\n",time(NULL)-begin);
		pmtx(A2,nrows,ncols,"A^2");
	}
	begin = time(NULL);
	//pmtx( mtxsq_thr(A,asz,nbproc),nrows,ncols,"A^2");
	A2=mtxsq_thr(A,asz,nbproc);
	printf("Time: %zu sec.\n",time(NULL)-begin);
	pmtx(A2,nrows,ncols,"A^2");
	return 0;
}
