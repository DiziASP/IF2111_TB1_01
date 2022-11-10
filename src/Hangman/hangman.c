#include "hangman.h"

boolean win;
int babak;
ArrayDin word;
ArrayDin answer;
ArrayDin wordGuess;

void Question()
{
    word = MakeArrayDin();
    answer = MakeArrayDin();
    wordGuess = MakeArrayDin();
    /* Generate Question */
    char *question1 = "'if' statement tergolong sebagai statement...";
    char *answer1 = "percabangan";
    char *answerGuess1 = "per_ab_n__n";
    InsertLast(&word, question1);
    InsertLast(&answer, answer1);
    InsertLast(&wordGuess, answerGuess1);

    char *question2 = "Badannya besar, tangannya kecil kalau mengaum yang lain langsung...";
    char *answer2 = "mundur";
    char *answerGuess2 = "m_n__r";
    InsertLast(&word, question2);
    InsertLast(&answer, answer2);
    InsertLast(&wordGuess, answerGuess2);

    char *question3 = "Kalau sigma tidak diketahui, maka digunakan distribusi...";
    char *answer3 = "t-distribution";
    char *answerGuess3 = "_-d__tr_bu__n";
    InsertLast(&word, question3);
    InsertLast(&answer, answer3);
    InsertLast(&wordGuess, answerGuess3);

    char *question4 = "Kalau misalnya crush kita udah suka sama yang lain, sebagai makhluk yang beradab dan berakal maka kita harus...";
    char *answer4 = "tikung";
    char *answerGuess4 = "__kung";
    InsertLast(&word, question4);
    InsertLast(&answer, answer4);
    InsertLast(&wordGuess, answerGuess4);

    char *question5 = "Apaan tuh?...";
    char *answer5 = "yntkts";
    char *answerGuess5 = "y_k__s";
    InsertLast(&word, question5);
    InsertLast(&answer, answer5);
    InsertLast(&wordGuess, answerGuess5);

    char *question6 = "Siapa asprak terfavorit alstrukdat? (hint:kita semua tau :D)...";
    char *answer6 = "kak-ace";
    char *answerGuess6 = "kak-___";
    InsertLast(&word, question6);
    InsertLast(&answer, answer6);
    InsertLast(&wordGuess, answerGuess6);

    char *question7 = "Siapa asprak terwibu alstrukdat? (hint:sering baca manga di sekre)...";
    char *answer7 = "kak-feihan";
    char *answerGuess7 = "kak-f_____";
    InsertLast(&word, question7);
    InsertLast(&answer, answer7);
    InsertLast(&wordGuess, answerGuess7);
}

boolean compuare(char *query, char *command)
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

char *reaued()
{

    printf("Masukkan jawaban: ");
    STARTWORD();
    return KataToString(currentKata);
}

void hangman()
{
    babak = 1;
    win = false;
    int streak = 0;
    Question();
    /* Selamat datang di game hengmen */
    printf("Selamat datang di game hangman!\n");
    printf("CEPAT SELAMATKAN INDRA\n\n");
    printf("Kamu akan diberikan pertanyaan dan kamu harus menebak jawabannya\n");
    printf("Kamu hanya punya 7 kesempatan untuk menebak jawabannya\n");
    printf("Jika kamu salah menebak, maka kamu akan lanjut ke pertanyaan selanjutnya\n");
    printf("Jika kamu benar menebak, maka kamu akan mendapatkan poin\n");
    printf("Jika kamu sudah menebak 4 pertanyaan secara berturut-turut, maka kamu menang\n\n");

    while (babak <= 7 && !win)
    {
        printf("Round : %d | Streak : %d\n", babak, streak);
        printf("Pertanyaan %d: %s\n", babak, Get(word, babak - 1));
        printf("Clue: %s\n", Get(wordGuess, babak - 1));

        char *input = (char *)malloc(100 * sizeof(char));
        input = reaued();
        if (compuare(input, Get(answer, babak - 1)))
        {
            printf("Jawaban kamu benar!\n");
            printf("Jawaban yang benar adalah %s\n", Get(answer, babak - 1));
            babak++;
            streak++;
            if (streak == 4)
            {
                win = true;
            }
        }
        else
        {
            printf("Jawaban kamu salah!\n");
            printf("Jawaban yang benar adalah %s\n", Get(answer, babak - 1));
            babak++;
            streak = 0;
        }
        printf("\n");
    }

    if (win)
    {
        printf("Selamat kamu menang!\n");
        printf("Skor kamu: %d\n", streak);
    }
    else
    {
        printf("Kamu kalah, git gud ya dek!\n");
        printf("Skor kamu: %d\n", streak);
    }
}
