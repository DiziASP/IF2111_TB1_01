/* File: hangman.h */

#ifndef HANGMAN_H
#define HANGMAN_H

#include "../ADT/Array/array.h"
#include "../ADT/Set/set.h"
#include "../ADT/Mesin/mesinkata.h"
#include "stdlib.h"

extern boolean win;
extern int babak, poin;
extern Set word;
extern Set answer;

char *readInput();

void LoadDictionary(Set *question, Set *boi);
/* I.S : Sembarang */
/* F.S : Mengisi question dan answer dengan data dari file hangman.txt */

void SaveDictionary(Set word, Set answer);
/* I.S : Sembarang */
/* F.S : Menyimpan hasil dictionary kembali ke file */
int hangman();

#endif