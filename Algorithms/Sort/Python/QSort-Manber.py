
def Qsort(A):
	quicksort(A,0,len(A)-1)

def quicksort(A,lo,hi):
	if lo<hi :
		p = partition(A, lo, hi )
		quicksort(A,lo,p)
		quicksort(A,p+1,hi)

def partition(A, lo, hi):
	#ipivot = lo 
	#ipivot = lo + findMedian( A[lo: hi+1] )
	#ipivot = (lo>ipivot)*(-1)+(lo<=ipivot)*ipivot
	#print("DEBUG: pivot: "+str(ipivot)+" -> "+str(A[ipivot]))
	##swap median with first element
	#tmp = A[lo]
	#A[lo] = A[ipivot]
	#A[ipivot] = tmp
	pivot = A[lo]
	i = lo #ipivot
	j = hi
	while i<j :
		while A[i] <= pivot and i< hi: i += 1 #; print("A["+str(i)+"]="+str(A[i]))
		while A[j] > pivot and j > lo: j -= 1
		#print("DEBUG: i:"+str(i)+"  j:"+str(j) )
		if i<j : 
			tmp = A[i]
			A[i] = A[j]
			A[j] = tmp
			#print("DEBUG:         Swapped:: i:"+str(i)+"  j:"+str(j)+" => r:"+str(r) )
	middle = j
	tmp = A[lo]
	A[lo] = A[j]
	A[j] = tmp
	print("DEBUG: lo:"+str(lo)+" hi:"+str(hi)+" middle:"+str(middle)+"  A:"+str(A[middle])+" A:"+str(A) )
	return middle

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
	
	
#r = [87, -3, 1, 6, -17, 3, 2, 1,7]
r = [2,2,2,2,2,2]
#r = r +r
print("Sorting "+str(r)+"\nMedian : "+str(findMedian(r))+" :: "+str(r[findMedian(r)]) )
print( Qsort(r) )
print("Original array now: "+str(r) )
 
