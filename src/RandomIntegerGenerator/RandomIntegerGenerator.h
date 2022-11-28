
/* File: RNG.c */
/* Random Integer Generator */
#ifndef RandomIntegerGenerator
#define RandomIntegerGenerator

// Boolean
#include "../ADT/Boolean/boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long int binary_exponent(int a,int b,int batas);
/*
    fungsi untuk menghitung a^b dengan kompleksitas O(log b)
*/

long long int random_generate(int batas);
/*
    fungsi yang mengembalikan random generator. 
    integer hasilnya akan berada di antara [1,batas]
    
*/

#endif