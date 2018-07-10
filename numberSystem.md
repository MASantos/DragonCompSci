# Number Systems
Class notes

## Decimal or Base 10 system

$1372 = 1*10^3 + 3*10^2 + 7*10^1 + 2*10^0$

## Algorithm for determining the digits in the decimal system
We divide repeatedly by the base, 10, and collect the remainder
until the integer division is zero.

\begin{eqnarray*}
1372 \% 10 &=& 2 \; \mbox{integer divsion = }\,137\\
  137  \% 10 &=& 7 \; \mbox{integer divsion = }\,13\\
   13  \% 10 &=& 3 \; \mbox{integer divsion = }\,1\\
    1  \% 10 &=& 1 \; \mbox{integer divsion = }\,0
\end{eqnarray*}

The successive remainders are exactly the digits in this number system.

## Binary or Base 2 system
Digits only $0$ or $1$.

Example: b\\$1\,0101\,1101\,=\,1 * 256+ 1 * 64+ 1 * 16+ 1 * 8+ 1 * 4+ 1 * 1\,=\,349$

We can obtain those binary digits by the same algorithm as above: 
repeatedly divide by 2 and collect the remainders.

\begin{eqnarray*}
349 \% 2 &=& 1 \; \mbox{integer divsion = }\,174 \\
  174 \% 2 &=& 0 \; \mbox{integer divsion = }\,87 \\
   87 \% 2 &=& 1 \; \mbox{integer divsion = }\,43 \\
   43 \% 2 &=& 1 \; \mbox{integer divsion = }\,21 \\
   21 \% 2 &=& 1 \; \mbox{integer divsion = }\,10 \\
   10 \% 2 &=& 0 \; \mbox{integer divsion = }\,5 \\
    5 \% 2 &=& 1 \; \mbox{integer divsion = }\,2 \\
    2 \% 2 &=& 0 \; \mbox{integer divsion = }\,1 \\
    1 \% 2 &=& 1 \; \mbox{integer divsion = }\,0
\end{eqnarray*}
and again the digits of $349$  in the binary system are just the successive remainders when
repeatedly dividing by 2.

Example: Write the decimal number 57 in binary using the algorithm.

\begin{eqnarray*}
  57 \% 2 &=& 1 \; \mbox{integer divsion = }\,28 \\
  28 \% 2 &=& 0 \; \mbox{integer divsion = }\,14 \\
  14 \% 2 &=& 0 \; \mbox{integer divsion = }\,7 \\
   7 \% 2 &=& 1 \; \mbox{integer divsion = }\,3 \\
   3 \% 2 &=& 1 \; \mbox{integer divsion = }\,1 \\
   1 \% 2 &=& 1 \; \mbox{integer divsion = }\,0
\end{eqnarray*}

and the answer is $57\,=\,b\backslash 0011\,1001$ where we follow the notation rule by which
we group every four binary digits and add 0s on the left if needed in order to complete 
a group of four bits.

## Babylonian or Base 60 or Sexagesimal System

Digits: $0\,1\,2\,\dots\,59$

A sexagesimal 4-digit-long number $\alpha\beta\gamma\delta$ is written here as $\alpha\;\beta\;\gamma\;\delta$, that is we leave a space between each digit.

Example: s\\21 = Decimal ? Answer: 21

Example: s\\54 = Decimal ? Answer: 54

Example: s\\02 01 $= 2*60^1 + 1*60^0 = 121$

Example: s\\07  11 $= 7*60^1 + 11*60^0 = 431$

More examples:

   * s\\01 23 08 03 $= 1*60^3 + 23*60^2 + 8*60^1 + 3*60^0 = 299283$ 
   * s\\17 17 $= 17*60^7 + 17*60^0 = 1037$ 

### Assignment (Due Tue. Sep. 12th 2017)

A. Write the following sexagesimal numbers in the decimal system:

   1. s\\07 $= 7$
   1. s\\37
   3. s\\51
   2. s\\01 00
   3. s\\01 01
   4. s\\01 02

