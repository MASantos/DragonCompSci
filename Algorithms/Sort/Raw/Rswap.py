
def rSwap(ar):
	"""
	INSERTION SORT
	Here we call it r(ecursive) swapping as it is how we implement it
	"""
	n = len(ar)
	if n < 2: return ar
	else:
		ar = rSwap(ar[:n-1]) + [ ar[n-1] ]
		i = n-1
		flip = True # we need the loop to go once: simulate a do-while loop
		while i >0 and flip :
			flip = False # detect when a flip happened
			if ar[ i ] < ar[ i - 1 ]:
				tmp = ar[ i-1 ]
				ar[ i-1 ] = ar[ i]
				ar[ i ] = tmp
				i = i -1
				flip = True
		return ar



r = [87, -3, 1, 6, -17, 3, 2, 1,7]
#Test
import math
from random import random
N=1000 # Check time N=200 -> N=400 => time -> ~ 2*time. But too much recursion for N=1000 ! BOMB!!!
i=0
r=[]
while i< N:
        sc = math.floor(100*random()+0.5)
        r += [ sc * random() ]
        i += 1

print("Sorting "+str(r) )
print( rSwap(r) )
