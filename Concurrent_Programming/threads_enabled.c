#include <stdio.h>

#ifdef STC_NO_THREADS
#define ENABLED "NO"
#else 
#ifndef STC_NO_THREADS
#define ENABLED "YES"
#else 
#define ENABLED "unknown"
#endif
#endif

int main(){
	printf("Threads enabled:%s\n",ENABLED);
	return 0;
}
