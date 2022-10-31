/* File: charmachine.c */
/* Implementasi Mesin Karakter Standar (input STDIN) */

#include "charmachine.h"

/* State Mesin */
char cc;
boolean EOT;

static FILE *tape;
static int retval;

void START()
{
    tape = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV()
{
    retval = fscanf(tape, "%c", &cc);
    EOT = (cc == MARK);
    if (EOT)
    {
        fclose(tape);
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */