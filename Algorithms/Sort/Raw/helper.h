#ifndef HELPERFUNCTIONS
#define HELPERFUNCTIONS
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#endif

// BEGIN HELPER FUNCTIONS
//prints array of floats
void printArray(float* ar, size_t n ) ;

//Integer exponentiation
int ipow(int base, int exp) ;

//Find minimum value in slice of array of floats
float findMin(float* ar, size_t n, size_t i) ;

//Find index of the first instance of value m in slice of array of floats. Returns -1 if not found
size_t findIndex(float m , float* ar, size_t n , size_t is) ;

//END OF HELPER FUNCTIONS
