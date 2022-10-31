/* File: charmachine.h */
/* Definisi Mesin Karakter Standar (input STDIN) */

#ifndef _CHARMACHINE_H
#define _CHARMACHINE_H

#include "../Boolean/boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Konstanta */
#define MARK '\n'

/* State Mesin */
extern char cc;
extern boolean EOT;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

#endif