B. Expand the following sexagesimal numbers in base 10 and evaluate the result:

   1. s\\08 00
   1. s\\01 00 00
   1. s\\01 00 00 00
   1. s\\37 00
   2. s\\50 00
   3. s\\51 00 00
   4. s\\52 00 00 00

C. Expand the following sexagesimal numbers in base 10 and evaluate the result:

   1. s\\01 08 16
   2. s\\11 22 40
   3. s\\18 12 16
   4. s\\13 33 53
   5. s\\15 50 05

D. (Advanced) Can you guess the expression in Base 60 of the following decimal numbers? 

   1.  4096
   2. 65536
   3. 57005
   4. 48813
   5. 6302715408

E. Answer the following questions:

   1. What is the largest power of 60 that is still smaller than 4096? 
   1. Take the remainder of dividing 4096 by the power you just found. What is the largest power of 60 that is still smaller than this remainder? 
   1. Compare the previous calculations to your answers to the first three questions. Can you see how this relates to the answer of questions D?

## Hexadecimal or Base 16

Digits: 0, 1, 2,...,15 but we use letters for the last 6 digits. Hence,
        0, 1, 2,...,9, A, B, C, D, E, F.

Example: x\\7D = Decimal ? Answer: $7*16^1 + 13*16^0 = 125$

Example: x\\12345 = Decimal ? Answer: $1*16^4 + 2*16^3 + 3*16^2 + 4*16^1 + 5*16^0 = 65536 + 2*4096 + 3*256 + 4*16 + 5*1 = 74565$


## Binary or Base 2

Digits: 0, 1. Each digit in the binary representation is a called a **bit**.

Often in the binary representation of a number we may insert a space between each pair of groups of 4 digits to easy the conversion to hexadecimal system.

Examples: 

   * b\\1 = Decimal? Answer: 1
   * b\\10 = Decimal? Answer: 2
   * b\\11 = Decimal? Answer: 3
   * b\\100 = Decimal? Answer: 4
   * b\\1000 = Decimal? Answer: 8
   * b\\1110 = Decimal? Answer: 14
   * b\\1111 = Decimal? Answer: 15
   * b\\0111 1101 = Decimal? Answer: $1*2^6 + 1*2^5 + 1*2^4 + 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0 = 125$


Example: We saw for the hexadecimal representation that x\\12345 = Decimal ? Answer: 1*16^4 + 2*16^3 + 3*16^2 + 4*16^1 + 5*16^0 = 65536 + 2*4096 + 3*256 + 4*16 + 5*1 = 74565. Rewriting each power as a power of 2, we obtain 
$$1*2^16 + 2*2^12 + 3*2^8 + 4*2^4 + 5*2^0$$

## Conversion between the binary and hexadecimal representations
Converting a ***binary*** number ***into*** a ***hexadecimal*** representation is very easy. The steps are:

1. Divide the binary representation into groups of four bits. E.g.: $b\backslash 1101011100101110=s\backslash 1101\,0111\,0010\,1110$
2. Convert each group of four bits into hexadecimal independently. E.g.: $x\backslash D72E$

Converting a ***hexadecimal*** number ***into*** a ***binary*** representation is very easy. The steps are:

1. Convert each each hexadecimal digit independently. E.g.: $x\backslash BEEF=b\backslash 1011\,1110\,1110\,1111$ 

## Quick Review of the rules of powers

A *power* is a number that is expressed in the form $b^e$. 

For example, $16^4=16*16*16*16$. 
In the different base systems, this number is written as d\\65536 = s\\18 12 16 = x\\10000 = b\\1 0000 0000 0000 0000. 

