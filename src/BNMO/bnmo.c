/* File: bnmo.c */
/* Implementasi fungsi dan prosedur Game BNMO */
#include "bnmo.h"

/* Inisialisasi State */
Stack history;
Set gamesList;
Queue nowPlaying;
Map scoreboardRNG, scoreboardDinerDash, scoreboardHangman, scoreboardTowerOfHanoi, scoreboardSnake, scoreboardCustomGame;
boolean Quit, isLoad, isSave;
char *userCreated, *username;

/* ***  Fungsi Utama BNMO *** */
void MAINMENU()
{
    /* STATE INITIAL */
    char *query;
    Quit = false;
    isLoad = false;
    isSave = false;
    userCreated = NULL;
    CreateStack(&history);
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
        printf("\n");
        if (IsStringEqual(query, "START") && !isLoad)
        {
            STARTGAME("config.txt");
        }
        else if (IsStringEqual(query, "LOAD") && !isLoad)
        {
            ADVWORD();
            query = KataToString(currentKata);
            if (!ContainStr(query, ".txt"))
            {
                printf("File tidak valid. Silahkan ulangi Input\n");
            }
            else
            {
                STARTGAME(query);
            }
        }
        else if (isLoad)
        {
            if (IsStringEqual(query, "CREATE"))
            {
                ADVWORD();
                query = KataToString(currentKata);
                if (!IsStringEqual(query, "GAME"))
                {
                    printf("Perintah tidak valid. Silahkan ulangi Input\n");
                }
                else
                {
                    CREATEGAME(&gamesList);
                }
            }
            else if (IsStringEqual(query, "SAVE"))
            {
                ADVWORD();
                char *userInput = KataToString(currentKata);
                // Check input valid
                while (!ContainStr(userInput, ".txt"))
                {
                    printf("Input tidak valid. Ulangi kembali: \n");
                    STARTWORD();
                    userInput = KataToString(currentKata);
                }
                SAVEGAME(userInput);
            }
            else if (IsStringEqual(query, "DELETE"))
            {
                ADVWORD();
                query = KataToString(currentKata);
                if (!IsStringEqual(query, "GAME"))
                {
                    printf("Perintah tidak valid. Silahkan ulangi Input\n");
                }
                else
                {
                    DELETEGAME(&gamesList, nowPlaying);
                }
            }
            else if (IsStringEqual(query, "LIST"))
            {
                ADVWORD();
                query = KataToString(currentKata);
                if (!IsStringEqual(query, "GAME"))
                {
                    printf("Perintah tidak valid. Silahkan ulangi Input\n");
                }
                else
                {
                    LISTGAME(gamesList);
                }
            }
            else if (IsStringEqual(query, "QUEUE"))
            {
                ADVWORD();
                query = KataToString(currentKata);
                if (!IsStringEqual(query, "GAME"))
                {
                    printf("Perintah tidak valid. Silahkan ulangi Input\n");
                }
                else
                {
                    QUEUEGAME(gamesList, &nowPlaying);
                }
            }
            else if (IsStringEqual(query, "PLAY"))
            {
                ADVWORD();
                query = KataToString(currentKata);
                if (!IsStringEqual(query, "GAME"))
                {
                    printf("Perintah tidak valid. Silahkan ulangi Input\n");
                }
                else
                {
                    PLAYGAME(&nowPlaying);
                }
            }
            else if (IsStringEqual(query, "SKIPGAME"))
            {
                SKIPGAME(&nowPlaying);
            }
            else if (IsStringEqual(query, "HISTORY"))
            {
                HISTORY(history);
            }
            else if (IsStringEqual(query, "SCOREBOARD"))
            {
                SCOREBOARD(scoreboardRNG, scoreboardDinerDash, scoreboardHangman, scoreboardTowerOfHanoi, scoreboardSnake, scoreboardCustomGame);
            }
            else if (IsStringEqual(query, "RESET"))
            {
                ADVWORD();
                query = KataToString(currentKata);
                if (IsStringEqual(query, "HISTORY"))
                {
                    RESETHIST(&history);
                }
                else if (IsStringEqual(query, "SCOREBOARD"))
                {
                    ResetScoreboard(gamesList, &scoreboardRNG, &scoreboardDinerDash, &scoreboardHangman, &scoreboardTowerOfHanoi, &scoreboardSnake, &scoreboardCustomGame);
                }
                else
                {
                    printf("Perintah tidak valid. Silahkan ulangi Input\n");
                }
            }
            else if (IsStringEqual(query, "HELP"))
            {
                HELP();
            }
            else if (IsStringEqual(query, "QUIT"))
            {
                QUITGAME();
            }
        }
        else
        {
            printf("Input tidak valid. Silahkan coba kembali\n");
        }
        if (isLoad)
        {
            MMSCREEN();
        }
        if (!Quit)
        {
            printf("\n");
            query = readQuery();
        }
    }
}
/* Print main menu */

