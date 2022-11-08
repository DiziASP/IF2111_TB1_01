/* File: bnmo.c */
/* Implementasi fungsi dan prosedur Game BNMO */
#include "bnmo.h"

/* Inisialisasi State */
ArrayDin gamesList;
boolean Quit;
boolean isLoad;
boolean isSave;
char *userCreated;
Queue nowPlaying;
/* ***  Fungsi Utama BNMO *** */

void MAINMENU()
{
    /* STATE INITIAL */
    char *query;
    Quit = false;
    isLoad = false;
    isSave = false;
    userCreated = NULL;
    CreateQueue(&nowPlaying);

    /* STATE MAIN MENU */
    WELCOMESCREEN(); // Print Welcome Screen
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
        else if (compQuery(query, "SAVE"))
        {
            SAVEGAME();
        }
        else if (compQuery(query, "CREATEGAME"))
        {
            CREATEGAME(&gamesList);
        }
        else if (compQuery(query, "LISTGAME"))
        {
            LISTGAME(gamesList);
        }
        else if (compQuery(query, "DELETEGAME"))
        {
            DELETEGAME(&gamesList);
        }
        else if (compQuery(query, "QUEUEGAME"))
        {
            QUEUEGAME(gamesList, &nowPlaying);
        }
        else if (compQuery(query, "PLAYGAME"))
        {
            PLAYGAME(&nowPlaying);
        }
        else if (compQuery(query, "SKIPGAME"))
        {
            SKIPGAME(&nowPlaying);
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

        if (Quit)
            break;
        if (isLoad)
        {
            printf("\n");
            MMSCREEN();
        }
        query = readQuery();
    }
}

