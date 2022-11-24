/* File: hangman.h */

#ifndef HANGMAN_H
#define HANGMAN_H

#include "../ADT/Array/array.h"
#include "../ADT/Mesin/mesinkata.h"

extern boolean win;
extern int babak;
extern ArrayDin word;
extern ArrayDin answer;
extern ArrayDin wordGuess;

int hangman();

#endif