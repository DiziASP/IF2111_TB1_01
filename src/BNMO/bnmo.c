/* File: bnmo.c */
/* Implementasi fungsi dan prosedur Game BNMO */
#include "bnmo.h"

/* ***  Fungsi Utama BNMO *** */

void MAINMENU()
{
    int command;
    WELCOMESCREEN(); // Print Welcome Screen

    printf("Command: ");
    scanf("%d", &command);
    while (command != 3)
    {
        switch (command)
        {
        case 1:
            // STARTGAME();
            break;
        case 2:
            printf("LOADGAME()");
            break;
        case 3:
            printf("LOADGAME()");
            break;
        default:
            printf("Command tidak dikenali. Silahkan masukkan command yang benar.\n");
            break;
        }
        printf("Command: ");
        scanf("%s", &command);
    }
}

void STARTGAME();
/* I.S. Sembarang */
/* F.S. Game dimulai */

void LOADGAME();
/* I.S. Sembarang */
/* F.S. Game dilanjutkan dari file eksternal */

void SAVEGAME();
/* I.S. Sembarang */
/* F.S. Game disimpan ke file eksternal */

void CREATEGAME();
/* I.S. Sembarang */
/* F.S. Membuat game baru */

void LISTGAME();
/* I.S. Sembarang */
/* F.S. Menampilkan list game yang tersedia */

void DELETEGAME();
/* I.S. Sembarang */
/* F.S. Menghapus game yang dipilih */

void QUEUEGAME();
/* I.S. Sembarang */
/* F.S. mendaftarkan permainan kedalam list.
   List dalam queue akan hilang ketika pemain menjalankan command QUIT */

void PLAYGAME();
/* I.S. Sembarang */
/* F.S. Memainkan game yang dipilih */

void SKIPGAME();
/* I.S. Sembarang */
/* F.S. Melewati giliran game dalam queue */

void QUITGAME();
/* I.S. Sembarang */
/* F.S. Keluar dari game */

void HELP();
/* I.S. Sembarang */
/* F.S. Menampilkan list bantuan */

/* Implementasi Fungsi Bantuan */

void WELCOMESCREEN()
{
    char *res;
    char *filename = "src/ASCIIArt/welcome.txt";
    STARTWORDFILE(filename);

    if (!IsEOP())
    {
        while (!EndWord)
        {
            res = WordToString(currentWord);
            printf("%s\n", res);
            ADVWORD();
        }
    }
}