void STARTGAME(char *userFile)
{
    /* 1. Read Games List */
    char *filename = (char *)malloc(100 * sizeof(char));
    concatStr("data/", userFile, filename);
    STARTCONFIG(filename);
    if (!IsEOP())
    {
        /* 1.1 Add Games List*/
        int totalGame = KataToInt(currentKata), i = 0;
        while (i < totalGame)
        {
            ADVCONFIG();
            InsertSet(&gamesList, KataToString(currentKata));
            i++;
        }
        /* 1.2. Add History */
        ADVCONFIG();
        int totalHistory = KataToInt(currentKata), j = 0;
        while (j < totalHistory)
        {
            ADVCONFIG();
            PushStack(&history, KataToString(currentKata));
            j++;
        }
        /* 2. Print Konfig berhasil */
        if (IsStringEqual(userFile, "config.txt"))
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
    if (currentChar == MARK)
    {
        printf("Input invalid\n");
    }
    else
    {
        ADVWORD();
        char *userFile = KataToString(currentKata);
        STARTGAME(userFile);
    }
}
/* I.S. Sembarang */
/* F.S. Game dilanjutkan dari file eksternal */

void SAVEGAME(char *userInput)
{
    /* 1. Save Games List */
    char *filename = (char *)malloc(100 * sizeof(char));
    concatStr("data/", userInput, filename);
    FILE *file = fopen(filename, "w");
    /* Print Game */
    fprintf(file, "%d\n", lengthSet(gamesList));
    for (int i = 0; i < lengthSet(gamesList); i++)
    {
        fprintf(file, "%s\n", gamesList.Elements[i]);
    }
    /* Print History */
    if (Top(history) + 1 == 0)
    {
        fprintf(file, "%d", 0);
    }
    else
    {
        fprintf(file, "%d\n", Top(history) + 1);
    }

    Stack temp = history;
    while (!IsEmptyStack(temp))
    {
        infotype x;
        PopStack(&temp, &x);
        fprintf(file, "%s\n", x);
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
    printf("Masukkan nama game yang akan ditambahkan (tanpa spasi)\n");
    /* Input Mechanism */
    char *input = readQuery();
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
    int score = 0;
    dequeue(daftargame, &game_now);
    if (IsStringEqual(game_now, "Diner DASH"))
    {
        // Mainkan Diner Dash
        PushStack(&history, "Diner DASH");
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = dinnerdash();
        InsertMap(&scoreboardDinerDash, username, score);
    }
    else if (IsStringEqual(game_now, "RNG"))
    {
        PushStack(&history, "RNG");
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = RNG(); // Karena RNG & Diner Dash dibuat dalam int() / bukan void(), jadi jalaninnya gini
        InsertMap(&scoreboardRNG, username, score);
    }
    else if (IsStringEqual(game_now, "HANGMAN"))
    {
        PushStack(&history, "HANGMAN");
        printf("Loading %s ...\n\n", game_now);
        printf("Masukkan Username (tanpa spasi)\n");
        username = readQuery();
        int score = hangman();
        InsertMap(&scoreboardHangman, username, score);
    }
    else if (userCreated != NULL && IsStringEqual(game_now, userCreated))
    {
        PushStack(&history, userCreated);
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
    ADVWORD();
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
        if (IsStringEqual(game_now, "Diner DASH"))
        {
            // Mainkan Diner Dash
            printf("Loading %s ...\n\n", game_now);
            printf("Masukkan Username (tanpa spasi)\n");
            username = readQuery();
            int score = dinnerdash();
            InsertMap(&scoreboardDinerDash, username, score);
        }
        else if (IsStringEqual(game_now, "RNG"))
        {
            printf("Loading %s ...\n\n", game_now);
            printf("Masukkan Username (tanpa spasi)\n");
            username = readQuery();
            int score = RNG(); // Karena RNG & Diner Dash dibuat dalam int() / bukan void(), jadi jalaninnya gini
            InsertMap(&scoreboardRNG, username, score);
        }
        else if (IsStringEqual(game_now, "HANGMAN"))
        {
            printf("Loading %s ...\n\n", game_now);
            printf("Masukkan Username (tanpa spasi)\n");
            username = readQuery();
            int score = hangman();
            InsertMap(&scoreboardHangman, username, score);
        }
        else if (userCreated != NULL && IsStringEqual(game_now, userCreated))
        {
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
    else
    {
        printf("Tidak ada lagi permainan dalam daftar game-mu.\n");
    }
}
/* I.S. Sembarang */
/* F.S. Melewati giliran game dalam queue */

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

void QUITGAME()
{
    printf("Apakah kamu yakin? Y/N\n");
    char *cmd = readQuery();

    if (IsStringEqual(cmd, "Y") || IsStringEqual(cmd, "YES") || IsStringEqual(cmd, "y"))
    {
        printf("Terima Kasih sudah bermain :D\n");
        Quit = true;
    }
}
/* I.S. Sembarang */
/* F.S. Keluar dari game */

void HISTORY(Stack history)
{

    printf("============ HISTORY Permainan ============\n");
    Stack temp = history;
    int i = 0;
    while (!IsEmptyStack(temp))
    {
        infotype X;
        PopStack(&temp, &X);
        printf("%d. %s\n", i + 1, X);
        i++;
    }
}

void RESETHIST(Stack *history)
{
    printf("Apakah kamu yakin ingin menghapus history? Y/N\n");
    char *cmd = readQuery();
    if (IsStringEqual(cmd, "Y") || IsStringEqual(cmd, "YES") || IsStringEqual(cmd, "y"))
    {
        CreateStack(history);
        printf("History berhasil direset.\n");
    }
    else
    {
        printf("History tidak jadi direset.\n");
        HISTORY(*history);
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
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)\n");
        char *cmd = readQuery();
        if (IsStringEqual(cmd, "YA"))
        {
            CreateMap(scoreboardRNG);
            CreateMap(scoreboardDinerDash);
            CreateMap(scoreboardHangman);
            CreateMap(scoreboardTowerOfHanoi);
            CreateMap(scoreboardSnake);
            CreateMap(scoreboardCustomGame);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
    else if (nomor == 1)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD RNG (YA/TIDAK)\n");
        char *cmd = readQuery();

        if (IsStringEqual(cmd, "YA"))
        {
            CreateMap(scoreboardRNG);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
    else if (nomor == 2)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD DINER DASH (YA/TIDAK)\n");
        char *cmd = readQuery();

        if (IsStringEqual(cmd, "Y") || IsStringEqual(cmd, "YES") || IsStringEqual(cmd, "y"))
        {
            CreateMap(scoreboardDinerDash);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "N") || IsStringEqual(cmd, "NO") || IsStringEqual(cmd, "n"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
    else if (nomor == 3)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD HANGMAN (YA/TIDAK)\n");
        char *cmd = readQuery();

        if (IsStringEqual(cmd, "YA"))
        {
            CreateMap(scoreboardHangman);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
    else if (nomor == 4)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD TOWER OF HANOI (YA/TIDAK)\n");
        char *cmd = readQuery();
        if (IsStringEqual(cmd, "YA"))
        {
            CreateMap(scoreboardTowerOfHanoi);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
    else if (nomor == 5)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD SNAKE ON METEOR (YA/TIDAK)\n");
        char *cmd = readQuery();

        if (IsStringEqual(cmd, "YA"))
        {
            CreateMap(scoreboardSnake);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
    else if (nomor == 6 && userCreated != NULL)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)\n", userCreated);
        char *cmd = readQuery();
        if (IsStringEqual(cmd, "YA"))
        {
            CreateMap(scoreboardCustomGame);
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (IsStringEqual(cmd, "TIDAK"))
        {
            printf("Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
        else
        {
            printf("Perintah tidak valid! Scoreboard tidak jadi di-reset.\n");
            SCOREBOARD(*scoreboardRNG, *scoreboardDinerDash, *scoreboardHangman, *scoreboardTowerOfHanoi, *scoreboardSnake, *scoreboardCustomGame);
        }
    }
}

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

/* Miscellanous Functions and Procedures */
void WELCOMESCREEN()
{
    char *filename = "src/ASCIIArt/welcome.txt";
    STARTCONFIG(filename);

    while (!IsEOP())
    {
        printf("%s\n", KataToString(currentKata));
        ADVCONFIG();
    }
    printf("%s\n", KataToString(currentKata));
}

void MMSCREEN()
{
    char *filename = "src/ASCIIArt/menu.txt";
    STARTCONFIG(filename);

    while (!IsEOP())
    {
        printf("%s\n", KataToString(currentKata));
        ADVCONFIG();
    }
    printf("%s\n", KataToString(currentKata)); // LastKata
}

char *readQuery()
{
    /* Command Parsing */
    printf("Masukkan perintah: ");
    STARTWORD();
    char *query = KataToString(currentKata);

    return query;
}