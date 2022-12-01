#include "hangman.h"

boolean QUIT;
int kesempatan, poin;
Set word;
Set answer;
char *guess;
char *ans;

char *readInput()
{
    /* Command Parsing */
    START();
    char *query = (char *)malloc(255 * sizeof(char));
    int i = 0;
    while (currentChar != MARK)
    {
        query[i] = currentChar;
        i++;
        ADV();
    }
    query[i] = '\0';
    return query;
}

char readAns()
{
    START();
    char ans = currentChar;
    while (currentChar != '\n')
    {
        ADV();
    }

    return ans;
}

boolean IsIn(char *defAns, char userGuess)
{
    int i = 0;
    while (defAns[i] != '\0')
    {
        if (defAns[i] == userGuess)
        {
            return true;
        }
        i++;
    }
    return false;
}

void SaveDictionary(Set word, Set answer)
{
    FILE *fp = fopen("data/hangman.txt", "w");
    fprintf(fp, "%d\n", lengthSet(word));
    for (int i = 0; i < lengthSet(word); i++)
    {
        fprintf(fp, "%s\n", word.Elements[i]);
    }

    fprintf(fp, "%d\n", lengthSet(answer));
    for (int i = 0; i < lengthSet(answer); i++)
    {
        fprintf(fp, i < lengthSet(answer) - 1 ? "%s\n" : "%s", answer.Elements[i]);
    }
}

void LoadDictionary(Set *question, Set *boi)
{
    STARTCONFIG("data/hangman.txt");
    if (!IsEOP())
    {
        int totalQ = KataToInt(currentKata), i = 0;
        while (i < totalQ)
        {
            ADVCONFIG();
            InsertSet(question, KataToString(currentKata));
            i++;
        }

        ADVCONFIG();
        int totalA = KataToInt(currentKata), j = 0;
        while (j < totalA)
        {
            ADVCONFIG();
            InsertSet(boi, KataToString(currentKata));
            j++;
        }
    }
}

void AddDictionary(Set *word, Set *answer)
{
    char *kata = (char *)malloc(255 * sizeof(char));
    printf("Masukkan kata: ");
    kata = readInput();
    InsertSet(word, kata);
    printf("Masukkan jawaban: ");
    kata = readInput();
    InsertSet(answer, kata);
}

void PrintCurrentState()
{
    printf("Tebakan sebelumnya: ");
    int j = 0;
    while (guess[j] != '\0')
    {
        printf("%c", guess[j]);
        j++;
    }
    printf("\n");

    printf("Kata: ");
    int i = 0;
    while (ans[i] != '\0')
    {
        /* Check Guessed Word*/
        boolean found = false;
        if (IsIn(guess, ans[i]) || ans[i] == '-')
        {
            printf("%c", ans[i]);
        }
        else
        {
            printf("_");
        }
        i++;
    }
    printf("\n");

    printf("Kesempatan: %d\n", kesempatan);
    printf("Poin: %d\n", poin);
    printf("\n");
}

boolean CheckAnswer(char useranswer)
{
    /* Search char inside ans is in guess */
    int i = 0;
    boolean found = false;

    while (ans[i] != '\0')
    {
        if (ans[i] == useranswer)
        {
            found = true;
            break;
        }
        i++;
    }

    if (!found)
    {
        printf("Salah tebak ya ges ya!\n");
        kesempatan--;
    }

    found = false;

    /* Check if user already guess the word */
    i = 0;
    while (ans[i] != '\0')
    {
        if (IsIn(guess, ans[i]))
        {
            found = true;
        }
        else
        {
            found = false;
            break;
        }
        i++;
    }
    return found;
}

int hangman()
{
    /* Initial Booting State */
    CreateSet(&word);
    CreateSet(&answer);

    LoadDictionary(&word, &answer);
    kesempatan = 10;
    poin = 0;
    QUIT = false;

    printf("Selamat datang di game hangman!\n");
    printf("CEPAT SELAMATKAN INDRA\n\n");
    printf("Kamu akan diberikan pertanyaan dan kamu harus menebak jawabannya\n");
    printf("Kamu hanya punya 10 kesempatan untuk menebak jawabannya\n");
    printf("Dalam permainan ini, kamu harus bisa menebak kata yang diberikan\n");
    printf("Jika kamu benar menebak, maka kamu akan mendapatkan poin\n");
    printf("Jika kamu sudah menebak semua pertanyaan secara berturut-turut, maka kamu akan mendapatkan poin maksimal\n\n");

    printf("Menu: \n");
    printf("1. Mulai permainan\n");
    printf("2. Tambahkan pertanyaan\n");
    printf("3. Keluar\n");

    /* Main Loop */
    while (!QUIT)
    {
        printf("Masukkan pilihan: ");
        char cmd = readAns();

        if (cmd == '1')
        {
            int questionNo = 0;
            while (questionNo < lengthSet(word) && kesempatan > 0)
            {
                boolean answered = false;
                printf("Pertanyaan: %s\n", word.Elements[questionNo]);
                ans = answer.Elements[questionNo];
                guess = (char *)malloc(255 * sizeof(char));
                guess[0] = '\0';
                int idx = 0;
                while (!answered && !(kesempatan == 0))
                {

                    PrintCurrentState();
                    printf("Jawaban: ");
                    char userAns = readAns();
                    if (IsIn(guess, userAns))
                    {
                        printf("Kamu sudah pernah menebak huruf ini!\n");
                    }
                    else
                    {
                        guess[idx] = userAns;
                        guess[idx + 1] = '\0';
                        idx++;
                        answered = CheckAnswer(userAns);
                        if (answered)
                        {
                            printf("\n\nYeyyy ketebak!\n");
                            printf("Jawabannya adalah: %s\n\n", ans);
                            poin += 10;
                            free(guess);
                        }
                    }
                }
                questionNo++;
            }

            printf("Perolehan Skor kamu: %d\n", poin);
            QUIT = true;
        }
        else if (cmd == '2')
        {
            AddDictionary(&word, &answer);
            PrintSet(word);
            PrintSet(answer);

            printf("Pertanyaan berhasil ditambahkan!\n");
        }
        else if (cmd == '3')
        {
            QUIT = true;
        }
        else
        {
            printf("Command tidak valid. Ulangi Kembali!\n");
        }
    }
    printf("Terima kasih sudah bermain henkmen...!\n");
    SaveDictionary(word, answer);

    return poin;
}