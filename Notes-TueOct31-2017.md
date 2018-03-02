# Dragon Acadmemy 2017-2018

# Computer Science G12

Remember I'm following the text I posted on [msantos.sdf.org/G12/](http://msantos.sdf.org/G12/Term1/AnIntroductionToLogic-2016-MarkVLawson.pdf) .

These notes will be updated further in the coming days and can be found on that same site, both in Markdown as well as PDF formats.

# Notes Tue 17 Oct 2017

## Boolean Algebra

### Connectives and their truth tables

And, or, not, conditional, biconditional, xor: 
$\wedge,\,\vee,\,\urcorner,\,\rightarrow,\,\leftrightarrow,\,\oplus$

Truth values: True/False, 0/1, T/$\perp$

#### Alternative notations

While symbols listed above are the ones that are common in logic, some computer science texts, or rather computer languages, may use
other symbols for them. 

* Negation: NOT p, !p, $\bar{p},\, p'$
* Conjunction: p AND q, $p\cdot q,\quad p\,q$ 
* Disjunction: p OR q, $p + q$ 

### Boolean Laws

1. Commutativity
2. Associativity
3. Distributivity
4. Idempotence
5. De Morgan Laws

# Notes of Tue Oct 31 2017. 

##  Logic riddles:

1. A, B, C either Knights (allways tell truth) or Knaves (allways lie). You ask A, but she whispers and you don't understand it. B then says: "She said she is a knave", to which C immediately replies "That's a lie". What can you say about A,B, and C being either a knight or a knave?
2. A: "Exactly one of us is a knave", B: "Exactly two of us is a knave", C: "all of us are knaves". Same question.

More on logic riddles can be found in e.g. 

