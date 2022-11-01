/* File: bnmo.c */
/* Implementasi fungsi dan prosedur Game BNMO */
#include "bnmo.h"

/* Inisialisasi State */
ArrayDin gamesList;
ArrayDin history;
boolean Quit;
boolean isLoad;
/* ***  Fungsi Utama BNMO *** */

void MAINMENU()
{
    char *query;
    Quit = false;
    isLoad = false;
    WELCOMESCREEN(); // Print Welcome Screen
    printf("Command: ");
    query = readQuery();
    while (!Quit)
    {
        if (compQuery(query, "START") && !isLoad)
        {
            STARTGAME("config.txt");
        }
        else if (compQuery(query, "LOAD") && !isLoad)
        {
            LOADGAME();
        }
        else if (compQuery(query, "QUIT"))
        {
            QUITGAME();
            break;
        }
        else
        {
            printf("Command not found. Please try again.\n");
        }
        if (!Quit)
        {
            MMSCREEN();
            printf("Command: ");
            query = readQuery();
        }
    }
}

void STARTGAME(char *userFile)
{
    /* 1. Read Games List */
    char *filename = (char *)malloc(100 * sizeof(char));
    concatStr("data/", userFile, filename);
    gamesList = MakeArrayDin();
    history = MakeArrayDin();
    STARTWORDFILE(filename);
    if (!EOP)
    {
        int totalGame = WordToInt(currentWord), i = 0;
        while (i < totalGame)
        {
            ADVWORD();
            InsertLast(&gamesList, WordToString(currentWord));
            i++;
        }

        /* 2. Read History */
        ADVWORD();
        int totalHistory = (!EOP ? WordToInt(currentWord) : 0), j = 0;
        while (j < totalHistory)
        {
            ADVWORD();
            InsertLast(&history, WordToString(currentWord));
            j++;
        }

        /* 3. Print Konfig berhasil */
        if (compQuery(userFile, "config.txt"))
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        isLoad = true;
    }
}
/* I.S. Sembarang */
/* F.S. Game dimulai */

void LOADGAME()
{
    /* Next Query */
    if (cc == MARK)
    {
        printf("Input invalid\n");
    }
    else
    {
        ADVWORDSTD();
        char *userFile = KataToString(currentKata);
        STARTGAME(userFile);
    }
}
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

void QUITGAME()
{
    printf("Apakah kamu yakin? Y/N: ");
    char *cmd = readQuery();
    if (compQuery(cmd, "Y") || compQuery(cmd, "YES") || compQuery(cmd, "y"))
    {
        printf("Terima Kasih sudah bermain :D\n");
        Quit = true;
    }
}
/* I.S. Sembarang */
/* F.S. Keluar dari game */

void HELP();
/* I.S. Sembarang */
/* F.S. Menampilkan list bantuan */

/* Implementasi Fungsi Bantuan */

void WELCOMESCREEN()
{
    char *filename = "src/ASCIIArt/welcome.txt";
    STARTWORDFILE(filename);

    while (!EOP)
    {
        printf("%s\n", WordToString(currentWord));
        ADVWORD();
    }
    printf("%s\n", WordToString(currentWord)); // LastWord
}

void MMSCREEN()
{
    char *filename = "src/ASCIIArt/menu.txt";
    STARTWORDFILE(filename);

    while (!EOP)
    {
        printf("%s\n", WordToString(currentWord));
        ADVWORD();
    }
    printf("%s\n", WordToString(currentWord)); // LastWord
}

char *readQuery()
{
    STARTWORD();
    return KataToString(currentKata);
}

boolean compQuery(char *query, char *command)
{
    int i = 0;
    while (query[i] != '\0' && command[i] != '\0')
    {
        if (query[i] != command[i])
        {
            return false;
        }
        i++;
    }
    return true;
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
