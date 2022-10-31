/* File: wordmachine.c */
/* Implementasi Mesin Kata Standar (input STDIN) */

#include "wordmachine.h"

Kata currentKata;

void IgnoreBlank()
{
    while (cc == BLANK || cc == MARK && !EOT)
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
    IgnoreBlank();
    if (!EOT)
        CopyWordSTD();
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDSTD()
{
    IgnoreBlank();
    if (!EOT)
        CopyWordSTD();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordSTD()
{
    int i = 0;
    while (cc != BLANK && cc != MARK && !EOT)
    {
        currentKata.TabWord[i] = cc;
        ADV();
        i++;
    }
    currentKata.Length = i;
    currentKata.TabWord[i] = '\0';
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int KataToInt(Kata K)
{
    int i = 0, result = 0;
    while (i < K.Length)
    {
        result = result * 10 + (K.TabWord[i] - '0');
        i++;
    }
    return result;
}

char *KataToString(Kata K)
{
    char *result = (char *)malloc((K.Length + 1) * sizeof(char));
    int i = 0;
    while (i < K.Length)
    {
        result[i] = K.TabWord[i];
        i++;
    }
    result[i] = '\0';
    return result;
}

Kata StringToKata(char *str)
{
    Kata result;
    int i = 0;
    while (str[i] != '\0')
    {
        result.TabWord[i] = str[i];
        i++;
    }
    result.Length = i;
    return result;
}