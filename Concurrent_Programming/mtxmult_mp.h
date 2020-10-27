#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <sys/mman.h>

#include "mtxmult.h"

#define NUM_CORES 4
#define NUM_PROCESS (size_t)(NUM_CORES-1)
#define DEBUG 0

//
//Threaded ( via fork() ) version of matrix multiplication

double* mtxm_thr(double* a,const size_t asz[2],double* b,const size_t bsz[2], size_t nbproc){
	printf("Threaded Matrix Multiplication start...%zu threads\n",nbproc);
	if ( asz[1] != bsz[0] ){
		printf("ERROR: can't multiply A*B: columns of A %zu != rows of b%zu\n",asz[1],bsz[0]);
		exit(1);	
	}
	//result matrix in shared memory
	double* ab = mmap(NULL,asz[0]*asz[1]*sizeof(double),PROT_READ | PROT_WRITE, 
											MAP_SHARED | MAP_ANONYMOUS, -1, 0); 
	if( ab == MAP_FAILED){
		printf("ERROR: Couldn't allocate shared memory for matrix multiplication");
		exit(2);
	}

	size_t i,j,k, mop, mopo, pid, children=0, fchildren=0;
	size_t mpt = (asz[0]*bsz[1])/nbproc;
	size_t rmm = (size_t) ((asz[0]*bsz[1])%nbproc);
	if( mpt == 0){
		nbproc=asz[0]*bsz[1];
		mpt = 1;
		rmm = 0;
		printf("I: Too large number of processes. Reset to %zu\n",nbproc);
	}		
	size_t* fchildren_ptr = &fchildren;
	mopo=rmm;
	int pd[2];
	pipe(pd);

	while ( children < nbproc - 1 ) {
		children++;
		mopo += mpt;
		pid = fork();
		if ( !pid ){
			for(mop= mopo ; mop < (mopo+mpt) ; mop++){//
				i = (size_t) (mop/bsz[1]);
				j = (mop%bsz[1]);
				for(k=0; k<asz[0] ; k++){
					ab[i*asz[1]+j] += a[i*asz[1]+k] * b[k*bsz[1]+j] ;
				}
				if( DEBUG ) printf("#DEBUG: child %zu : ab(%zu,%zu)=%.4f\n",children,i,j,ab[i*asz[1]+j]);
			}
			(*fchildren_ptr)++;
		
			if( write(pd[1], fchildren_ptr, sizeof(size_t)) == -1 ){
				printf("ERROR: child %zu couldn't write to parent\n",children);
				exit(3);
			}
			//return 0;
			exit(0);
		}
	}
	if( DEBUG ) printf("#DEBUG: Parent processing... mop[0, %zu)\n",rmm+mpt);
	for(mop=0 ; mop < rmm+mpt ; mop++){
		i = (size_t) (mop/bsz[1]);
		j = (mop%bsz[1]);
		for(k=0; k<asz[0] ; k++)
			ab[i*asz[1]+j] += a[i*asz[1]+k] * b[k*bsz[1]+j] ;
		if( DEBUG ) printf("#DEBUG: parent : ab(%zu,%zu)=%.4f\n",i,j,ab[i*asz[1]+j]);
	}
	
	struct timespec timeout;
	timeout.tv_sec = 1;
	timeout.tv_nsec = 10*1000;
	
	while( fchildren< nbproc-1 ){
		if( DEBUG ) printf("#DEBUG: checking... %zu(%zu) children finished\n",fchildren,nbproc-1);
		nanosleep(&timeout,NULL);
		if( read(pd[0],&children,sizeof(size_t)) == -1 ){
			printf("ERROR: parent :  reading pipe \n");
			exit(4);
		}
		fchildren += children; 
	}
	if( DEBUG ) printf("#DEBUG: %zu(%zu) children finished\n",fchildren,nbproc-1);
	return ab;
}
double* mtxsq_thr(double* m, const size_t msz[2], size_t nbproc){
	return mtxm_thr(m,msz,m,msz,nbproc);
}