void STARTGAME(char *userFile)
{
    /* 1. Read Games List */
    char *filename = (char *)malloc(100 * sizeof(char));
    concatStr("data/", userFile, filename);
    gamesList = MakeArrayDin();
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

        /* 2. Print Konfig berhasil */
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

void SAVEGAME()
{
    /* 1. Save Games List */
    ADVWORDSTD();
    char *userInput = KataToString(currentKata);
    char *filename = (char *)malloc(100 * sizeof(char));
    // Check input valid
    while (!ContainStr(userInput, ".txt"))
    {
        printf("Input tidak valid. Ulangi kembali: \n");
        STARTWORD();
        userInput = KataToString(currentKata);
    }

    concatStr("data/", userInput, filename);
    FILE *file = fopen(filename, "w");
    fprintf(file, "%d\n", Length(gamesList));
    for (int i = 0; i < Length(gamesList); i++)
    {
        if (i == Length(gamesList) - 1)
            fprintf(file, "%s", Get(gamesList, i));
        else
            fprintf(file, "%s\n", Get(gamesList, i));
    }
    fclose(file);

    /* 3. Print Konfig berhasil */
    printf("Save file berhasil dibuat.\n");
}
/* I.S. Sembarang */
/* F.S. Game disimpan ke file eksternal */

void CREATEGAME(ArrayDin *arr)
{
    boolean found = false;
    int i = 0;
    printf("Masukkan nama game yang akan ditambahkan: ");
    /* Input Mechanism */
    char *input = readGame();
    /* End Input */
    while (i < (*arr).Neff && found == false)
    {
        if (compQuery(input, arr->A[i]))
        {
            found = true;
        }
        i++;
    }
    if (!found)
    {
        InsertLast(arr, input);
        if (userCreated == NULL)
        {
            userCreated = input;
        }
        printf("Game berhasil ditambahkan\n");
    }
    else
    {
        printf("Game sudah ada\n");
    }
}
/* I.S. Sembarang */
/* F.S. Membuat game baru */

void LISTGAME(ArrayDin arr)
{
    int panjang = arr.Neff;
    int i;
    printf("List game BNMO :\n");
    if (IsEmpty(arr))
    {
        printf("Tidak ada game yang tersedia\n");
    }
    else
    {
        for (i = 0; i < panjang; i++)
        {
            printf("%d. %s\n", i + 1, arr.A[i]);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Menampilkan list game yang tersedia */

void DELETEGAME(ArrayDin *arr)
{
    int nomor;
    printf("Berikut adalah daftar game yang tersedia \n");
    LISTGAME(*arr);
    printf("Masukkan nomor game yang akan dihapus: ");

    /* Read Angka */
    do
    {
        STARTWORD();
        nomor = KataToInt(currentKata);
        if (nomor < 0 || nomor > (*arr).Neff)
        {
            printf("Input invalid. Silahkan masukkan nomor game yang valid: ");
        }
    } while (nomor < 0 || nomor > (*arr).Neff);

    if (nomor >= 1 && nomor <= (*arr).Neff)
    {
        if (nomor >= 1 && nomor <= 5)
        {
            printf("Game gagal dihapus\n");
        }
        else
        {
            printf("Game berhasil dihapus\n");
            DeleteAt(arr, nomor - 1);
        }
    }
    else
    {
        printf("Game gagal dihapus\n");
    }
}
/* I.S. Sembarang */
/* F.S. Menghapus game yang dipilih */

void QUEUEGAME(ArrayDin arr, Queue *daftargame)
/* I.S. Sembarang */
/* F.S. mendaftarkan permainan kedalam list.
   List dalam queue akan hilang ketika pemain menjalankan command QUIT */
{
    if (isEmpty(*daftargame))
    {
        printf("Daftar game antrianmu kosong.\n\n");
    }
    else
    {
        printf("Berikut adalah daftar antrian game-mu\n");
        IdxType i = IDX_HEAD(*daftargame);
        int start = 1;
        for (i = IDX_HEAD(*daftargame); i != IDX_TAIL(*daftargame); i = (i + 1) % CAPACITY)
        {
            printf("%d. %s\n", start, daftargame->buffer[i]);
            start += 1;
        }
        printf("%d. %s\n\n", start, daftargame->buffer[i]);
    }

    LISTGAME(arr);

    printf("Nomor game yang ingin dimainkan: ");
    STARTWORD();
    while (KataToInt(currentKata) > arr.Neff || KataToInt(currentKata) < 0)
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        STARTWORD();
    }

    IdxType nomor = KataToInt(currentKata);
    IdxType i;
    ElType val;
    IdxType find = 0;

    ElType games = arr.A[nomor - 1];
    enqueue(daftargame, games);

    printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
}

void PLAYGAME(Queue *daftargame)
/* I.S. Sembarang */
/* F.S. Memainkan game yang dipilih */
{

    if (isEmpty(*daftargame))
    {
        printf("Daftar Antrian game-mu kosong.\n");
        return;
    }
    printf("Berikut adalah daftar antrian game-mu\n");
    IdxType i = IDX_HEAD(*daftargame);
    int start = 1;
    for (i = IDX_HEAD(*daftargame); i != IDX_TAIL(*daftargame); i = (i + 1) % CAPACITY)
    {
        printf("%d. %s\n", start, daftargame->buffer[i]);
        start += 1;
    }
    printf("%d. %s\n\n", start, daftargame->buffer[i]);

    char *game_now;
    dequeue(daftargame, &game_now);
    if (compQuery(game_now, "Diner DASH"))
    {
        // Mainkan Diner Dash
        printf("Loading %s ...\n\n", game_now);
        // int a = dinnerDash();
    }
    else if (compQuery(game_now, "RNG"))
    {
        printf("Loading %s ...\n\n", game_now);
        // int a = RNG(); // Karena RNG & Diner Dash dibuat dalam int() / bukan void(), jadi jalaninnya gini
    }
    else if (compQuery(game_now, "HANGMAN"))
    {
        printf("Loading %s ...\n\n", game_now);
        hangman();
    }
    else if (compQuery(game_now, userCreated))
    {
        printf("Loading %s ...\n\n", game_now);
        UserCreated();
    }
    else
    {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n Silahkan pilih game lain.\n", game_now);
    }
}
void SKIPGAME(Queue *daftargame)
{
    ADVWORDSTD();
    while (KataToInt(currentKata) > CAPACITY || KataToInt(currentKata) < 0)
    {
        printf("Jumlah permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        STARTWORD();
    }
    char *game_now;
    int i = 0;
    while (i < KataToInt(currentKata) && !isEmpty(*daftargame))
    {
        dequeue(daftargame, &game_now);
        i++;
    }
    if (!isEmpty(*daftargame))
    {
        dequeue(daftargame, &game_now);
        if (compQuery(game_now, "Diner DASH"))
        {
            // Mainkan Diner Dash
            printf("Loading %s ...\n\n", game_now);
            // int a = dinnerDash();
        }
        else if (compQuery(game_now, "RNG"))
        {
            printf("Loading %s ...\n\n", game_now);
            // int a = RNG(); // Karena RNG & Diner Dash dibuat dalam int() / bukan void(), jadi jalaninnya gini
        }
        else if (compQuery(game_now, "hangman"))
        {
            printf("Loading %s ...\n\n", game_now);
            hangman();
        }
        else if (compQuery(game_now, userCreated))
        {
            printf("Loading %s ...\n\n", game_now);
            UserCreated();
        }
        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n Silahkan pilih game lain.\n", game_now);
        }
    }
    else
    {
        printf("Tidak ada lagi permainan dalam daftar game-mu.\n");
    }
}
/* I.S. Sembarang */
/* F.S. Melewati giliran game dalam queue */

void QUITGAME()
{
    printf("Apakah kamu yakin? Y/N\n");
    char *cmd = readQuery();
    if (compQuery(cmd, "Y") || compQuery(cmd, "YES") || compQuery(cmd, "y"))
    {
        if (!isSave)
        {
            printf("Sepertinya kamu belum menyimpan permainan\n");
            printf("Apakah kamu ingin menyimpan permainan? Y/N\n");
            char *cmd = readQuery();
            if (compQuery(cmd, "Y") || compQuery(cmd, "YES") || compQuery(cmd, "y"))
            {
                char *filename = (char *)malloc(100 * sizeof(char));
                printf("Masukkan nama file: ");
                char *userInput = readQuery();

                while (!ContainStr(userInput, ".txt"))
                {
                    printf("Input tidak valid. Ulangi kembali: \n");
                    userInput = readQuery();
                }
                concatStr("data/", userInput, filename);
                FILE *file = fopen(filename, "w");
                fprintf(file, "%d\n", Length(gamesList));
                for (int i = 0; i < Length(gamesList); i++)
                {
                    if (i == Length(gamesList) - 1)
                        fprintf(file, "%s", Get(gamesList, i));
                    else
                        fprintf(file, "%s\n", Get(gamesList, i));
                }
                fclose(file);

                /* 3. Print Konfig berhasil */
                printf("Save file berhasil dibuat.\n");
            }
        }
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

    printf("Command: ");
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

char *readGame()
{
    char *input = (char *)malloc(sizeof(char) * 100);
    concatStr("", "", input);
    STARTWORD();
    while (cc != MARK)
    {
        concatStr(input, KataToString(currentKata), input);
        concatStr(input, " ", input);
        ADVWORDSTD();
    }
    concatStr(input, KataToString(currentKata), input);
    return input;
}

boolean ContainStr(char *query, char *comp)
{
    int i = 0;
    int j = 0;
    while (query[i] != '\0' && comp[j] != '\0')
    {
        if (query[i] == comp[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (comp[j] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}