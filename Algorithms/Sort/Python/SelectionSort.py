def selectionSort(ar):
	"""
	  SELECTION SORT
	  iteratively swap mininum of remaining slice
	  Modifies original array (in-place method)
	"""
	n = len( ar )
	if  n < 2 : return ar
	# i absolute position of first element of slice starting at i: ar[i:]
	i = 0
	while i< n-1 :
		m = min( ar[i:] )
		#finds index of 1st instance of m in slice starting at i
		jm = ar[i:].index(m) 
		tmp = ar[i]
		ar[i] = m
		#jm is position relative to slice size. Add i for absolute position in ar
		ar[jm+i]= tmp 
		#print( "DEBUG: jm+i="+str(jm+i)+" i="+str(i)+" "+str(ar) )
		i+=1
	#return ar

def badSelectionSort(A):
	"""
	Given the list of #s
	  R1, R2, ..., Ri, Ri+1, ...,Rj, Rj+1, ..., Rn
	consider an arbitrary position i. We'll compare the
	following positions against this one.

	For a pos. j>i, if Rj < Ri, swap values. Increase j; repeat comparison.
	This will put the smallest number between i and n in position i.

	Repeat for all i.

	Thus, this is NOT BUBBLE SORT, but a bad implementation of Selection sort!
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

def amin_bare(A,i,im):
	n = len(A)
	im[0] = i
	im[1] = A[i]
	k = i+1
	f = False
	while k < n: 
		"""
		Avoiding branch prediction overhead
		if A[k] < m : 
			m=A[k]
			im = k
		"""
		f = A[k] < im[1]
		im[1] = A[k] * f + im[1] * (1-f)
		im[0] =   k  * f + im[0] * (1-f)
		k += 1
	#return [im,m]
	#print("DEBUG: min A["+str(i)+":]="+str(A[i:])+" : m="+str(im[1])+" im="+str(im[0]) )

def amin(A,i):
	n = len(A)
	im = i
	f =  A[i] <= A[n-1]  
	m = f * A[i] + (1-f) * A[n-1]
	for k in range(i+1,n-1):
		if A[k] < m:
			m = A[k]
			im = k
		"""
		This takes 4 times more than the previous if-then!!!
		f =  A[k] < m 
		m = f*A[k] + (1-f)*m 
		"""
	return [im,m]

def aminrec(A,i):
	if len(A)-i == 1: return [i,A[i]]
	[im,m] = aminrec(A,i+1) # len = 2000 => max recursion exceeded!
	r = (len(A)-i)//2
	#[im1,m1] = aminrec(A, 
	if A[i]<m:
		im = i 
		m = A[i] 

	return [im,m]
def ssort(A):
	n = len(A)
	#im = [-1,-666]
	im = 0
	m = A[im]
	#for i in range(0,n-1):
	i=-1
	while i < n-1:
		i += 1
		[im,m] = amin(A,i)
		tmp = A[i]
		A[i] = m
		A[im] = tmp
		"""
		amin_bare(A,i,im)
		tmp = A[i]
		A[i] = im[1]
		A[im[0]] = tmp
		"""

"""
r = [87, -3, 1, 6, -17, 3, 2, 1,7]
r = r #+r
"""
#Test
import math
from random import random
N=4000 # Check time N=2k -> N=4k => time -> ~ 4*time. 
i=0
r=[]
while i< N:
        sc = math.floor(100*random()+0.5)
        r += [ sc * random() ]
        i += 1

"""
print("Sorting "+str(r) )
#print( swapMin(r) )
print( ssort(r) )
print("Original array now: "+str(r) )
"""
#selectionSort(r)
ssort(r)
