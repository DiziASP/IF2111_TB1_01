/* File: bnmo.c */
/* Implementasi fungsi dan prosedur Game BNMO */
#include "bnmo.h"

/* Inisialisasi State */
ArrayDin history;
Set gamesList;
Map scoreboardRNG, scoreboardDinerDash, scoreboardHangman, scoreboardTowerOfHanoi, scoreboardSnake, scoreboardCustomGame;
boolean Quit;
boolean isLoad;
boolean isSave;
char *userCreated;
Queue nowPlaying;
char *username;
/* ***  Fungsi Utama BNMO *** */

void MAINMENU()
{
    /* STATE INITIAL */
    char *query;
    Quit = false;
    isLoad = false;
    isSave = false;
    userCreated = NULL;
    history = MakeArrayDin();
    CreateQueue(&nowPlaying);
    CreateSet(&gamesList);
    CreateMap(&scoreboardRNG);
    CreateMap(&scoreboardDinerDash);
    CreateMap(&scoreboardHangman);
    CreateMap(&scoreboardTowerOfHanoi);
    CreateMap(&scoreboardSnake);
    CreateMap(&scoreboardCustomGame);

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
        else if (compQuery(query, "CREATE"))
        {
            ADVWORDSTD();
            if (compQuery(KataToString(currentKata), "GAME"))
            {
                CREATEGAME(&gamesList);
            }
            else
            {
                printf("Input tidak valid\n");
            }
        }
        else if (compQuery(query, "LIST"))
        {
            ADVWORDSTD();
            if (compQuery(KataToString(currentKata), "GAME"))
            {
                LISTGAME(gamesList);
            }
            else
            {
                printf("Input tidak valid\n");
            }
        }
        else if (compQuery(query, "DELETE"))
        {
            ADVWORDSTD();
            if (compQuery(KataToString(currentKata), "GAME"))
            {
                DELETEGAME(&gamesList, nowPlaying);
            }
            else
            {
                printf("Input tidak valid\n");
            }
        }
        else if (compQuery(query, "QUEUE"))
        {
            ADVWORDSTD();
            if (compQuery(KataToString(currentKata), "GAME"))
            {
                QUEUEGAME(gamesList, &nowPlaying);
            }
            else
            {
                printf("Input tidak valid\n");
            }
        }
        else if (compQuery(query, "PLAY"))
        {
            ADVWORDSTD();
            if (compQuery(KataToString(currentKata), "GAME"))
            {
                PLAYGAME(&nowPlaying);
            }
            else
            {
                printf("Input tidak valid\n");
            }
        }
        else if (compQuery(query, "SKIPGAME"))
        {
            SKIPGAME(&nowPlaying);
        }
        else if (compQuery(query, "HISTORY"))
        {
            HISTORY(&history);
        }
        else if (compQuery(query, "RESET"))
        {
            ADVWORDSTD();
            if (compQuery(KataToString(currentKata), "HISTORY"))
            {
                RESETHIST(&history);
            }
            else if (compQuery(KataToString(currentKata), "SCOREBOARD"))
            {
                ResetScoreboard(gamesList, &scoreboardRNG, &scoreboardDinerDash, &scoreboardHangman, &scoreboardTowerOfHanoi, &scoreboardSnake, &scoreboardCustomGame);
            }
            else
            {
                printf("Input tidak valid\n");
            }
        }
        else if (compQuery(query, "HELP"))
        {
            HELP();
        }
        else if (compQuery(query, "QUIT"))
        {
            QUITGAME();
        }
        else if (compQuery(query, "SCOREBOARD"))
        {
            SCOREBOARD(scoreboardRNG, scoreboardDinerDash, scoreboardHangman, scoreboardTowerOfHanoi, scoreboardSnake, scoreboardCustomGame);
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
    STARTWORDFILE(filename);
    if (!EOP)
    {
        /* 1. Add Games List*/
        int totalGame = WordToInt(WordToString(currentWord)), i = 0;
        while (i < totalGame)
        {
            ADVWORD();
            InsertSet(&gamesList, WordToString(currentWord));
            i++;
        }
        /* 1.2. Add History */
        ADVWORD();
        int totalHistory = WordToInt(WordToString(currentWord)), j = 0;
        while (j < totalHistory)
        {
            ADVWORD();
            InsertLast(&history, WordToString(currentWord));
            j++;
        }
        ADVWORD();
        if (!EOP)
        {
            int totalscoreRNG = WordToInt(WordToString(currentWord)), k = 0;
            while (k < totalscoreRNG)
            {
                ADVWORD();
                InsertMap(&scoreboardRNG, firstString(WordToString(currentWord)), WordToInt(secondString(WordToString(currentWord))));
                k++;
            }
            ADVWORD();
            int totalscoreDinnerDash = WordToInt(WordToString(currentWord)), l = 0;
            while (l < totalscoreDinnerDash)
            {
                ADVWORD();
                InsertMap(&scoreboardDinerDash, firstString(WordToString(currentWord)), WordToInt(secondString(WordToString(currentWord))));
                l++;
            }
            ADVWORD();
            int totalscoreHangman = WordToInt(WordToString(currentWord)), m = 0;
            while (m < totalscoreHangman)
            {
                ADVWORD();
                InsertMap(&scoreboardHangman, firstString(WordToString(currentWord)), WordToInt(secondString(WordToString(currentWord))));
                m++;
            }
            ADVWORD();
            int totalscoreHanoi = WordToInt(WordToString(currentWord)), n = 0;
            while (n < totalscoreHanoi)
            {
                ADVWORD();
                InsertMap(&scoreboardTowerOfHanoi, firstString(WordToString(currentWord)), WordToInt(secondString(WordToString(currentWord))));
                n++;
            }
            ADVWORD();
            int totalscoreSnake = WordToInt(WordToString(currentWord)), o = 0;
            while (0 < totalscoreSnake)
            {
                ADVWORD();
                InsertMap(&scoreboardSnake, firstString(WordToString(currentWord)), WordToInt(secondString(WordToString(currentWord))));
                o++;
            }
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

        /* 3. User created game */
        if (lengthSet(gamesList) > 5)
        {
            userCreated = (char *)malloc(100 * sizeof(char));
            userCreated = gamesList.Elements[5];
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
    /* Print Game */
    fprintf(file, "%d\n", lengthSet(gamesList));
    for (int i = 0; i < lengthSet(gamesList); i++)
    {
        fprintf(file, "%s\n", gamesList.Elements[i]);
    }
    /* Print History */
    if (Length(history) == 0)
    {
        fprintf(file, "%d", Length(history));
    }
    else
    {
        fprintf(file, "%d\n", Length(history));
    }

    for (int i = 0; i < Length(history); i++)
    {
        fprintf(file, "%s\n", Get(history, i));
    }
    sortedMap(&scoreboardRNG);
    sortedMap(&scoreboardDinerDash);
    sortedMap(&scoreboardHangman);
    sortedMap(&scoreboardTowerOfHanoi);
    sortedMap(&scoreboardSnake);

    /* Scoreboard RNG */
    fprintf(file, "%d\n", scoreboardRNG.Count); // Banyak data RNG
    for (int i = 0; i < scoreboardRNG.Count; i++)
    {
        fprintf(file, "%s %d\n", scoreboardRNG.Elements[i].Key, scoreboardRNG.Elements[i].Value);
    }

    /* Scoreboard DinerDash */
    fprintf(file, "%d\n", scoreboardDinerDash.Count); // Banyak data DinerDash
    for (int i = 0; i < scoreboardDinerDash.Count; i++)
    {
        fprintf(file, "%s %d\n", scoreboardDinerDash.Elements[i].Key, scoreboardDinerDash.Elements[i].Value);
    }

    /* Scoreboard Hangman */
    fprintf(file, "%d\n", scoreboardHangman.Count); // Banyak data Hangman
    for (int i = 0; i < scoreboardHangman.Count; i++)
    {
        fprintf(file, "%s %d\n", scoreboardHangman.Elements[i].Key, scoreboardHangman.Elements[i].Value);
    }

    /* Scoreboard Tower of Hanoi */
    fprintf(file, "%d\n", scoreboardTowerOfHanoi.Count); // Banyak data Tower of Hanoi
    for (int i = 0; i < scoreboardTowerOfHanoi.Count; i++)
    {
        fprintf(file, "%s %d\n", scoreboardTowerOfHanoi.Elements[i].Key, scoreboardTowerOfHanoi.Elements[i].Value);
    }

    /* Scoreboard Snake */
    fprintf(file, scoreboardSnake.Count != 0 ? "%d\n" : "%d", scoreboardSnake.Count); // Banyak data Snake
    for (int i = 0; i < scoreboardSnake.Count; i++)
    {
        fprintf(file, i < scoreboardSnake.Count - 1 ? "%s %d\n" : "%s %d", scoreboardSnake.Elements[i].Key, scoreboardSnake.Elements[i].Value);
    }

    fclose(file);

    /* 3. Print Konfig berhasil */
    printf("Save file berhasil dibuat.\n");
}
/* I.S. Sembarang */
/* F.S. Game disimpan ke file eksternal */

void CREATEGAME(Set *arr)
{
    int i = 0;
    printf("Masukkan nama game yang akan ditambahkan: ");
    /* Input Mechanism */
    char *input = readGame();
    /* End Input */

    if (!IsMember(*arr, input))
    {
        InsertSet(arr, input);
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

void LISTGAME(Set arr)
{
    int panjang = lengthSet(arr);
    int i;
    printf("List game BNMO :\n");
    if (IsEmptySet(arr))
    {
        printf("Tidak ada game yang tersedia\n");
    }
    else
    {
        for (i = 0; i < panjang; i++)
        {
            printf("%d. %s\n", i + 1, arr.Elements[i]);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Menampilkan list game yang tersedia */

void DELETEGAME(Set *arr, Queue daftargame)
{
    int nomor;
    printf("Berikut adalah daftar game yang tersedia \n");
    LISTGAME(*arr);
    printf("Masukkan nomor game yang akan dihapus: ");
    // Read angka
    STARTWORD();
    nomor = KataToInt(currentKata);
    /* Read Angka */
    if (nomor >= 1 && nomor <= lengthSet(*arr))
    {
        if (nomor >= 1 && nomor <= 5)
        {
            printf("Game gagal dihapus\n");
        }
        else
        {
            if (isInQueue((*arr).Elements[nomor - 1], daftargame))
            {
                printf("Game gagal dihapus karena sedang ada di dalam queue\n");
            }
            else
            {
                printf("Game berhasil dihapus\n");
                DeleteSet(arr, (*arr).Elements[nomor - 1]);
            }
        }
    }
    else
    {
        printf("Game gagal dihapus\n");
    }
}
/* I.S. Sembarang */
/* F.S. Menghapus game yang dipilih */

void QUEUEGAME(Set arr, Queue *daftargame)
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
    while (KataToInt(currentKata) > lengthSet(arr) || KataToInt(currentKata) < 0)
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        STARTWORD();
    }

    IdxType nomor = KataToInt(currentKata);
    IdxType i;
    ElType val;
    IdxType find = 0;

    ElType games = arr.Elements[nomor - 1];
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
        InsertLast(&history, "Diner DASH");
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = dinnerdash();
        InsertMap(&scoreboardDinerDash, username, score);
    }
    else if (compQuery(game_now, "RNG"))
    {
        InsertLast(&history, "RNG");
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = RNG(); // Karena RNG & Diner Dash dibuat dalam int() / bukan void(), jadi jalaninnya gini
        InsertMap(&scoreboardRNG, username, score);
    }
    else if (compQuery(game_now, "HANGMAN"))
    {
        InsertLast(&history, "HANGMAN");
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = hangman();
        InsertMap(&scoreboardHangman, username, score);
    }
    else if (userCreated != NULL && compQuery(game_now, userCreated))
    {
        InsertLast(&history, userCreated);
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = UserCreated();
        InsertMap(&scoreboardCustomGame, username, score);
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
            dinnerdash();
        }
        else if (compQuery(game_now, "RNG"))
        {
            printf("Loading %s ...\n\n", game_now);
            int a = RNG(); // Karena RNG & Diner Dash dibuat dalam int() / bukan void(), jadi jalaninnya gini
        }
        else if (compQuery(game_now, "HANGMAN"))
        {
            printf("Loading %s ...\n\n", game_now);
            hangman();
        }
        else if (userCreated != NULL && compQuery(game_now, userCreated))
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
                /* Print Game */
                fprintf(file, "%d\n", lengthSet(gamesList));
                for (int i = 0; i < lengthSet(gamesList); i++)
                {
                    fprintf(file, "%s\n", gamesList.Elements[i]);
                }
                /* Print History */
                if (Length(history) == 0)
                {
                    fprintf(file, "%d", Length(history));
                }
                else
                {
                    fprintf(file, "%d\n", Length(history));
                }

                for (int i = 0; i < Length(history); i++)
                {
                    fprintf(file, "%s\n", Get(history, i));
                }
                sortedMap(&scoreboardRNG);
                sortedMap(&scoreboardDinerDash);
                sortedMap(&scoreboardHangman);
                sortedMap(&scoreboardTowerOfHanoi);
                sortedMap(&scoreboardSnake);

                /* Scoreboard RNG */
                fprintf(file, "%d\n", scoreboardRNG.Count); // Banyak data RNG
                for (int i = 0; i < scoreboardRNG.Count; i++)
                {
                    fprintf(file, "%s %d\n", scoreboardRNG.Elements[i].Key, scoreboardRNG.Elements[i].Value);
                }

                /* Scoreboard DinerDash */
                fprintf(file, "%d\n", scoreboardDinerDash.Count); // Banyak data DinerDash
                for (int i = 0; i < scoreboardDinerDash.Count; i++)
                {
                    fprintf(file, "%s %d\n", scoreboardDinerDash.Elements[i].Key, scoreboardDinerDash.Elements[i].Value);
                }

                /* Scoreboard Hangman */
                fprintf(file, "%d\n", scoreboardHangman.Count); // Banyak data Hangman
                for (int i = 0; i < scoreboardHangman.Count; i++)
                {
                    fprintf(file, "%s %d\n", scoreboardHangman.Elements[i].Key, scoreboardHangman.Elements[i].Value);
                }

                /* Scoreboard Tower of Hanoi */
                fprintf(file, "%d\n", scoreboardTowerOfHanoi.Count); // Banyak data Tower of Hanoi
                for (int i = 0; i < scoreboardTowerOfHanoi.Count; i++)
                {
                    fprintf(file, "%s %d\n", scoreboardTowerOfHanoi.Elements[i].Key, scoreboardTowerOfHanoi.Elements[i].Value);
                }

                /* Scoreboard Snake */
                fprintf(file, scoreboardSnake.Count != 0 ? "%d\n" : "%d", scoreboardSnake.Count); // Banyak data Snake
                for (int i = 0; i < scoreboardSnake.Count; i++)
                {
                    fprintf(file, i < scoreboardSnake.Count - 1 ? "%s %d\n" : "%s %d", scoreboardSnake.Elements[i].Key, scoreboardSnake.Elements[i].Value);
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

void HELP()
{
    printf("============ HELP ============\n");
    printf("1. START - Mulai menjalankan BNMO\n");
    printf("2. LOAD <namafile.txt> - Untuk memuat file yang sudah disimpan\n");
    printf("3. SAVE - Untuk menyimpan state game ke dalam file yang sudah dijalankan\n");
    printf("4. CREATEGAME - Untuk menambahkan game baru\n");
    printf("5. LISTGAME - Untuk melihat list game yang tersedia dalam sistem\n");
    printf("6. DELETEGAME - Untuk menghapus game dari daftar game\n");
    printf("7. QUEUEGAME - Untuk mendaftarkan permainan ke dalam antrian Game\n");
    printf("8. PLAYGAME - Untuk memulai permainan sesuai antrian game\n");
    printf("9. SKIPGAME <nomor game> - Untuk melewati antrian game sebanyak yang diinginkan\n");
    printf("10. SCOREBOARD - Untuk melihat Scoreboard BNMO\n");
    printf("11. RESET SCOREBOARD - Untuk menghapus Scoreboard BNMO\n");
    printf("12. HISTORY - Untuk melihat riwayat game yang telah dimainkan\n");
    printf("13. RESET HISTORY - Untuk menghapus riwayat game\n");
    printf("10. QUIT - Untuk keluar dari program\n");
}
/* I.S. Sembarang */
/* F.S. Menampilkan list bantuan */

void HISTORY(ArrayDin *history)
{
    ADVWORDSTD();
    while (KataToInt(currentKata) > CAPACITY || KataToInt(currentKata) < 0)
    {
        printf("Jumlah permainan tidak valid, silahkan masukkan kembali.\n");
        STARTWORD();
    }
    printf("============ HISTORY Permainan ============\n");
    int i = 0;
    while (i < KataToInt(currentKata) && i < Length(*history))
    {
        printf("%d. %s\n", i + 1, Get(*history, i));
        i++;
    }
}

void RESETHIST(ArrayDin *history)
{
    printf("Apakah kamu yakin ingin menghapus history? Y/N\n");
    char *cmd = readQuery();
    if (compQuery(cmd, "Y") || compQuery(cmd, "YES") || compQuery(cmd, "y"))
    {
        *history = MakeArrayDin();
        printf("History berhasil direset.\n");
    }
    else
    {
        printf("History tidak jadi direset.\n");
        printf("============ HISTORY Permainan ============\n");
        int i = 0;
        while (i < KataToInt(currentKata) && i < Length(*history))
        {
            printf("%d. %s\n", i + 1, Get(*history, i));
            i++;
        }
    }
}

void SCOREBOARD(Map scoreboardRNG, Map scoreboardDinerDash, Map scoreboardHangman, Map scoreboardTowerOfHanoi, Map scoreboardSnake, Map scoreboardCustomGame)
{
    sortedMap(&scoreboardRNG);
    sortedMap(&scoreboardDinerDash);
    sortedMap(&scoreboardHangman);
    sortedMap(&scoreboardTowerOfHanoi);
    sortedMap(&scoreboardSnake);
    sortedMap(&scoreboardCustomGame);
    int panjang, i;
    i = 0;
    panjang = scoreboardRNG.Count;
    printf("**** SCOREBOARD GAME RNG ****\n");
    if (panjang == 0)
    {
        printf("------SCOREBOARD KOSONG------\n");
    }
    else
    {
        printf("|       NAMA |       SKOR |\n");
        while (i < panjang)
        {
            printf("| %-10s | %-10d |\n", scoreboardRNG.Elements[i].Key, scoreboardRNG.Elements[i].Value);
            i++;
        }
    }
    i = 0;
    panjang = scoreboardDinerDash.Count;
    printf("\n**** SCOREBOARD GAME DINER DASH ****\n");
    if (panjang == 0)
    {
        printf("------SCOREBOARD KOSONG------\n");
    }
    else
    {
        printf("|       NAMA |       SKOR |\n");
        while (i < panjang)
        {
            printf("| %-10s | %-10d |\n", scoreboardDinerDash.Elements[i].Key, scoreboardDinerDash.Elements[i].Value);
            i++;
        }
    }
    i = 0;
    panjang = scoreboardHangman.Count;
    printf("\n**** SCOREBOARD GAME HANGMAN ****\n");
    if (panjang == 0)
    {
        printf("------SCOREBOARD KOSONG------\n");
    }
    else
    {
        printf("|       NAMA |       SKOR |\n");
        while (i < panjang)
        {
            printf("| %-10s | %-10d |\n", scoreboardHangman.Elements[i].Key, scoreboardHangman.Elements[i].Value);
            i++;
        }
    }
    i = 0;
    panjang = scoreboardTowerOfHanoi.Count;
    printf("\n**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    if (panjang == 0)
    {
        printf("------SCOREBOARD KOSONG------\n");
    }
    else
    {
        printf("|       NAMA |       SKOR |\n");
        while (i < panjang)
        {
            printf("| %-10s | %-10d |", scoreboardTowerOfHanoi.Elements[i].Key, scoreboardTowerOfHanoi.Elements[i].Value);
            i++;
        }
    }
    i = 0;
    panjang = scoreboardSnake.Count;
    printf("\n**** SCOREBOARD GAME SNAKE ON METEOR ****\n");
    if (panjang == 0)
    {
        printf("------SCOREBOARD KOSONG------\n");
    }
    else
    {
        printf("|       NAMA |       SKOR |\n");
        while (i < panjang)
        {
            printf("| %-10s | %-10d |\n", scoreboardSnake.Elements[i].Key, scoreboardSnake.Elements[i].Value);
            i++;
        }
    }
    i = 0;
    panjang = scoreboardCustomGame.Count;
    printf("\n**** SCOREBOARD GAME %s ****\n", userCreated);
    if (panjang == 0)
    {
        printf("------SCOREBOARD KOSONG------\n");
    }
    else
    {
        printf("|       NAMA |       SKOR |\n");
        while (i < panjang)
        {
            printf("| %-10s | %-10d |\n", scoreboardCustomGame.Elements[i].Key, scoreboardSnake.Elements[i].Value);
            i++;
        }
    }
}

void ResetScoreboard(Set game, Map *scoreboardRNG, Map *scoreboardDinerDash, Map *scoreboardHangman, Map *scoreboardTowerOfHanoi, Map *scoreboardSnake, Map *scoreboardCustomGame)
{
    printf("DAFTAR SCOREBOARD: \n");
    printf("0. All\n");
    LISTGAME(game);
    printf("\n");
    printf("\n");
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTWORD();
    int nomor;
    nomor = KataToInt(currentKata);
    if (nomor < 0 || nomor > game.Count)
    {
        printf("Nomor yang anda masukkan tidak valid! scoreboard gagal dihapus!\n");
    }
    else if (nomor == 0)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)");
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardRNG);
            CreateMap(scoreboardDinerDash);
            CreateMap(scoreboardHangman);
            CreateMap(scoreboardTowerOfHanoi);
            CreateMap(scoreboardSnake);
            CreateMap(scoreboardCustomGame);
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
    else if (nomor == 1)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD RNG (YA/TIDAK)");
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardRNG);
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
    else if (nomor == 2)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD DINER DASH (YA/TIDAK)");
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardDinerDash);
            ;
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
    else if (nomor == 3)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD HANGMAN (YA/TIDAK)");
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardHangman);
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
    else if (nomor == 4)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD TOWER OF HANOI (YA/TIDAK)");
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardTowerOfHanoi);
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
    else if (nomor == 5)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD SNAKE ON METEOR (YA/TIDAK)");
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardSnake);
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
    else if (nomor == 6 && userCreated != NULL)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)", userCreated);
        char *cmd = readQuery();
        while (!compQuery(cmd, "YA") || !compQuery(cmd, "TIDAK"))
        {
            printf("Input Tidak Valid, silahkan ulangi (YA/TIDAK): ");
            cmd = readQuery();
        }
        if (compQuery(cmd, "YA"))
        {
            CreateMap(scoreboardCustomGame);
            printf("Scoreboard berhasil di-reset.\n");
        }
    }
}
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
boolean isInQueue(ElType str, Queue q)
{
    int len = length(q);
    int i;
    for (i = 0; i < len; i++)
    {
        if (compQuery(str, q.buffer[i]))
        {
            return true;
        }
    }
    return false;
}

