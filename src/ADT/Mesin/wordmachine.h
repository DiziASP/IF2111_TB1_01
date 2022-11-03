/* File: wordmachine.h */
/* Definisi Mesin Kata Standar (input STDIN) */

#ifndef _WORDMACHINE_H
#define _WORDMACHINE_H

#include "../Boolean/boolean.h"
#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

#define NMax 255
#define BLANK ' '
#define NEWLINE '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Kata;

/* State Mesin Kata */
extern Kata currentKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDSTD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordSTD();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int KataToInt(Kata K);
/* Mengubah kata menjadi integer */

char *KataToString(Kata K);
/* Mengubah kata menjadi string */

Kata StringToKata(char *str);
#endif