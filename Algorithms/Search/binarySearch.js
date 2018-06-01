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

function binarySearch(x,A){
	n = A.length
	return find(x,A,0,n-1)
}

function find(x,A,l,r){
	middle = Math.ceil((l+r)/2)
	console.log("DEBUG: ",l,middle,r)
	if ( l == r && x != A[middle] ) return -1
	
	if ( x == A[middle] ) return middle
	else {
		if ( x > A[middle] ) return find(x,A,middle,r)
		else return find(x,A,l,middle)
	}
}


//Test
var r = [-30,-3, 0, 2, 47, 173, 1648, 22866]
var item = 173
var idx =  binarySearch(item,r) 
console.log("Search for/in ",item,r)
console.log(idx,r[idx])
