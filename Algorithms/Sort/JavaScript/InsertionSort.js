/* INSERTION SORT
Here we called it r(ecursive) Swapping as that's how we implement it
*/
function rSwap( ar ){
	var n = ar.length
	if ( n < 2 ) return ar
	//first sort the initial slice ar[0:n-1]
	ar = (rSwap(ar.slice(0,n-1)) ).concat( ar[n-1] )

	var i = n-1
	do{
		var flip = false
		if( ar[i] < ar[i-1]){
			var tmp = ar[i-1]
			ar[i-1] = ar[i]
			ar[i] = tmp;
			flip = true
			i--
		}
	}while( i > 0 && flip)
	
	return ar
}

r = [87, -3, 1, 6, -17, 3, 2, 1,7]
console.log("Sorting ",r)
console.log(rSwap(r) )

