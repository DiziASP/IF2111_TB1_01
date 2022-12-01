#include "UserCreated.h"

BinTree tree;
int question_node;

int generate_num()
{
    int x = rand() % 100;
    return x;
}

BinTree CreateTree(int n)
{
    addrNode P;
    BinTree L, R;
    infotree X;
    int nL, nR;

    if (n == 0)
    {
        return NilRec;
    }
    else
    {
        X = generate_num();
        P = AlokNode(X);
        if (P != NilRec)
        {
            nL = n / 2;
            nR = n - nL - 1;
            L = CreateTree(nL);
            R = CreateTree(nR);
            Left(P) = L;
            Right(P) = R;
        }
        return P;
    }
}

int generate_question()
{
    /* Find the possible num inside Tree */
    int x = rand() % 100;

    while (!BSearch(tree, x))
    {
        x = rand() % 100;
    }

    return x;
}

int check_answer(BinTree P, int x)
{
    if (Akar(P) == x)
    {
        return 0;
    }
    else
    {
        if (BSearch(Left(P), x))
        {
            return 1 + (2 * check_answer(P->left, x));
        }
        else if (BSearch(Right(P), x))
        {
            return 2 * check_answer(P->right, x);
        }
        else
        {
            return -1;
        }
    }
}

int UserCreated()
{
    /* Initial States */
    srand(time(NULL));
    int score = 100;
    tree = CreateTree(15);

    /* Welcome */
    printf("       _-_\n");
    printf("    /~~   ~~\\\n");
    printf(" /~~         ~~\\\n");
    printf("{               }\n");
    printf(" \\  _-     -_  /\n");
    printf("   ~  \\ //  ~\n");
    printf("_- -   | | _- _\n");
    printf("  _ -  | |   -_\n");
    printf("      // \\\n");

    printf("Welcome to the TREE OF LIFE!\n\n");
    /* Aturan Permainan */
    printf("Rules:\n");
    printf("1. Kamu akan diberikan sebuah tree dengan 13 Node.\n");
    printf("Setiap Node akan memiliki angka yang unik.\n");
    printf("Contoh:\n");
    printf("17 <- Node Akar\n");
    printf("  57 <- Node Kiri 1\n");
    printf("    49<- Node Kiri 2\n");
    printf("      1 <- Node Kiri 3\n");
    printf("      78 <- Node Kanan 3\n");
    printf("    11 <- Node Kanan 2\n");
    printf("      81 <- Node Kiri 3\n");
    printf("      9 <- Node Kanan 3\n");
    printf("  41 <- Node Kanan 1\\\n");
    printf("    1 <- Node Kiri 2\n");
    printf("      37 <- Node Kiri 3\n");
    printf("      86 <- Node Kanan 3\n");
    printf("    97 <- Node Kanan 2\n");
    printf("      4 <- Node Kiri 3\n");
    printf("      7 <- Node Kanan 3\n");
    printf("2. Kamu akan diberikan salah satu node dari tree tersebut yang dapat menghasilkan jawaban dan kamu harus menebak jawaban apa yang akan dihasilkan oleh node itu\n");
    printf("3. Bila node penghasil jawaban ada di tree kanan maka rekursif akan berjalan ke kanan dengan hasil 2 * (hasil fungsi rekursif)\n");
    printf("4. Bila node penghasil jawaban ada di tree kiri maka rekursif akan berjalan ke kiri dengan hasil 1 + (2 * (hasil fungsi rekursif))\n");
    printf("5. Bila node penghasil jawaban adalah node akar (basis) maka rekursif akan berhenti dan menghasilkan nilai 0\n");
    printf("6. Contoh:\n");
    printf("Angka berapa yang dihasilkan node 41?\n");
    printf("Jawaban: 0\n");
    printf("Karena 41 ada di akar kanan sehingga perkaliannya akan menjadi 2 * (0)\n");
    printf("7. Setiap jawaban salah akan mengurangi poin hingga 0. (jadi jgn kalah yh)\n");
    printf("\nBerikut adalah Pohon Angka kamu:\n");
    PrintTree(tree, 2);

    /* Game */
    question_node = generate_question();
    printf("Angka berapa yang dihasilkan node %d: ", question_node);

    int kunjaw = check_answer(tree, question_node);
    int answer;

    scanf("%d", &answer);
    while (answer != kunjaw && score > 0)
    {
        score -= 10;
        printf("Salah! Coba lagi! (Score: %d)\n", score);
        scanf("%d", &answer);
    }
    printf("Kamu berhasil menebak angka %d!\n", kunjaw);
    printf("Score kamu: %d\n", score);
    return score;
}