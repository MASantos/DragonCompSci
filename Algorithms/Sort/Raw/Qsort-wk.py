"""
algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := partition(A, lo, hi)
        quicksort(A, lo, p)
        quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
    pivot := A[lo]
    i := lo - 1
    j := hi + 1
    loop forever
        do
            i := i + 1
        while A[i] < pivot

        do
            j := j - 1
        while A[j] > pivot

        if i >= j then
            return j

        swap A[i] with A[j]
"""

def quicksort(A, lo, hi):
	if lo < hi :
			p = partition(A,lo,hi)
			quicksort(A,lo,p)
			quicksort(A,p+1,hi)

def partition(A, lo, hi):
	ipivot = lo 
	pivot = A[ipivot] 
	i = lo #ipivot
	j = hi
	while True:
		while A[i] < pivot: i += 1
		while A[j] > pivot: j -= 1
		if i>=j : return j
		tmp = A[i]
		A[i] = A[j]
		A[j] = tmp
		return i

def findMedian(ar): 
	"""
		Finds median of first, middle and last value in array ar
	"""
	im = len(ar)//2 
	a=ar[-1]
	b=ar[im]
	c=ar[0] 
	x=a-b
	y=b-c
	z=a-c
	if x*y > 0 : return im
	if x*z > 0 : return 0
	return -1
	
	
r = [87, -3, 1, 6, -17, 3, 2, 1,7]
r = r +r
print("Sorting "+str(r)+"\nMedian : "+str(findMedian(r))+" :: "+str(r[findMedian(r)]) )
print( quicksort(r,0,len(r)-1) )
print("Original array now: "+str(r) )
 
