'''
/* Given set N elements, generates all partitions of floor( [N+1]/2 ) blocks, i.e., each block has 2 elements or it is a singleton. Only 1 singleton per partition.
*
*  For each partition, print an array with all pairs. Leave the singleton out, if there is one.
*
*  Induction:
*  When N=1, there is none. For N=2, there is only 1 partition, namely [(1,2)]
*  Lets assume we know how to build all such partitions for N elements.
*  
*  For N+1 = 2k+1, we take the new element x* and add it to each partition of the 2k case as a singleton. We clone each partition by swapping each time x* with one of the previous N elements.
*
*             [ [(x1,x2),(x3,x4),...,(x_{2k-},x_{2k})], ... ]    ---->    [ [(x1,x2),(x3,x4),...,(x_{2k-},x_{2k}), (N,0)], ... ]
*             
*  For N+1 = 2k, we take the new element x* and pair it with the singleton of each partition of the 2k-1.
*
*  
*  PSEUDO-CODE
*
*  AllPairBlocks(N):
*  Input: N # elements
*  Output: [(x1,x2),(x3,x4),...,] , [(x1,x6),(x3,x5),...] , ...
*
*  Implicit Representation: Internally, each partition as a linear array of integers. Even number of integers. N=2k+1, last number is 0.
*
*  Begin:
*
*   if N <  2: return [ [] ]
*   if N == 2: return [ [1,2] ]
*   if N % 2 != 0:
*       list = AllPairBlocks(N-1)
*       nlist = [ [] ]
*       for p in list:
*           np = p
*           nlist.append( np.append( N,0 )
*           np = nlist[0]
*           for i =  0 to N-1:
*               nnp = swap np[i] <> N
*               nlist.append( nnp )
*       return nlist
*   else: 
*       list = AllPairBlocks(N-1)
*       for p in list:
*           p[N]=N
*       return list
*/
'''

def AllPairBlocks(N):
        if N <  2: return [ ]
        if N == 2: return [ [1,2] ]
        if N % 2 == 0:
            list = AllPairBlocks(N-1)
            for p in list:
                p[N-1] = N
            return list
        else: 
            list = AllPairBlocks(N-1)
            nlist = [ ]
            for p in list:
                np = p[:]
                np.extend( (N,0) )
                nlist.append( np )
                np = nlist[0]
                for i in range(N-1):
                    nnp = np[:]
                    tmp = np[i]
                    nnp[i] = N
                    nnp[N-1] = tmp
                    nlist.append( nnp )
            return nlist

def printAPB( lst , sizeonly=False):
    numPart = len(lst)
    if sizeonly: 
        print("Number of Partitions of with blocks of size 2: "+str(numPart) )
        return
    if numPart < 106: print("Number of Partitions of with blocks of size 2: "+str(numPart) )
    if numPart < 1 : 
        return
    N=len( lst[0] )
    if N < 2: return 
    if N == 2:
        print("[(1,2)]")
        return
    for p in lst:
        print("[",end="")
        for i in range(0,N-4,2):
            print("("+str(p[i])+","+str(p[i+1])+")",end=",")
        print("("+str(p[N-4])+","+str(p[N-3])+")",end="")
        if p[-1] != 0: print(", ("+str(p[-2])+","+str(p[-1])+")",end="")
        print("], ",end="")
    print("[]]")
    if numPart > 105: print("Number of Partitions of with blocks of size 2: "+str(numPart) )


def runLoop():
    import sys
    for line in sys.stdin:
        n=int(line.split()[0])
        printAPB( AllPairBlocks(n) ) 
        print("---")


def runOnce(sizeonly=False):
    n = int( input() )
    if not sizeonly and n < 7:
        print( AllPairBlocks(n) ) 
        print("----")
    printAPB( AllPairBlocks(n) , sizeonly) 

runOnce(True)
#runLoop()
