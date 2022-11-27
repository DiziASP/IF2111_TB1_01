#include "mesinkata.h"

boolean EndKata;
Kata currentKata;

/* Pemrosesan Mesin Kata Input */
void IGNOREBLANKS()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTWORD()
{
    START();
    IGNOREBLANKS();
    if (currentChar == MARK || IsEOP())
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        COPYWORD();
    }
}
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IGNOREBLANKS();
    if (currentChar == MARK)
    {
        EndKata = true;
    }
    else
    {
        COPYWORD();
        IGNOREBLANKS();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void COPYWORD()
{
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        currentKata.TabKata[i] = currentChar;
        ADV();
        i++;
    }
    currentKata.TabKata[i] = '\0';
    currentKata.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/* Pemrosesan Mesin Kata File */
void IGNOREBLANKSFILE()
{
    while (currentChar == BLANK || currentChar == MARK && !IsEOP())
    {
        ADVFILE();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = NEWLINE */

void STARTWORDFILE(char *filename)
{
    STARTFILE(filename);
    IGNOREBLANKSFILE();
    if (!IsEOP())
    {
        COPYWORDFILE();
    }
}
/* Versi Input dari File Eksternal */
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFILE()
{
    IGNOREBLANKSFILE();
    if (!IsEOP())
    {
        COPYWORDFILE();
        IGNOREBLANKSFILE();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure COPYWORDFILE */

void COPYWORDFILE()
{
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK && i < MAX_KATA && !IsEOP())
    {
        currentKata.TabKata[i] = currentChar;
        ADVFILE();
        i++;
    }
    currentKata.TabKata[i] = '\0';
    currentKata.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTCONFIG(char *filename)
{
    STARTFILE(filename);
    IGNOREBLANKSFILE();
    if (!IsEOP())
    {
        stringify();
    }
}
void ADVCONFIG()
{
    IGNOREBLANKSFILE();
    if (!IsEOP())
    {
        stringify();
        IGNOREBLANKSFILE();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure COPYWORDFILE */

void stringify()
{
    int i = 0;
    while (currentChar != MARK && i < MAX_KATA && !IsEOP())
    {
        currentKata.TabKata[i] = currentChar;
        ADVFILE();
        i++;
    }
    currentKata.TabKata[i] = '\0';
    currentKata.Length = i;
}

boolean IsStringEqual(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
boolean ContainStr(char *STR1, char *str2)
{
    int i = 0;
    int j = 0;
    while (STR1[i] != '\0' && str2[j] != '\0')
    {
        if (STR1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (str2[j] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *KataToString(Kata kata)
{
    char *result = (char *)malloc(sizeof(char) * (kata.Length + 1));
    int i;
    for (i = 0; i < kata.Length; i++)
    {
        result[i] = kata.TabKata[i];
    }
    result[kata.Length] = '\0';
    return result;
}

int KataToInt(Kata kata)
{
    int i = 0, result = 0;
    while (kata.TabKata[i] != '\0')
    {
        result = result * 10 + (kata.TabKata[i] - '0');
        i++;
    }
    return result;
}

void concatStr(char *str1, char *str2, char *str3)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str3[i] = str1[i];
        i++;
    }
    int j = 0;
    while (str2[j] != '\0')
    {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';
}