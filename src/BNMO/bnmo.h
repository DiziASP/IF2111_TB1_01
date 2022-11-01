/* File: bnmo.h */
/* Definisi fungsi dan prosedur Game BNMO */
#ifndef BNMO_H
#define BNMO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../ADT/Boolean/boolean.h"
#include "../ADT/Mesin/mesinkar.h"
#include "../ADT/Mesin/mesinkata.h"
#include "../ADT/Mesin/charmachine.h"
#include "../ADT/Mesin/wordmachine.h"
#include "../ADT/Array/array.h"

/* *** Initial State dari BNMO *** */
extern ArrayDin gamesList;
extern ArrayDin history;
extern boolean Quit;
extern boolean isLoad;

/* *** Definisi Fungsi dan Prosedur *** */
/* Menampilkan Main Menu BNMO */
void MAINMENU();
/* I.S. Sembarang */
/* F.S. Menampilkan menu */

/* Memulai Game BNMO */
void STARTGAME();
/* I.S. Sembarang */
/* F.S. Game dimulai */

/* Loading BNMO dari File Save Eksternal */
void LOADGAME();
/* I.S. Sembarang */
/* F.S. Game dilanjutkan dari file eksternal */

/* Save BNMO ke File Save Eksternal */
void SAVEGAME();
/* I.S. Sembarang */
/* F.S. Game disimpan ke file eksternal */

/* Membuat game di BNMO */
void CREATEGAME();
/* I.S. Sembarang */
/* F.S. Membuat game baru */

/* Menampilkan list game yang terdapat pada BNMO */
void LISTGAME();
/* I.S. Sembarang */
/* F.S. Menampilkan list game yang tersedia */

/* Menghapus game yang terpilih dari BNMO */
void DELETEGAME();
/* I.S. Sembarang */
/* F.S. Menghapus game yang dipilih */

/* Menambahkan game ke dalam Queue game player */
void QUEUEGAME();
/* I.S. Sembarang */
/* F.S. mendaftarkan permainan kedalam list.
   List dalam queue akan hilang ketika pemain menjalankan command QUIT */

/* Memainkan game  */
void PLAYGAME();
/* I.S. Sembarang */
/* F.S. Memainkan game yang dipilih */

/* Skip game yang dipilih */
void SKIPGAME();
/* I.S. Sembarang */
/* F.S. Melewati giliran game dalam queue */

/* Keluar dari game BNMO */
void QUITGAME();
/* I.S. Sembarang */
/* F.S. Keluar dari game */

/* Menampilkan help command BNMO */
void HELP();
/* I.S. Sembarang */
/* F.S. Menampilkan list bantuan */

/* ***  Fungsi dan Prosedur Bantuan (Miscellaneous) *** */
/* Menampilkan Welcome Screen */
void WELCOMESCREEN();

/* Menampilkan MAINMENU Screen */
void MMSCREEN();

/* Menggabung String */
void concatStr(char *str1, char *str2, char *str3);

/* Membandingkan String*/
boolean compQuery(char *query, char *command);

/* Membaca Query user */
char *readQuery();
#endif