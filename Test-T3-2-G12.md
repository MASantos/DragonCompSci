# Computer Science G12

# Test 2 Term 3

Date: \today

## Name:


Each question emphasizes different skills: (K) Knowledge, (T) Thinking, (C) Communication and (A) Application.

The value of each problem is as follows: P1 20% , P2 40%, P3 30% and P4 10%.

1. (20% KTC) Prove that $Q_n=\sum^n_{k=1}\frac{1}{2^k}\,=\,\frac{1}{2}+\frac{1}{4}+\frac{1}{8}+\dots +\frac{1}{2^n}\,<\,1$ by way of finding a closed expression for $Q_n$.
   Make sure that your reasoning is clear.
2. (40% KTC) The gist of the **insertion sort**  algorithm consists in building a sorted list of number by inserting each of them one by one in the right position. 
   Say, the list of numbers $R_1,\,R_2,\,R_3,\,\dots \,R_n\,R_{n+1}$ is such that the first $n$ of them are already sorted. How can we sort the full list?
   
       1. Write a pseudo-code for this algorithm 
       2. Explain the code's logic in your own words. Make sure to clearly show how PMI is used to guarantee the logic is correct.
3. (30% KCA) Calculate the closed form of the following sums and prove your result by mathematical induction. Hint: Use the method of shifting and 
   the well-known result $S_n=\sum^n_{k=1}k=n\dot (n+1)/2$

       1. $S2_n\,=\,\sum^n_{k=0}k^2$ 
       2. $S3_n\,=\,\sum^n_{k=0}k^3$ 

5. (10% KTC) Consider the following recurrence relation 
   $$G_n\,=\,G_{n-1}\,+\,G_{n-2}\,+\,1\quad \mbox{with}\quad G_1\,=\,1\;G_2\,=\,1$$ 
   and compare it to the Fibonacci one 
   $$F_n\,=\,F_{n-1}\,+\,F_{n-2}\quad F_1\,=\,1\quad\mbox{with}\quad F_2\,=\,1$$
   Because of the extra $1$ it seems obvious that $G_n\,>\,F_n$. Yet the following *seems* a valid proof that $G_n\,=\,F_n\,-\,1$, namely (by the strong PMI):
   Assume that $G_k\,=\,F_k\,-1\;\forall\,k\leq n$. We can then prove it holds for $n+1$ as well:
   $$G_{n+1}\,=\,G_n\,+\,G_{n-1}\,+\,1\,=\,F_n\,-1\,+\,F_{n-1}\,-\,1\,+\,1\,=\,F_{n+1}\,-\,1$$
   What is **wrong** with this proof?


