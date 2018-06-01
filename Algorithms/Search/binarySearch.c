/*
Idea: Compare to the middle value. Choose half that may contain it. Repeat till found or till interval is 1 single element

Detail:  Assume there are n numbers 
Induction hypothesis: We can find x among arrays of sizes n/2, n/4, n/8,..., n/2^k for all k such that 2^k <= n.

Reduction step: Compare x to entry n/2. 
		if x is equal, we are done
                If x larger, repeat steps in right half; if smaller, repeat in the left half.  (By hypothesis, we can do that)

Base case(s): If size(array) = 0 => not found
              if size(array) = 1 => either found or not found
   
Pseudo-Code:

Algorithm: binarySearch(A, x)
Input: A ( sorted array of numbers), x (number to search for)
Output: i ( index of x in A)


Begin binarySearch(x, A):

     n = len(A)

     return find(x,A,0,n-1)
END binarySearch

Algorithm: find(x,A,l,r)
Input: x (# to search fo)
       A (sorted array of numbers)
       l (lef/lower index of search interval)
       r (right/upper index of search interval )
Output: i (index of x in A if found; else -1)

BEGIN find(x,A,l,r):

   middle = ceiling(l+r/2)
   
   if l == r and x != A[middle] return -1 //not found

   if x == A[middle] return middle
   else
       if x > A[middle] return find(x,A,middle,r)
       else return find(x,A,l,middle)   
END find(x,A,0,n)
*/

#include<stdio.h>

size_t ffind(float , float* , size_t , size_t );

size_t fbinarySearch(float x, float* A, size_t n){
	return ffind(x, A,0,n-1);
}

size_t ffind(float x, float* A, size_t l, size_t r){
	size_t middle;
	middle = (l+r)/2.0+0.5 ;
	printf("DEBUG: %lu  %lu  %lu\n",l,middle,r);
	if ( l == r && x != A[middle] ) return -1;
	
	if ( x == A[middle] ) return middle;
	else {
		if ( x > A[middle] ) return ffind(x,A,middle,r);
		else return ffind(x,A,l,middle);
	}
}


int main(){
	//Test
	float r[8] = {-30,-3, 0, 2, 47, 173, 1648, 22866};
	float item = 173;
	size_t idx,i;
	idx =  fbinarySearch(item,r,8) ;
	printf("Search for/in %f ",item);
	printf(" r = [ ");
	i = 0;
	for( ; i < 8-1 ; i++) printf("%f, ",r[i]);
	printf("%f ]\n",r[i]);
	printf("%lu  %f\n",idx,r[idx]);
	return 0;
}
