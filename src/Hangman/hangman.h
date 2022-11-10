/* File: hangman.h */

#ifndef HANGMAN_H
#define HANGMAN_H

#include "../ADT/Array/array.h"
#include "../ADT/Mesin/wordmachine.h"
#include "../ADT/Mesin/charmachine.h"

extern boolean win;
extern int babak;
extern ArrayDin word;
extern ArrayDin answer;
extern ArrayDin wordGuess;

void hangman();
#endif