The number $b$ is called the *base* of the power; the number $e$, the *exponent* of the power. In the power $16^4$ the base is 16 and the exponent is 4.

   i. *The power of zero is 1*, that is, any number raised to the power of $0$ is defined to be equal to $1$.
      * Example: $\mathbf{1} \,=\,575^0\,=\,137^0\,=\,17364613643947.287388^0 = \mathbf{1}$

   i. *Product of powers of the same base*: Gives a power with that same base, and the exponent, the sum of the exponents 
    $$b^x\,b^y\,=\,b^{x+y}$$
      * Example: $5^7*5^8\,=\,5^{15}$

   i. *Quotient of powers of the same base*: Gives a power with that same base, and the exponent, the exponent of the numerators minus that of the denominator. $$\frac{b^x}{b^y}\,=\,b^{x-y}$$
      * Example: $\frac{5^7}{5^8}\,=\,\frac{1}{5}\,=\,5^{-1}$
      * Example: $\frac{5^7}{5^{10}}\,=\,\frac{1}{5^3}\,=\,5^{-3}$
   i. *Power of a power*: Gives a power with the same base and the exponent, the product of the exponents
        $$ (b^x)^y\,=\,b^{x\cdot y}$$
      * Example: $({5^7})^5\,=\,5^{7\cdot 5}\,=\,5^{35}$

## Fractional Numbers

 (HW G10: Read and guess .5 .25 .125 in binary)

The digits to the right of the ***radix point*** (i.e., the "fraction point" or *decimal* point) denote powers of the base of negative exponent:

A. In the decimal system:

   * d\\0.7 = $\frac{7}{10}\,=\,7*10^{-1}$
   * d\\0.07 = $\frac{7}{10^2}\,=\,7*10^{-2}$
   * d\\0.007 = $\frac{7}{10^3}\,=\,7*10^{-3}$
   * d\\137.259 =
            $$=\,1\cdot 10^2 + 3\cdot 10^1 + 7\cdot 10^0 + \frac{2}{10^1} + \frac{5}{10^2} + \frac{9}{10^3} =$$ 
            $$=\,1\cdot 10^2 + 3\cdot 10^1 + 7\cdot 10^0 + 2\cdot 10^{-1} + 5\cdot 10^{-2} + 9\cdot 10^{-3}$$

A. In the binary system:

   * d\\0.1 = $\frac{1}{2}\,=\,1*2^{-1}$
   * d\\0.01 = $\frac{1}{2^2}\,=\,1*2^{-2}$
   * d\\0.001 = $\frac{1}{2^3}\,=\,1*2^{-3}$

### Problems of representing fractionary numbers in different base systems

Any integer can be represented exactly in any number system. Ex:  d\\65536 = s\\18 12 16 = x\\10000 = b\\1 0000 0000 0000 0000. 

However, in general, fractionary numbers can only be represented *exactly **in some base systems, but not in all**.* 

Examples:

   * $\frac{1}{3}$: It cannot be expressed exactly in the decimal system (d\\$0.333333\dots$), the binary system (b\\$0.010101\dots$), nor the hexadecimal system (x\\$0.555555\dots$). As you can see the fraction $1/3$ requires *infinite* digits after the dot when we try to represent them in the binary, decimal or hexadecimal system. As **we can never write an infinite string of digits**, any attempt to represent the fraction in either of these systems must necessarily be truncated up to say 6 digits, or 11, or even one million digits after the dot, but then we stop. Hence, **they become an inexact representation of 1/3**!

       However, it can be represented exactly in the sexagesimal (babylonian) system as s\\$0.20\;00$ where the 20 represents the first digit after the *decimal* point. 

       Indeed, $20/60 = 2/6 = 1/3$. Hence we require only one digit after the dot in the sexagesimal system.

