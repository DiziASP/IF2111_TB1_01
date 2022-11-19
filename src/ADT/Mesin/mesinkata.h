/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Modifikasi File Eksternal */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Boolean/boolean.h"
#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

#define NMax 255
#define BLANK ' '
#define NEWLINE '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDFILE();
/* Versi Input dari File Eksternal */
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int WordToInt(char *);
/* Mengubah Word menjadi integer
   I.S. : W terdefinisi
   F.S. : W berisi integer yang sudah diakuisisi */

char *WordToString();
/* Mengubah Word menjadi string
   I.S. : W terdefinisi
   F.S. : W berisi string yang sudah diakuisisi */
#endif