* The notes I'm basing this unit on. See link above.
* The site [Knight and Knaves](https://sites.google.com/site/newheiser/knightsandknaves)
* Logicians have a peculiar sense of humor as reflected in the title of research papers like "_The Hardest Logic Puzzle Ever_" by George Boolos 
    or "_How to solve the hardest logic puzzle ever in two questions_" by Gabriel Uzquiano. (And you thought they would only be dealing with _serious stuff_, eh?)
     
    You can dig further into this topic in the corresponding [wikipedia page](https://en.wikipedia.org/wiki/The_Hardest_Logic_Puzzle_Ever). 
    Be aware though, these are tricky problems, so don't desperate if you feel at lost -that said, if you find them trivial, let me know and I tell the authors!!
 

## SAT (Boolean SATisfiability) problem:

* Example of a SAT problem: Which combination of truth values of p, q and r makes the following sentence true? ~p ^ (r ^ (q v p) )
* Easy understand complexity: Exponential complexity. Unsolved general case. P !=? NP

## Propositional Logic as a formal system/language

We  will describe again here what we have seen on propositional logic, but his time we will consider the topic as a _(formal) language_. 

In more general terms, a language is an example of what's called a _formal system_. Other examples of formal systems are for instance, any _axiomatic system_, 
e.g., Euclid's geometry could arguably be considered the first axiomatic/formal system we know of.

One distinguishes two parts when formally stating what propositional logic, and by extension, any (formal) language, is: Its **syntax** and its **semantics**.

Note: What does the word semantic mean? where does it come from? Semantics comes from greek $\sigma \eta \mu \alpha \nu \tau \iota \kappa \'o \varsigma$ (like semanticos)
and more or less translates into the word "meaning". Thus, semantic as adjective relates to the meaning in language and logic.

### Syntax of Propositional Logic

1. Alphabet of symbols: $\Sigma=\{p_1,\,p_2,\dots ,\, (,),\urcorner ,\vee ,\wedge ,\rightarrow ,\leftrightarrow ,\oplus , \perp, T\}$ 
1. Definition: **Atom** := Any of the symbols $p_1,\,p_2,\dots$
    * Note: Atoms are usually denoted by lowercase symbols from a natural language (e.g. english) alphabet like $p, q, r,\dots$ or variants as shown above ($p_1,p_2\dots$).
2. Definition of a sentence using that alphabet $\Sigma$: Sentences are strings containing only characters of the alphabet $\Sigma$.
3. Rules defining a _well-formed formula_:
    1. (WFF1) All atoms are wff
    2. (WFF2) if A and B are wff, the so are $(A), \urcorner A, A\vee B, A\wedge B, A\oplus B, A\rightarrow B, A\leftrightarrow B$.
    3. (WFF3) All wffs are constructed by repeated application of rules (WFF1) and (WFF2) a _finite number of times_.

Definition: All wff which are not an atom are called _compound statements_.   

Definition: **Literal** := Any atom $p$ or the symbol $\urcorner$ immediately followed by an atom $p$. That is, either $p$ or $\urcorner p$.

Definition: **Connective** := Any of the symbols of the alphabet that either links together two or more  wff or modifies one. Examples: $\urcorner ,\vee ,\wedge\dots$

Definition: **Language based on alphabet $\Sigma$** := Is the collection of all wff based on that alphabet.

Definition: A **grammar** is the set of rules that tells us what the wff are. 

   * The grammar for propositional logic is given by the rules (WFF1), (WFF2) and (WFF3) above. This set of rules is an exampl of _Backus-Knaur Form_ (BNF).


The idea of a language as a formal system, i.e., defined by a grammar as a set of transformation rules as stated above, is due to [Noam Chomsky](https://en.wikipedia.org/wiki/Noam_Chomsky).

In more technical terms, the example of grammar above is called a [_context-free grammar_](https://en.wikipedia.org/wiki/Context-free_grammar) 
and plays an essential role in defining programming languages and compilers, which translate a code
into an executable.


* **Solved exercise:** Prove that the sentence $(\urcorner ((p\vee q)\wedge r))$ is a wff.
    * **Proof:**
        1. p, q and r are wff [by WFF1]
        2. $(p\vee q)$ is a wff [by 1 and WFF2]
        3. $((p\vee q)\wedge r)$ is a wff [by 2 and WFF2]
        4. $(\urcorner ((p\vee q)\wedge r))$ is a wff [by 3 and WFF2] . q.e.d.

### Semantics of Propositional Logic

The semantics of propositional logic is already well known by us: it consists in specifying the truth tables of all connectives.

  
# Notes of Wed Nov. 7/8 2017. 

## Parse trees and Truth trees

For details, check out the book reference provided at the very beginning of these notes.

### Parse Trees

Eg: Parse tree for $\urcorner p\rightarrow (q \vee r)$ 
\begin{equation}
\begin{array}{ccc}
\phantom{p} & \rightarrow & \phantom{p}
\\
\phantom{p} & \swarrow\,\searrow  & \phantom{p}
\\
\urcorner  & \phantom{\rightarrow} & \vee 
\\
\downarrow  & \phantom{\rightarrow} & \swarrow \searrow
\\
p & \phantom{\rightarrow} &  q \quad r 
\end{array}
\end{equation}

### Truth Trees

Advantages:

1. **Simplifying** expressions/statements
2. Determining **SAT** (satisfiability) questions
3. Determining *contradictions*/**tautologies**

Eg: (Book notes: pp 51, example 1.10.1)

\begin{equation}
\begin{array}{ccc}
\phantom{p} & \urcorner p \rightarrow (q\wedge r) & \phantom{p}
\\
\phantom{p} & \swarrow\,\searrow  & \phantom{p}
\\
\urcorner (\urcorner p)  & \phantom{\rightarrow} & q\wedge r 
\\
\downarrow  & \phantom{\rightarrow} & \swarrow \searrow
\\
p & \phantom{\rightarrow} &  q \quad r 
\end{array}
\end{equation}

See book examples 1.10-2 to 1.10.10.

Homework: Exercices 5 (see book pp. 61)

#### Example workout: Exercise 1(a) book pp. 61

  * **Problem**: Determine wether the following argument is valid or not using a truth tree: $A\equiv p\rightarrow q,\,r\rightarrow s,\,p\vee r\vDash q\vee s$

    **Solution**:

    The key is to see that proving such argument is valid is equivalent to proving that the following statement is a tautology

    $\vDash\,\urcorner\left( (p\rightarrow q) \wedge (r\rightarrow s) \wedge (p\vee r)\right)  \vee (q\vee s)$

    The above line states that the expression to the right of the symbol $\vDash$ is a tautology.

    In order to prove that an expression is a tautology the trick is to prove that its negation is a **contradiction** (*proof by contradiction*), 
    i.e., we need to prove that 

    $\left( (p\rightarrow q) \wedge (r\rightarrow s) \wedge (p\vee r)\right) \,\wedge \, \urcorner (q\vee s) \vDash .$ 

    Let's do that.
    \begin{equation}
    \begin{array}{rcl}
      \phantom{p} & (p\rightarrow q) \wedge (r\rightarrow s) \wedge (p\vee r) \wedge   \urcorner (q\vee s) & \phantom{a}
    \\
      \phantom{p} & \downarrow & \phantom{a}
    \\  
      \phantom{p} & p\rightarrow q              & \phantom{a}
    \\
      \phantom{p} & r\rightarrow s              & \phantom{a}
    \\
      \phantom{p} & p\vee r                     & \phantom{a}
    \\
      \phantom{p} & \urcorner (q\vee s)         & \phantom{a}
    \\
      \phantom{p} & \swarrow\quad\searrow       & \phantom{a}
    \\
      \phantom{p} & \urcorner p \qquad  q       & \phantom{a}
    \\
      \phantom{p} & \swarrow   \downarrow \qquad \downarrow \searrow        & \phantom{a}
    \\
      \phantom{p} & \urcorner r \qquad   s    \qquad  \urcorner r\qquad s    & \phantom{a}
    \\
      \phantom{p} & \quad \swarrow\downarrow   \quad\downarrow\searrow   \quad  \downarrow\searrow \qquad \downarrow\searrow  & \phantom{a}
    \\
      \phantom{p} & \;\;  p\quad r \quad    p\quad r \;\;    p\quad r   \quad    p\quad r & \phantom{a}
    \\
      \phantom{p} & \;\;  \downarrow\quad \downarrow \quad    \downarrow\quad \downarrow \;\;   \downarrow \quad \downarrow   \quad    \downarrow\quad \downarrow & \phantom{a}
    \\
      \phantom{p} &   \urcorner q\; \urcorner q \;\;    \urcorner q\;\; \urcorner q \;\;    \urcorner q\; \urcorner q   \;\;   \urcorner q\;\; \urcorner q & \phantom{a}
    \\
      \phantom{p} &   \urcorner s\; \urcorner s \;\;    \urcorner s\;\; \urcorner s \;\;    \urcorner s\; \urcorner s   \;\;   \urcorner s\;\; \urcorner s & \phantom{a}
    \\
      \phantom{p} &  \perp\;\;\perp \quad   \perp\;\;\perp \quad   \perp\;\perp   \quad  \perp\;\;\perp & \phantom{a}
    \end{array}
    \end{equation}

    Clearly, not all branches end up in a contradiction, e.g., the right-most branch containing $\urcorner q \wedge \urcorner s$.

    Whence, the original statement is what is called a **contingent statement**, i.e., *a statement whose truth value can be either false or true, depending on
    the truth values of the atoms involved*. $\square$


    
