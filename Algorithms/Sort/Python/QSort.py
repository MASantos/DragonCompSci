
def Qsort(A,l=0,r=-1):
	"""
	Recursively partition by pivot into left and right blocks.
	"""
	if r == -1 and l == 0 : r = len(A)-1
	print("DEBUG: QS Bef. P: l="+str(l)+" r="+str(r)+"  A="+str(A), end="\t" )
	if r > l:
		p = partitionRec(A,l, r)
		print("DEBUG: QS Aft. P: p="+str(p)+" A["+str(p)+"]="+str(A[p]) )
		Qsort(A,l,p-1)
		Qsort(A,p+1,r)

def partition(A,l,r):
	"""
	Idea:  Partition by pivot
	Partition array A between l-th and r-th elements (both included) using a given value as the "pivot".
	That is, once done, all elements < pivot, will be on left of pivot; all > pivot, on its right.

	Choose as pivot A[p] with p=0, i.e., the first element of array.

	Given a pivot A[p], consider a value at p<i<r. If A[i]>A[p], check next i. 

	Otherwise, swap A[i] w/ A[p+1], then swap A[p] w/ A[p+1]. Effectively, this will put
	the original A[i] on the left of the pivot A[p], which has moved one to the right to
	accommodate A[i]. The original value on the right of A[p] is moved to where A[i] was.

                                        If  A[i] <= A[p] then

	Initiallly:        A[0] ... A[p-1] A[p] A[p+1] ... A[i]   ... A[N-1]
                                             ^              ^^
	After 1st swap:    A[0] ... A[p-1] A[p] A[i]  ...  A[p+1] ... A[N-1]
                                             ^   ^^
	After 2nd swap:    A[0] ... A[p-1] A[i] A[p]  ...  A[p+1] ... A[N-1]
                                            ^^    ^

	Increment p by 1.
	Repeat for all i from p+1 to r. 

	Return index of pivot: p

	Base case, 2 elements. Ok (although one superfluous swap)
	"""
	# From here on it will be r >= l + 1
	if r <= l : return l
	# p is the pivot
	p = l
	i=p+1
	while i<=r :
		if A[i] > A[p] : i += 1
		else :
			#if p < i-1:
			tmp = A[p+1]
			A[p+1] = A[i]
			A[i] = tmp
				
			tmp = A[p+1]
			A[p+1] = A[p]
			A[p] = tmp
			p += 1
			i += 1
	return p
		

def partitionRec(A,l,r):
	"""
	Recursively partitioning exhausts the heap very quickly, i.e., even for very small arrays

	Whence, we must unfold this recursive version into one using a well-determined loop over the array.
	"""
	print("DEBUG: P-range l:"+str(l)+" r:"+str(r))
	if r <= l : return r+1

	p = partitionRec(A,l,r-1)
	# p == r-1 + 1  if no swap was done

	print("DEBUG: swapping p:"+str(p)+" r:"+str(r))
	#new pivot
	np = r+1
	if A[p] < A[r] or p == r : return np
	if p < r -1: 
		tmp = A[p+1]
		A[p+1] = A[r]
		A[r] = tmp

	tmp = A[p+1]
	A[p+1] = A[p]
	A[p] = tmp
	
	np = p+1
	return np

#r = [87, -3, 1, 6, -17, 3, 2, 1,7]
#r = [87, -3,1,6]
r = [1,6]
#r = [87, -3, 1, 6, -17, 3, 2, 7]
#r = [2,2,2,2,2,2]
#r = r +r

"""
from random import random
import math

N=8000 # Check time N=2k -> N=4k => time -> < 4*time
i=0
r=[]
while i< N:
        sc = math.floor(100*random()+0.5)
        r += [ sc * random() ]
        i += 1
"""

print("Sorting "+str(r) )
Qsort(r)
print("Original array now: "+str(r) )
"""
Qsort(r)
"""

