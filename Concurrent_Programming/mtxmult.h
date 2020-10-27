#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void pmtx(double* m, size_t rs, size_t cs,char* txt){
	if( rs*cs <= 0 ) {
		fprintf(stderr,"Warning: ill-defined matrix dimensions\n");
		return;
	}
	if( txt ) printf("%s\n",txt);
	size_t i,j ;
	for(i=0 ; i<rs ; i++){
		for(j=0 ; j<cs ; j++){
			printf("%.4f\t",m[i*cs+j]);
			if( j == 10) {
				j = cs;
				printf("...");
			}
		}
		printf("\n");
		if( i == 10){
			i = rs;
			printf("...\n");
		}
	}
}

double* mtxm(double* a,const size_t asz[2],double* b,const size_t bsz[2]){
	if ( asz[1] != bsz[0] ){
		printf("ERROR: can't multiply A*B: columns of A %zu != rows of b%zu\n",asz[1],bsz[0]);
		exit(1);	
	}
	double* ab = calloc(asz[0]*bsz[1],sizeof(double));
	if( !ab ){
		printf("ERROR: Couldn't allocate memory for matrix multiplication");
		exit(2);
	}
	size_t i,j,k;
	for(i=0 ; i<asz[0] ; i++){
		for(j=0 ; j<bsz[1] ; j++)
			for(k=0; k<asz[0] ; k++)
				ab[i*asz[1]+j] += a[i*asz[1]+k] * b[k*bsz[1]+j] ;
	}
	return ab;
}
double* mtxsq(double* m, const size_t msz[2]){
	return mtxm(m,msz,m,msz);
}

