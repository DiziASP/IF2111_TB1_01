/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Modifikasi Mesin Kata Versi 2 File Eksternal */

#include "../Boolean/boolean.h"
#include "mesinkata.h"

/* State Mesin Kata */

Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == NEWLINE || currentChar == BLANK && !EOP)
    {
        ADVFILE();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDFILE(char *filename)
{
    STARTFILE(filename);
    IgnoreBlanks();
    if (!EOP)
    {
    }

    CopyWord();
}

/* Versi Input dari File Eksternal */
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (!EOP)
    {
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    int i = 0;
    while (currentChar != MARK && currentChar != NEWLINE && i < NMax && !EOP)
    {
        currentWord.TabWord[i] = currentChar;
        ADVFILE();
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