#include "TowerofHanoi.h"
#include <math.h>
void pushdisk(int n, StackHanoi *S)
{
    for (int i = n; i >= 1; i--)
    {
        PushHanoi(S, i);
    }
}

void scorer(int n, int *score, int langkah)
{
    int max, i, langkahmax;
    max = 1;
    for (i = 0; i < n; i++)
    {
        max = max * 2;
    }
    langkahmax = max - 1;
    if (langkah == langkahmax)
    {
        *score += 2 * n;
    }
    else
    {
        *score += n;
    }
}

int TowerofHanoi()
{
    int skor, langkah;
    skor = 0;
    StackHanoi A, B, C;
    CreateHanoi(&A);
    CreateHanoi(&B);
    CreateHanoi(&C);
    printf("Masukkan jumlah disk: ");
    STARTWORD();
    char *x = KataToString(currentKata);
    while (!isnumber(x))
    {
        printf("Input tidak valid! Masukkan jumlah disk: ");
        STARTWORD();
        x = KataToString(currentKata);
    }
    int n = strtoint(x);
    pushdisk(n, &A);
    displayStackHanoi(A, B, C, n);
    while (lengthStackHanoi(C) != n)
    {
        printf("TIANG ASAL: ");
        STARTWORD();
        char *asal = KataToString(currentKata);
        printf("TIANG TUJUAN: ");
        STARTWORD();
        char *tujuan = KataToString(currentKata);
        if (isvalid(asal, tujuan, &A, &B, &C))
        {
            move(asal, tujuan, &A, &B, &C, n);
            langkah++;
        }
        else
        {
            printf("Tidak bisa dipindahkan\n");
        }
    }
    scorer(n, &skor, langkah);
    printf("Skor didapatkan : %d\n", skor);
    return skor;
}