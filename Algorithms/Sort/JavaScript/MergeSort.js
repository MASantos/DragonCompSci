/*MERGE SORT
IH: Assume array size n = 2^k and that we know how to sort up to k.

Let's consider k+1 (=> n -> 2n ). Split in two halfs a1, a2 & sort each.
Now merge(a1,a2): 
 assume a1[0] < a2[0]
 merge =  [ a1[0] ] ++ merge( a1[1:], a2)

Base case: k=1... Works!

But, how does it work for n=3 or k=2? =>  Need to split all the way down!
Whence, merge ("conquer") needs to be separated from split ("divide")

Algorithm: mergeSort(A)
Input: A (array size n)
Output: new array w/ sorted elements of A

Begin
 n <-- len(A)
 if n <= 1 then return A
 a1 = mergeSort( A[:n//2] )
 a2 = mergeSort( A[n//2:] )

 if a1[0] <= a2[0] then
	return [a1[0] ] ++ mergeSort(a1[1:n//2],a2)
 else
	return [a2[0] ] ++ mergeSort(a1,a2[n//2+1:] )
End
*/

function MergeSort(A){
	var n = A.length
	if ( n <= 1 ) return A
	var n2 = Math.floor( n/2 ) 
	var a1 = MergeSort( A.slice(0,n2) )
	var a2 = MergeSort( A.slice(n2) )
	return merge(a1,a2)
	/* DEBUG
	ma= merge(a1,a2)
	console.log("DEBUG: A=["+A+"] => merge: ["+ma+"]")
	return ma
	*/
}

function merge(a1,a2) {
	var n1 = a1.length
	var n2 = a2.length
	var i = 0 ; var j = 0 
	var ma = []
	var t = true
	while ( i < n1 && j < n2 ) {
		t =  a1[i] <= a2[j]
		ma.push( a1[i]*t+a2[j]*(1-t)  )
		i += 1*t
		j += 1*(1-t)
	}
	if ( i == n1 && j < n2 ) ma = ma.concat(a2.slice(j) )
	if ( i < n1 && j == n2 ) ma = ma.concat(a1.slice(i) )
	return ma
}

function mergeRec(a1,a2){
	if (a1.length == 0 ) return a2
	if (a2.length == 0 ) return a1
	if ( a1[0] <= a2[0] ) return [a1[0]].concat( merge(a1.slice(1), a2) )
	else                  return [a2[0]].concat( merge(a1, a2.slice(1)) )
}

/*
var r = [87, -3, 1, 6, -17, 3, 2, 1,7]
//r = r.concat(r)
console.log("Sorting ["+r+"]" )
console.log( MergeSort(r) )
console.log("Original array now: ["+r+"]" )
*/

var N=12800000// stack exhausted by N=16k at mergeRec(a1,a2)
var r = []
var i = 0
while ( i < N ){
        var sc = Math.floor( 100*Math.random() + 0.5 )
        r.push( sc * Math.random() )
        i++
}

r = MergeSort(r)
/*
var hw = 20
console.log( r.slice(0,hw),"\n", r.slice(-hw,-1) )
console.log(r.length)
*/

