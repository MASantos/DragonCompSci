# Computer Science G12

# Test 2 Term 3

Date: \today

## Name:


Each question emphasizes on different skills: (K) Knowledge, (T) Thinking, (C) Communication and (A) Application.

The value of each problem is as follows: P1 20% , P2 40%, P3 30% and P4 10%.

1. (20% KTC) Prove that $Q_n=\sum^n_{k=1}\frac{1}{2^k}\,=\,\frac{1}{2}+\frac{1}{4}+\frac{1}{8}+\dots +\frac{1}{2^n}\,<\,1$ by way of finding a closed expression for $Q_n$.
   Make sure that your reasoning is clear.

     **Answer**: $Q_n\,=\,2\,Q_n\,-\,Q_n\,=\,1\,-\,\frac{1}{2^n}$. Whence, as it is always that $(1/2)^n\,>\,0$, and therefore $1-1/2^n<1$, 
     we conclude that it will always be $Q_n\,<\,1\quad\Box$
2. (40% KTC) The gist of the **insertion sort**  algorithm consists in building a sorted list of number by inserting each of them one by one in the right position. 
   Say, the list of numbers $R_1,\,R_2,\,R_3,\,\dots \,R_n\,R_{n+1}$ is such that the first $n$ of them are already sorted. How can we sort the full list?
   
       1. Sketch a reasoning of how to sort the full list using PMI and proving it is correct. 
       2. Write a pseudo-code for this algorithm 
 
     **Answer**: See course notes.
     
3. (30% KCA) Calculate the closed form of the following sums and prove your result by mathematical induction. Hint: Use the method of shifting and 
   the well-known result $S_n=\sum^n_{k=1}k=n\dot (n+1)/2$

       1. $S2_n\,=\,\sum^n_{k=0}k^2$ 

         **Answer**: Consider the sum $S3_n=\sum^n_{k=1}k^3$. It is $n^3\,=\,S3_n\,-\,S3_{n-1}\,=\,\sum^n_{k=1}\{k^3\,-\,(k-1)^3\}$. Expanding the last expression
         we have $n^3\,=\,3\,S2_n\,-\,3\,S_n\,+\,n$. Isolating $S2_n$ from here and simplifying we arrive at the solution $S2_n\,=\,n\,(n+1)\,(2n+1)/6$

         Let's prove this result by mathematical induction. 

         **Base case**: It works for $n=1$. Indeed, by definition $S2_1=1$, and the expression we obtained evaluates to $1\dot (1+1)\dot (2\dot 1+1)/6=1$. Check!
        
         **Induction step**: Let's assume it works for a given $n$. Let's show that we can then prove it also works for $n+1$. Indeed, for $n+1$ it is 
         by definition $S2_{n+1}\,=\,S2_n\,+\,(n+1)^2$. Using the assumption, we can rewrite the right-hand side as $n\,(n+1)\,(2n+1)/6\,+\,(n+1)^2$. Simplifying
         this leads to the result that $S2_{n+1}\,=\,(n+1)\,(n+2)\,(2n+3)/6\quad\Box$
       2. $S3_n\,=\,\sum^n_{k=0}k^3$ 

         **Answer**: Consider the sum $S4_n=\sum^n_{k=1}k^4$. It is $n^4\,=\,S4_n\,-\,S4_{n-1}\,=\,\sum^n_{k=1}\{k^4\,-\,(k-1)^4\}$. Expanding the last expression
         we have $n^4\,=\,4\,S3_n\,-\,6\,S2_n\,+\,4\,S_n\,-\,n$. Isolating $S3_n$ from here and simplifying we arrive at the solution $S3_n\,=\,n^2\,(n+1)^2/4$

         The proof by PMI follows the same steps as for the previous case.

5. (10% KTC) Consider the following recurrence relation 
   $$G_n\,=\,G_{n-1}\,+\,G_{n-2}\,+\,1\quad \mbox{with}\quad G_1\,=\,1\;G_2\,=\,1$$ 
   and compare it to the Fibonacci one 
   $$F_n\,=\,F_{n-1}\,+\,F_{n-2}\quad F_1\,=\,1\quad\mbox{with}\quad F_2\,=\,1$$
   Because of the extra $1$ it seems obvious that $G_n\,>\,F_n$. Yet the following *seems* a valid proof that $G_n\,=\,F_n\,-\,1$, namely (by the strong PMI):
   Assume that $G_k\,=\,F_k\,-1\;\forall\,k\leq n$. We can then prove it holds for $n+1$ as well:
   $$G_{n+1}\,=\,G_n\,+\,G_{n-1}\,+\,1\,=\,F_n\,-1\,+\,F_{n-1}\,-\,1\,+\,1\,=\,F_{n+1}\,-\,1$$
   What is **wrong** with this proof?

     **Answer**: The base case $n=1$ does not satisfy the induction hypothesis $G_n=F_n-1$. The given argument just proves that IF that hypothesis would work
     for any given case $n^*$, THEN it would work for all cases $n>n^*$. However, it so happens that there is no case at all for which it works! Therefore
     this does not constitute a proof that $G_n=F_n-1\quad\Box$.

     Furthermore, the fact that there is a concrete case (the base case $n=1$) for which the given relation is false means that the statement 
     "*For all values of $n>0$, it is $G_n=F_n-1$*" **is actually false**. We would say that the case $n=1$ is a *counter-example* that falsifies that
     statement.
