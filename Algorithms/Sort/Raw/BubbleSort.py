from random import random
import math

def bubbleSort(A):
	"""
	Bubble Sort
	Sweep array comparing each element againts its neighbor on the right.
	Swap them if the latter is smaller.
	Repeat until previous is done w/o any swap.

	Begin
	 n <-- len(A)
	 swapped <-- True
	 while swapped
		swapped <-- False
	 	for i <-- 0 TO n-2
		  if A[i] > A[i+1] then
			Swap A[i], A[i+1]
			swapped <-- True
	End
	"""
	n = len(A)
	swapped = True
	while swapped :
		swapped = False
		for i in range(0,n-1):
			if A[i] > A[i+1]:
				tmp = A[i+1]
				A[i+1] = A[i]
				A[i] = tmp
				swapped = True

def badSelectionSort(A):
	"""
	This algorithm looks similar, but it's not bubble sort:

	Given the list of #s
	  R1, R2, ..., Ri, Ri+1, ...,Rj, Rj+1, ..., Rn
	consider an arbitrary position i. We'll compare the
	following positions against this one.

	For a pos. j>i, if Rj < Ri, swap values. Increase j; repeat comparison.
	This will put the smallest number between i and n in position i.

	Repeat for all i.

	Thus, this is NOT BUBBLE SORT, but a bad O(n^2) implementation of Selection sort!
	"""
	l = len(A)
	i=0 ; j=0 ; tmp=A[0] 
	while i < l:
		j = i+1 
		while j<l:
			if A[j] < A[i]:
				tmp = A[i]
				A[i]= A[j]
				A[j]= tmp
			j +=1
		i += 1


#r = [87, -3, 1, 6, -17, 3, 2, 1,7]
#r = [2,2,2,2,2,2]
#r = r +r
N=4000 # Check time N=2k -> N=4k => time -> ~ 4*time
i=0
r=[]
while i< N:
	sc = math.floor(100*random()+0.5)	
	r += [ sc * random() ]
	i += 1

"""
print("Sorting "+str(r) )
print( bubbleSort(r) )
print("Original array now: "+str(r) )
"""
bubbleSort(r)

