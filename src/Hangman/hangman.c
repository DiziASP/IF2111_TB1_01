#include "hangman.h"

boolean win;
int kesempatan, poin;
Set word;
Set answer;
char *ans, *guess;

boolean isIn(char word, char *a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == word)
        {
            return true;
        }
        i++;
    }
    return false;
}

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

    int i = 0;
    while (isIn(ans, guess))
    {
        printf("Kata sudah ditebak. Ulangi input: ");
        START();
        ans = currentChar;
    }

    return ans;
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
        int j = 0;
        while (guess[j] != '\0')
        {
            if (ans[i] == guess[j])
            {
                found = true;
                break;
            }
            j++;
        }
        if (found)
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

boolean CheckAnswer()
{
    /* Search char inside ans is in guess */
    int i = 0;
    boolean found = false;
    while (ans[i] != '\0' && !found)
    {
        int j = 0;
        while (guess[j] != '\0')
        {
            if (ans[i] == guess[j])
            {
                found = true;
                break;
            }
            j++;
        }
        i++;
    }
    if (!found)
    {
        printf("Salah tebak ya ges ya!\n");
        kesempatan--;
    }

    boolean exist = true;
    i = 0;
    while (ans[i] != '\0' && exist)
    {
        int j = 0;
        while (guess[j] != '\0' && exist)
        {
            if (ans[i] == guess[j])
            {
                break;
            }
            exist = false;
            j++;
        }
        i++;
    }
    return exist;
}

int hangman()
{
    /* Initial Booting State */
    LoadDictionary(&word, &answer);
    kesempatan = 10;
    poin = 0;
    guess = (char *)malloc(255 * sizeof(char));

    printf("Selamat datang di game hangman!\n");
    printf("CEPAT SELAMATKAN INDRA\n\n");
    printf("Kamu akan diberikan pertanyaan dan kamu harus menebak jawabannya\n");
    printf("Kamu hanya punya 10 kesempatan untuk menebak jawabannya\n");
    printf("Dalam permainan ini, kamu harus bisa menebak kata yang diberikan\n");
    printf("Jika kamu benar menebak, maka kamu akan mendapatkan poin\n");
    printf("Jika kamu sudah menebak semua pertanyaan secara berturut-turut, maka kamu akan mendapatkan poin maksimal\n\n");

    /* Main Loop */
    int questionNo = 0;
    int idx = 0;
    while (questionNo < lengthSet(word))
    {
        boolean answered = false;
        printf("Pertanyaan: %s\n", word.Elements[questionNo]);
        ans = answer.Elements[questionNo];
        while (!answered)
        {
            PrintCurrentState();
            printf("Masukkan tebakan: ");
            char tebakan = readAns();
            guess[idx] = tebakan;
            idx++;

            answered = CheckAnswer();
            if (answered)
            {
                poin += 1;
            }
        }
        questionNo++;
    }

    printf("Kamu berhasil menebak %d pertanyaan!\n", questionNo + 1);
    printf("Perolehan Skor kamu: %d\n", poin);
}

int main()
{
    /* code */
    hangman();
    return 0;
}
