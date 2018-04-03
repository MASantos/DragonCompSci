
/*
BUBBLE SORT : RECURSIVE
Idea: Swap the first element all the way down the array until it is no longer larger than then next one.

**Buble-sort Induction hypothesis**: Let's assume we know how to sort a list of $n$
elements.

Consider now the case of $n+1$ elements. Split the array into two parts: the first element and the
remaining $n$. By the induction hypothesis, we know how to sort the latter. We are left with making
sure the first elements gets swapped into its right position.

But this can be easily done: we just sweep the list from left to right and keep swapping that element
everytime it is larger than the next element.

**Base case**: Trivially it works for an array of size $n=1$.

Thus, using the PMI, we have found the gist of the bubble-sort algorithm: swap an element all the way
down the array until it is no longer larger than its following element.

**Pseudo-code**:
```bash
Algorithm: BubbleSort-Rec(A)
Input: A (array of numbers)
Output: A (array w/ numbers sorted in increasing order)

Begin
 n <-- len(A)
 if n <= 1 return A
 A <-- A[0] ++ BubbleSort-Rec( A[1:] )
 for i from 0 to n-2
   if A[i] > A[i+1] then swap A[i] & A[i+1]
 return A
End
```

*/
function BubbleSortRec(A){
	var n = A.length
	if ( n == 1 ) return A

	A = [ A[0] ].concat( BubbleSortRec(A.slice(1)) )

	var tmp = 0.0 
	for(var i = 0 ; i < n-1 ; i++ ){
		if ( A[i] > A[i+1] ){
			tmp = A[i+1]
			A[i+1] = A[i]
			A[i] = tmp 
		}
	}
	return A
}


/*
var r = [87, -3, 1, 6, -17, 3, 2, 1,7]
//r = r.concat(r)
console.log("Sorting ["+r+"]" )
console.log( BubbleSortRec(r) )
console.log("Original array now: ["+r+"]" )
*/

var N=8000// stack exhausted by N=16k at mergeRec(a1,a2)
var r = []
var i = 0
while ( i < N ){
        var sc = Math.floor( 100*Math.random() + 0.5 )
        r.push( sc * Math.random() )
        i++
}

r = BubbleSortRec(r)

/*
var hw = 20
console.log( r.slice(0,hw),"\n", r.slice(-hw,-1) )
console.log(r.length)
*/

