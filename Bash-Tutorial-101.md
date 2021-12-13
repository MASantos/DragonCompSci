# Bash Tutorial
This tutorial is intended as a crash course to help fixing the minimal set of  ideas to allow one
modify the scripts built in house. In particular we will focus on understanding the `automate-upgrade.sh`
Drivesync5 upgrade script.

Generality or precision have consequently been sacrified in order to keep this tutorial concise and practical.


## Concepts to brush up for this tutorial:

### 1. Key "actions" we do in any program

* Print out some "stuff"
* Read in some "stuff"
* Store in memory some "stuff"
* Make a choice
* Repeat some statements in an automated way (so called "loops")

That's all what any program, in any language does.

The first two are part of what's called I/O (input/output) procedures.

### 2. Variable assignment
This is how we store things in memory
x=43
yz="Hello World"
b=true

#### Remark
A statement like `x=43` means the following:
1. The computer reads the equal sign and then knows that
2. `43` is a *value* (see section on Types below) that the computer stores in memory.
3. `x` is a label (string) that the computer the computer uses to point to the memory location where the previous value was stored.
4. After a variable assignment, whenever we use `x` the computer looks up the memory location pointed to by `x` and uses the value stored there, i.e, `43`

These facts are summarized by saying that **the variable `x` is a reference for the value `43`**.

#### 2.1 Accessing the value referred to by a variable
In bash we do this similarly to what's called **dereferencing**, i.e., accessing the value from the memmory location that
a variable lable is pointing to.

In bash we do this by writing a dollar sign in front of the variable name.
Example:
```
echo $x    # 43
```

In some cases, you may have to wrap the variable label within braces
Example
```
echo ${x}  # 43
```


### 3. Bash Types
There are NO Types when it comes to variables' values.

Other languages make distinctions like 'x is a number' and 'yz is a string'.

In bash, basically everything is a string.
The above statements mean that even variable `x` has a value that is a string, despite its looks.

The only 2 exceptions that we will encounter are that of a
1. boolean Type. Case in point, the above variable `b` has been assigned an boolean value.
2. Array/List


### 4. Conditionals
These are the **if-then-else** type of staments.

We have the computer crunch different group of statements depending on some conditions being true or false.

This is how we make choices in a programming language.

### 5. Loops
We have a list of 1000 files and we want to change their names and add the suffix `-test`.

How can we do that in the most efficient -i.e., fastest- way?

For each file we have to do issue the same command, namely a `mv`: `mv oldname oldname-test`.
This means that the action we need to perform has a well defined **pattern** that is the same for all files.
This is precisely the scenario where we should use a loop.

Loops come in different "forms":
* **while loop**
* **for loop**
* **until loop** (we won't discuss this)

#### Example of loop in plain english
```
let x be 3
while x is larger than 0, do the following
 print the value of x
 decrease x by 1
done
```
In bash we can do it the following way
```
x=3
while [ $x -gt 0 ] ; do
 echo $x
 x = $(( x-1 ))
done
```
### 6. I/O
#### 6.1 Printing
It's enough to use the command `echo`. It's not the only one: there is also the `printf`,
but we won't comment this but on passing.



#### 6.2 Reading in "stuff"
We will be using 5 different ways:

1. Prompting (interactively) the user
2. Command line parameters
3. Redirection
4. Pipes
5. Sourcing

We will discuss all this cases in the tutorial though.

### 7. Functions
A function is a "machine" that, as all machines, takes in some input, and spits out some output, whatever those may be.

In that sense, any Linux command is a function. All take in some input (this could be either provided by the user
or read directly from the OS environment) and **do something**. The latter can be just printing things out on the screen
or changing something at the OS or filesystem level or all of the above.

You have seen function in high school: `f(x) = 2x`. This  is a function that doubles any number that we feed to it.

It is vital to make a *linguistic* distinction:
1. The **name of the function** is `f`
2. In that example above, `x` is called the *argument* of `f`. Here, we may also call it the *parameter* of `f`.
3. The expression above `f(x)` is called a **function call**

Many programming languages use the same syntax. Alas, Bash does not quite do so.

Still, **everytime we see a *label followed by (* we know that *the label refers to a function*.

In bash, a *function call* is done as `f x`.

Yet, when *defining a function* we must write
```
f(){
 ...statements that ...
 ...the function will do...
}
```
That is, *the label `f` followed by `()`* **will tell the computer that `f` is a function**!

#### Remark
1. Any script it for all purposes the same as a function
2. Any script can itself define new functions and those can be called inside that script

Hence, the same way we read the command-line parameters that we provide to a script is the way
we may grab the arguments we pass to a function when defining that function.

Example
```
f(){
 x=$1
 echo $((2*x))
}

# Now let's call function f with argument 3
f 3 # This will print 6 on screen
```