### Exact fractionary numbers
Let's list first the patterns of exact fractions for each number system:

   * **Exact fractionary numbers in the binary system**: These have all one of the two following forms
     1. **$\frac{a}{2^e}$**: For instance, $\frac{1}{2}=b\backslash 0.1,\;\frac{1}{4}=b\backslash 0.01,\;\frac{1}{8}=b\backslash 0.001,\;\frac{1}{16}=b\backslash 0.0001$, etc. and multiples of these, like e.g., $\frac{7}{4}=b\backslash 1.11$
     3. **Products of any of those cases**: For instance, $\frac{7}{4} \frac{1}{2}=\frac{7}{8}=b\backslash 0.111$, or $\frac{11}{64} \frac{5}{16}=\frac{55}{1024}=b\backslash 0.11$
   * **Exact fractionary numbers in the hexadecimal system**: These have all one of the two following forms
     1. **$\frac{a}{2^e}$**: For instance, $\frac{1}{2}=\frac{8}{16}=x\backslash 0.8,\;\frac{1}{4}=\frac{4}{16}=x\backslash 0.4,\;\frac{1}{8}=x\backslash 0.2,\;\frac{1}{16}=x\backslash 0.1$, etc. and multiples of these, like e.g., $\frac{7}{4}=\frac{28}{16}=\frac{16+12}{16}=x\backslash 1.C$
     3. **Products of any of those cases**: For instance, $\frac{7}{4} \frac{1}{2}=\frac{7}{8}=\frac{14}{16}=x\backslash 0.E$, or $\frac{11}{64} \frac{5}{16}=\frac{55}{4*16^2}=\frac{220}{16^3}=\frac{13\cdot 16^1+12\cdot 16^0}{16^3}=\frac{13}{16^2}+\frac{12}{16^3}=x\backslash 0.0D0 + x\backslash 0.00C = x\backslash 0.0DC$
   * **Exact fractionary numbers in the decimal system**: These have all the three following forms
     1. **$\frac{a}{2^e}$**: For instance, $\frac{1}{2}=d\backslash 0.5,\;\frac{1}{4}=d\backslash 0.25,\;\frac{1}{8}=d\backslash 0.125,\;\frac{1}{16}=d\backslash 0.06125$, etc. and multiples of these, like e.g., $\frac{7}{4}=d\backslash 1.75$
     2. **$\frac{a}{5^e}$**: For instance, $\frac{1}{5}=d\backslash 0.2,\;\frac{1}{25}=d\backslash 0.04,\;\frac{1}{125}=d\backslash 0.008,\;\frac{1}{625}=d\backslash 0.0016$, etc. and multiples of these, like e.g., $\frac{3}{5}=d\backslash 0.6$
     3. **Products of any of those first two cases**: For instance, $\frac{7}{4} \frac{3}{5}=\frac{21}{20}=d\backslash 1.05$, or $\frac{11}{64} \frac{16}{25}=\frac{11}{100}=d\backslash 0.11$
   * **Exact fractionary numbers in the sexagesimal system**: These have all the four following forms
     1. **$\frac{a}{2^e}$**: For instance, $\frac{1}{2}=\frac{30}{60}=s\backslash 0.30\;00,\;\frac{1}{4}=\frac{15}{60}=s\backslash 0.15\;00,\;\frac{1}{8}=\frac{450}{3600}=\frac{7}{60^1}+\frac{30}{60^2}=s\backslash 0.7\;30,\;\frac{1}{16}=\frac{225}{60^2}=\frac{3\cdot 60+45}{60^2}=s\backslash 0.3\;45$, etc. and multiples of these, like e.g., $\frac{7}{4}=s\backslash 1.45$
     1. **$\frac{a}{3^e}$**: For instance, $\frac{1}{3}=s\backslash 0.20\;00,\;\frac{1}{9}=\frac{400}{60^2}=\frac{6\cdot 60+40}{60^2}=s\backslash 0.6\;40,\;\frac{1}{27}=s\backslash 0.6\;40 * 0.20 = s\backslash 20 * 0.0\;06\;40 = 0.02\;13\;20 ,\;\frac{1}{81}=s\backslash 0.00\;44\;26\;40$, etc. and multiples of these, like e.g., $\frac{7}{4}=s\backslash 1.75$
     2. **$\frac{a}{5^e}$**: For instance, $\frac{1}{5}=\frac{12}{60}=s\backslash 0.12\;00,\;\frac{1}{25}=s\backslash 0.02\;24,\;\frac{1}{125}=\frac{1728}{60^3}=\frac{28\cdot 60+48}{60^3}=s\backslash 0.00\;28\;48,\;\frac{1}{625}=12\cdot 0.01\cdot 1/125=s\backslash 0.00\;05\;45\;36$, etc. and multiples of these, like e.g., $\frac{3}{5}=3\cdot \frac{1}{5}=3\cdot 0.12\;00=s\backslash 0.36\;00$
     3. **Products of any of those first two cases**: For instance, $\frac{7}{4} \frac{3}{5}=\frac{21}{20}=1.45\;00\cdot 0.36\;00=36\cdot 0.01\;45=s\backslash 1.03\;00$, or $\frac{11}{64} \frac{16}{25}=\frac{11}{100}=\frac{33}{300}=s\backslash 0.11$

