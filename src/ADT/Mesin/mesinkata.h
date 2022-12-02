/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Boolean/boolean.h"
#include "mesinkar.h"

#define MAX_KATA 255
#define BLANK ' '

typedef struct
{
   char TabKata[MAX_KATA]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata currentKata;

/* Pemrosesan Mesin Kata Input */
void IGNOREBLANKS();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTWORD();
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void COPYWORD();
/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* Pemrosesan Mesin Kata File */
void IGNOREBLANKSFILE();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = NEWLINE */

void STARTWORDFILE(char *filename);
/* Memulai Pembacaan Kata pada File */

void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
         Jika currentChar = NEWLINE, endWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void COPYWORDFILE();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
         currentChar = BLANK atau currentChar = NEWLINE;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void STARTCONFIG(char *filename);

void ADVCONFIG();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure COPYWORDFILE */

void stringify();

boolean IsStringEqual(char *str1, char *str2);

char *KataToString(Kata Kata);

int KataToInt(Kata kata);

void concatStr(char *str1, char *str2, char *str3);

boolean ContainStr(char *query, char *comp);
#endif