char *firstString(char *text)
{
    int i = 0;
    char *first;
    first = (char *)malloc(100 * sizeof(char));
    while (text[i] != BLANK && text[i] != '\0')
    {
        *(first + i) = text[i];
        i++;
    }
    *(first + i) = '\0';
    return first;
}

char *secondString(char *text)
{
    int i = 0, j = 0;
    char *second;
    second = (char *)malloc(100 * sizeof(char));
    while (text[i] != BLANK && text[i] != '\0')
    {
        i++;
    }
    i++;
    while (text[i] != '\0' && text[i] != BLANK)
    {
        second[j] = text[i];
        i++;
        j++;
    }
    *(second + j) = '\0';
    return second;
}

void sortedMap(Map *sorted)
{
    Map temp;
    CreateMap(&temp);
    int panjang = (*sorted).Count;
    int i, j;
    char *keyTemp;
    int valueTemp;
    for (i = 0; i < panjang; i++)
    {
        for (j = i + 1; j < panjang; j++)
        {
            if ((*sorted).Elements[i].Value > (*sorted).Elements[j].Value)
            {
                keyTemp = (*sorted).Elements[i].Key;
                valueTemp = (*sorted).Elements[i].Value;
                InsertMap(&temp, keyTemp, valueTemp);

                (*sorted).Elements[i].Key = (*sorted).Elements[j].Key;
                (*sorted).Elements[i].Value = (*sorted).Elements[j].Value;

                (*sorted).Elements[j].Key = temp.Elements[0].Key;
                (*sorted).Elements[j].Value = temp.Elements[0].Value;

                DeleteMap(&temp, temp.Elements[0].Key);
            }
        }
    }
}