The general rule is as follows. 

* **In the decimal system**: The factorization of the base is $10=2\cdot 5$ and thus the *prime factors of the base* are 2 and 5. Whence the only exact fractions will be those where the denominator only has 2's and 5's as prime factors. 
    
     E.g., 1/30 won't work, because $30=2\cdot 5\cdot 3$ and the 3 is not a prime factor of 10. Hence, the representation of $1/30$ in base 10 leads to infinite decimals, which is the same as saying it can't be represented exactly in this base.
* **In the binary and hexadecimal systems**: The factorization of both bases contain *only one prime factor*, namely 2 ($2=1\cdot 2;\,16=2^4$). Whence the only exact fractions in base 2 and base 16 are those whose denominators contain only powers of 2. 

     E.g. 1/14 won't work, because $14=2\cdot 7$ and 7 is not a prime factor of neither 2 nor 16.
* **In the sexagesimal system**: The factorization of the base is $60=2^2\cdot 3\cdot 5$ and thus contains *three prime factors*, namely $2,\,3,\,5$. Whence the exact fractions are those whose denominator contain only 2's, 3's and 5's as prime factors. 

## Exercises

1. Complete the following table by filling in the numbers in the different base systems as each column header indicates. Remember, in the Babylonian (Base 60) system, we separate each digit by a blank space (e.g., $02\;30$ which is 190 in decimal system). However, we write the decimal dot as usual, namely a single dot!

   |   Binary  | Hexadecimal | Babylonian | Decimal|
   |:---------:|:-----------:|:----------:|:------:|
   | 0000 0101 |             |            |        |
   |           |  2F         |            |        |
   |           |             |  03 16     |        |
   |           |             |            | 137    |
   |           |             |  56.45     |        |


2. Perform the following two calculations in your calculator or your computer. Explain why we obtain a different result. Can it be due to a software bug?
     a) Note $3600 = 144 \cdot 25$, and thus $144/3600=1/25$. But a computer shows
        * $144/3600\,=\,1/25\, =\,0.04$
        * $144/3600\,=\,120/3600+24/3600\, = \,2/60+24/3600\, =\,0.03999999\dots$
     a) Analogously, $450/3600 = 1/8$, but a computer shows
        * $450/3600\,=\,1/8\, =\,0.125$
        * $450/3600\,=\,420/3600+30/3600\, =\,7/60+30/3600\, =\,0.124999999\dots$

3. List and evaluate in each base system three fractions that cannot be represented exactly. E.g., $1/3=d\backslash 0.333333\dots$
     a) Binary system
     a) Decimal system
     a) Hexadecimal system
     a) Sexagesimal system

4. We have seen that the binary and hexadecimal systems have only two forms of fractions that can be represented exactly; the decimal system has three forms and the sexagesimal system has four forms of fractions that can be represented exactly. Invent a number system that has
     a) five forms of fractions that can be represented exactly. What is the smallest possible base?
     a) 11 forms of fractions that can be represented exactly. What is the smallest possible base?

5. Consider the following binary number $b\backslash 0110\,1010$. 
     a) What happens if we *shift* all bits one position to the left? Evaluate both numbers and explain the change.
     a) What happens if we *shift* all bits one position to the right? Evaluate both numbers and explain the change.

