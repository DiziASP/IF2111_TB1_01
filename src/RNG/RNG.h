/* File: RNG.c */
/* Random Integer Generator */
#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean
#include "../ADT/Boolean/boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_number();
/*
    Fungsi untuk mengembalikan bilangan random
    Pada implementasinya, angka yang keluar akan berada di batas [0,1000]

*/


int binary_exponent(int a,int b);
/*
    fungsi untuk menghitung a^b dengan kompleksitas O(log b)
*/


int random_generate();
/*
    fungsi yang mengembalikan random generator
*/

#endif