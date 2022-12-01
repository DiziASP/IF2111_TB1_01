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
    printf("Berikut adalah Pohon Angka kamu:\n");
    PrintTree(tree, 2);

    /* Game */
    question_node = generate_question();
    printf("Angka berapa yang dihasilkan node %d: ", question_node);

    int kunjaw = check_answer(tree, question_node);
    int answer;

    scanf("%d", &answer);
    while (answer != kunjaw)
    {
        score -= 10;
        printf("Salah! Coba lagi: ");
        scanf("%d", &answer);
    }
    printf("Kamu berhasil menebak angka %d!\n", kunjaw);
    printf("Score kamu: %d\n", score);
    return score;
}