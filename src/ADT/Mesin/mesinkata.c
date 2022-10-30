/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Modifikasi File Eksternal */

#include "../Boolean/boolean.h"
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        IgnoreBlanks();
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char *filename)
{
    STARTFILE(filename);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

/* Versi Input dari File Eksternal */
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    int i;
    i = 0;
    while (currentChar != MARK && currentChar != NEWLINE && i < NMax && !IsEOP())
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int WordToInt(Word W)
{
    int i, result = 0;
    for (i = 0; i < W.Length; i++)
    {
        result = result * 10 + (W.TabWord[i] - '0');
    }
    return result;
}
/* Mengubah Word menjadi integer
   I.S. : W terdefinisi
   F.S. : W berisi integer yang sudah diakuisisi */

char *WordToString(Word W)
{
    char *result = (char *)malloc(sizeof(char) * (W.Length + 1));
    int i;
    for (i = 0; i < W.Length; i++)
    {
        result[i] = W.TabWord[i];
    }
    result[W.Length] = '\0';
    return result;
}
/* Mengubah Word menjadi string
   I.S. : W terdefinisi
   F.S. : W berisi string yang sudah diakuisisi */