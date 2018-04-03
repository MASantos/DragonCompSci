/* SELECTION SORT

We called it with the more explicit name SwapMin(imum). 
*/

function swapMin(ar){
	/*
	  Sort
	  iteratively swap mininum of remaining slice
	  Modifies original array
	*/
	var n =  ar.length
	if  ( n < 2 )  return ar
	// i absolute position of first element of slice starting at i: ar[i:]
	var i = 0
	while (true) { //do-until loop
		/*The spread operator ...[array]
			Math.min(1,2,3,-1)  ==  -1
			Math.min([1,2,3,-1])  ==  NaN
			Math.min(...[1,2,3,-1])  ==  -1
		*/
		m = Math.min( ...ar.slice(i) )
		//finds index of 1st instance of m in slice starting at i
		jm = ar.slice(i).indexOf(m) 
		tmp = ar[i]
		ar[i] = m
		//jm is position relative to slice size. Add i for absolute position in ar
		ar[jm+i]= tmp 
		console.log( "DEBUG: jm+i="+(jm+i)+" i="+i+" "+ar )
		i+=1
		if (i == n)  break
	}
	return ar
}

r = [87, -3, 1, 6, -17, 3, 2, 1,7]
//r = r.concat(r)
console.log("Sorting "+r )
console.log( swapMin(r) )
console.log("Original array now: "+r )

