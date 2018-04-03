
/*
QSORT 

Recursively partition by pivot an array between l-th and r-th elements, both included

*/

/*
Partition by pivot array A between l and r

Choose pivot A[p]. Eg. p=l

Consider i > p : If A[i] > A[p] , increment i and repeat.

Otherwise, swap A[i] w/ A[p+1] , then swap A[p+1] w/ A[p].

Increment p + 1

Repeat for all i from l+1 to r;

return p
*/
function partition(A,l,r){
	var p = l 
	var tmp = 0.0;
	//console.log("DEBUG: l:"+l+" r:"+r+" p:"+p)
	for(var i=p+1 ; i<=r ; i++){
		if (A[i] > A[p] ) continue 
		tmp = A[p+1] 
		A[p+1] = A[i]
		A[i] = tmp

		tmp = A[p+1] 
		A[p+1] = A[p]
		A[p] = tmp
			
		p++
		//console.log("DEBUG: l:"+l+" r:"+r+" p:"+p+" A:["+A+"]")
	}
	return p
}

function Qsort(A,l=0,r=A.length-1){
	if ( r<=l) return A
	var p = partition(A,l,r)
	Qsort(A,l,p-1)
	Qsort(A,p+1,r)
	return A
}


/*
var r = [87, -3, 1, 6, -17, 3, 2, 1,7]
//r = r.concat(r)
console.log("Sorting "+r )
console.log( Qsort(r) )
console.log("Original array now: "+r )
*/

var N=2000000//6000
var r = []
var i = 0
while ( i < N ){
	var sc = Math.floor( 100*Math.random() + 0.5 )
	r.push( sc * Math.random() )
	i++
}

r = Qsort(r)
var hw = 20
console.log( r.slice(0,hw),"\n", r.slice(-hw,-1) )
console.log(r.length) 
