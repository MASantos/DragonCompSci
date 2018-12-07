#include<stdio.h>
/* Compile with gcc as
 * gcc 20181206_101000-Assignment-7-solution.c -o 20181206_101000-Assignment-7-solution
 *
 * When compiling with gcc, this program will give you three (3) warnings, namely:
 * 20181206_101000-Assignment-7-solution.c:40:16: warning: incompatible pointer types initializing 'short *' with an expression of type 'int *' [-Wincompatible-pointer-types]
 *  short int* ptr_s = &i;
 *             ^       ~~
 * 20181206_101000-Assignment-7-solution.c:47:11: warning: incompatible pointer types assigning to 'short *' from 'int *' [-Wincompatible-pointer-types]
 *  ptr_s = &j;
 *        ^ ~~
 * 20181206_101000-Assignment-7-solution.c:76:16: warning: incompatible pointer types initializing 'short *' with an expression of type 'int *' [-Wincompatible-pointer-types]
 *  short int* ptr_sa = &a;
 *             ^        ~~
 * 3 warnings generated.
 *
 * This is expected: See questions in sections 2 & 3.
 */
int main(){
    //1.  Declaration, Definition, Varible, Pointer and Dereferencing
    //
    //1 Declare variable j as an int
    int j;  
    //2 Define variable i as an int
    int i = 7;
    //3 Declare ptr as a pointer to int
    int * ptr;
    //4 Assign to ptr the address of i
    ptr = &i;
    //5 Asssign to i the  value 1
    i = 1 ;
    //6 Print the value of ptr, i.e., the memory address ptr is storing
    printf("6) ptr: %p\n", (void*)ptr);
    //7 Print the value of i
    printf("7) i: %d\n",i);
    //8 Print out the value the pointer ptr is pointing to
    printf("8) *ptr: %d\n",*ptr);
    //9 Print the content of mem addr pointed to by ptr (at this point, that's i)
    printf("9) *ptr: %d\n",*ptr);
    //10 Store 2 in the memory location of i
    i = 2;
    //11 Print the value of i
    printf("11) i: %d\n",i);
    //12 Assign the value 3 to i using ptr
    *ptr = 3;
    //13 Print i
    printf("13) i: %d\n",i);
    //14 Assign the value 137 to j using a pointer to j and print out the j
    int *ptr_j = &j;
    *ptr_j = 137;
    printf("14) j: %d\n",j);
    //
    // 2. Correct type of a pointer
    //
    //1 In one statement, define a pointer ptr_s to a short int with the value of variable i
    short int* ptr_s = &i;
    //2 Print out the value pointed by ptr_s and content of variable ptr_s.
    printf("2.2) ptr_s: %p  *ptr_s: %d\n",(void*)ptr_s, *ptr_s);
    //3 Does the value of that short int coincide with i? In which memory address is that short int been stored?
    printf("2.3) (*ptr_s:%d) == (i:%d)? Yes\n",*ptr_s,i);
    //4 Assign to j the value 65537, then assign its address to ptr_s
    j = 65537 ;
    ptr_s = &j;
    //5 Print out the value pointed by ptr_s and content of variable ptr_s.
    printf("2.5) ptr_s: %p  *ptr_s: %d\n",(void*)ptr_s, *ptr_s);
    //6 Does the value of that short int coincide with j? In which memory address is that short int been stored?
    printf("2.6) (*ptr_s:%d) == (j:%d)? No, in this case *ptr_s is different from j as j requires more than just 2 bytes\n",*ptr_s,j);
    printf(""
    "/* This previous line shows us something important:\n"
    "* 1.- A pointer, e.g, ptr or ptr_s, is something more than just a 'variable storing an integer value'\n"
    "* 2.- A pointer KNOWS some details about WHAT IT'S POINTING TO. Case in point, compare var j and ptr_s from 2.4.\n"
    "*      &j    is a mem addr pointing to the start of variable j this variable is 4 bytes long (check with sizeof(j) )\n"
    "*      ptr_s is a mem addr pointing to the start of variable j AS WELL!! BUT *ptr_s is a content that spans ONLY FIRST 2 BYTES OF J !!!\n"
    "*      Take home message: pointers and variables KNOW the EXTENT IN BYTES of the things they are refering to!!!\n"
    "*\n"
    "*      This is also shown in section 3 of this assignment. But let's show that explicitely for the present example\n"
    "*/"
    "\n");
    printf("Hence, Both ptr_s and &j point to the same address:\nptr_s: %p\t&j: %p\n",(void*)ptr_s,(void*)&j);
    printf("BUT (ptr_s+1) and (&j+1) point to different address: The pointer KNOW about the size of things they are pointing to!!:\n");
    printf("ptr_s+1: %p\t&j+1: %p\n",(void*)(ptr_s+1),(void*)(&j+1));
    printf("What is the difference between addresses ptr_s and (ptr_s+1)? Ans: 2 Bytes!!\n");
    printf("What is the difference between addresses &j and (&j+1)? Ans: 4 Bytes!!\n");
    //
    // 3. How does the computer lay out the bits of an integer in memory? Little Endian, Big Endian and basic pointer arithmetics.
    //
    //1 Define an integer variable a with the hex value value 0x00010203 (Note: the first 2 characters, 0x, just mean that the rest is a number in hexadecimal notation. Assign it just as it is.)
    int a = 0x00010203 ;
    //2 Print out the value of a and its address
    printf("3.2) a: %d &a: %p\n",a,&a);
    //3 Define a pointer to a short int ptr_sa and assign it the address of a
    short int* ptr_sa = &a;
    //4 Print out the address contained in ptr_sa and the value it’s referencing.
    printf("3.4) ptr_sa: %p *ptr_sa: %d\n",(void*)ptr_sa,*(ptr_sa));
    //5 Print out the content of the next memory address following that pointed to by ptr_sa. (Hint: The next memory address is given by ptr_sa+1)
    printf("3.5) *(ptr_sa+1): %d\n",*(ptr_sa+1));
    //6 What is the difference between the memory addresses of this last one and that in ptr_sa? Express it in bytes.
    printf("3.6) ptr_sa: %p ptr_sa+1: %p\n",(void*)ptr_sa,(void*)(ptr_sa+1));
    // 7 What did hapen? Explain the difference between these last three print statements?
    printf("Again we see the pointers store more than just an integer (the mem addr): They also KNOW THE TYPE of the THING THAT THEY POINT TO!\n");
    printf("Variable\tType\tpointer\tnext mem unit\tdifference in mem addresses (Bytes)\n");
    printf("a\tint\t&a:%p\(&a+1):%p\t%ld\n",(void*)&a,(void*)(&a+1),(&a+1)-(&a));
    printf(" \tshort\t&ptr_sa:%p\(&ptr_sa+1):%p\t%ld\n",(void*)&ptr_sa,(void*)(&ptr_sa+1),(ptr_sa+1)-(ptr_sa));
    //8 Consider the last print statement and answer the following questions:
    //8.1 What value of a was printed when dereferencing the address following that pointed to by ptr_sa
    printf("*(ptr_sa+1): %d\n",*(ptr_sa+1));
    //8.2 Hence, when we "go up" in memory we retrieve the higher bits (more to the left) or the lower bits (more to the right) of a byte?
    printf("(ptr_sa+1) points to the value of the 3rd byte of a (%d), namely, %d. That is, the (right) end of a byte (lowest exponent bit) is stored \
            in lower addresses, and the left-most bit is stored in higher addresses.\n",a,*(ptr_sa+1));
    printf("Hence, we are dealing with a LITTLE ENDIAN COMPUTER! This is common for Intel processors, and thus, AMD as well.\n");
    //8.3 The hex number 0x010203 occupies 3 bytes. For arguments sake, let’s say it is store in memory address 0x7fff51b0f900. 
    //  a) What number is stored in the first byte starting at that address, b) In which address is the 01 stored?
    printf("Given our processor uses a little-endian format to store data, if 0x010203 is store in addr 0x7fff51b0f900, the first byte starting at that address contains the number 0x03, i.e., a 3!\n");
    printf("The 3rd byte of 0x010203 is thus stored at addres 0x7fff51b0f900+2 = 0x7fff51b0f902\n");

    return 0;
}