6. Evaluate and explain the change: What happens when we shift each *digit* one position to the left in each of the following cases?
     a) $d\backslash 314$
     a) $x\backslash 314$
     a) $s\backslash 03\;14$

## Test (G10 Tue 19Sep2017)

1. Complete the following table by filling in the numbers in the different base systems as each column header indicates. Remember, in the Babylonian (Base 60) system, we separate each digit by a space (e.g., 02 30 which is 190 in decimal system) and add a leading zero for digits below 10. However, we write the _radix_ (decimal) dot as usual, namely a single dot!

   |   Binary  | Hexadecimal | Babylonian | Decimal|
   |:---------:|:-----------:|:----------:|:------:|
   | 110011010 |  [19A](h)      |  [06 50](h)   | [410](h)  |
   | [11101110101100](h)|  3BAC       | [04 14 36](h)| [15276](h)|
   | [10001000](h)| [88](h)  |  02 16     | [136](h)       |
   | [10001001](h)| [89](h)  | [02 17](h) | 137    |
   | [110001111000010100](h)| [31E14](h) |  56 45 08  |[204308](h)|


2. This is part of an ASCII character table. Complete the missing code in octal, decimal and hexadecimal system. 

|Char                        |Oct   |Dec   |Hex   |Char    |
|:---------------------------|:----:|:----:|:----:|:------:|
| NUL '\\0' (null character) |[100](h)|64   |40   |@|
| SOH (start of heading)     |101   |[65](h)|[41](h)|A|
| STX (start of text)        |[102](h)|66   |42   | B|
| ETX (end of text)          |[103](h) |67     |[43](h)|C|
| EOT (end of transmission)  | [...](h)|    |44   |D|
| ENQ (enquiry)              |       |    |45   |E|
| ACK (acknowledge)          |      |70     |   |F|
| BEL '\\a' (bell)           |       |71   |47   |G|
| BS  '\\b' (backspace)      |       |72   |48   |H|
| HT  '\\t' (horizontal tab) |       |73   |49   |I|
| LF  '\\n' (new line)       |       |74    |    |J|
| VT  '\\v' (vertical tab)   |       |     |4B   |K|
| FF  '\\f' (form feed)      |       |     |4C   |L|
| CR  '\\r' (carriage ret)   |  115  |      |    |M|

[Solutions are trivial as all three columns show consecutive numbers](h)


## Arithmetics of (binary) Negative integers

There are multiple ways to encode negative integers and define their arithmetics. We will see the most common one: 2's complement.

In short, we use the highest bit to represent the sign. Thus, a *signed* byte represents only up to the positive integer 127. In 2's complement,
the most negative integer is -128. 

Imaging our integers living on a line, with the zero on the center, the positive ones extending to the right and the negative ones to the left
of zero. Now glue together the both ends of the line to form a circle. On this circle, one we reach 127, if we keep adding one, we will find ourselves on
-128! And if we keep adding ones, we then go to -127, -126, etc. till we are on -3, -2, -1, ...and back to 0!

| decimal | binary |
|:-------:|:------:|
| 0      | 00000000|
| 1      | 00000001|
| 2      | 00000010|
| ...
| 126    | 01111101|
| 127    | 01111111|
|-128    | 10000000|
|-127    | 10000001|
|-126    | 10000010|
| ...
| -3 | 11111101 |
| -2 | 11111110 |
| -1 | 11111111 |


### Chaging sign of an integer

1. Invert all bits 20 = 0001 0100 -> 1110 1011
2. Add 1:   1110 1100

**Proof:** Let's prove that $1110 1100=-27$. If that is true then adding it to 27 should give us 0. It is


homework : guess -4, -27 , -53 

## Floating point arithmetic
Any fractionary (finite) number $152853.5047$ can be rewritten using only integers as

$152853.5047\,=\,0.1528535047\dot 10^6$ 

where $1528535047$ is the mantissa and 6 is the exponent. 

Thus, rewriting real numbers this way, we can store and treat them
as if they were a couple of integers: the mantissa and the exponent!


 
