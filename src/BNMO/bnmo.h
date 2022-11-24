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
#include "../ADT/Array/array.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/Set/set.h"
#include "../ADT/Map/map.h"
#include "../ADT/LinkedList/linkedlist.h"

/* Import game */
#include "../RandomIntegerGenerator/randomintegergenerator.h"
#include "../RNG/RNG.h"
#include "../UserCreated/UserCreated.h"
#include "../Hangman/hangman.h"
#include "../DinerDash/dinnerdash.h"

/* *** Initial State dari BNMO *** */
extern Stack history;
extern Set gamesList;
extern Queue nowPlaying;
extern Map scoreboardRNG, scoreboardDinerDash, scoreboardHangman, scoreboardTowerOfHanoi, scoreboardSnake, scoreboardCustomGame;
extern boolean Quit, isLoad, isSave;
extern char *userCreated, *username;

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
void SAVEGAME(char *userInput);
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

void HISTORY(Stack history);

void RESETHIST(Stack *history);

void SCOREBOARD(Map scoreboardRNG, Map scoreboardDinerDash, Map scoreboardHangman, Map scoreboardTowerOfHanoi, Map scoreboardSnake, Map scoreboardCustomGame);

void ResetScoreboard(Set game, Map *scoreboardRNG, Map *scoreboardDinerDash, Map *scoreboardHangman, Map *scoreboardTowerOfHanoi, Map *scoreboardSnake, Map *scoreboardCustomGame);
/* ***  Fungsi dan Prosedur Bantuan (Miscellaneous) *** */
/* Menampilkan Welcome Screen */
void WELCOMESCREEN();

/* Menampilkan MAINMENU Screen */
void MMSCREEN();

/* Membaca Query user */
char *readQuery();

#endif