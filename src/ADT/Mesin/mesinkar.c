#include "mesinkar.h"

/* State Mesin */
char currentChar;
boolean EOP;

/* State File*/
static FILE *pita;
static int retval;

/* STDIN Parser */
void START()
{
    pita = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

/* File Parser */
void STARTFILE(char *filename)
{
    pita = fopen(filename, "r");
    if (pita == NULL)
    {
        printf("File konfigurasi tidak ditemukan\n");
        EOP = true;
    }
    else
    {
        ADVFILE();
    }
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADVFILE()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (retval < 0);
    if (IsEOP())
    {
        EOP = true;
        fclose(pita);
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC()
{
    return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP()
{
    return EOP;
}
/* Mengirimkan true jika currentChar = MARK */