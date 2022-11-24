#include "TowerofHanoi.h"

int TowerofHanoi()
{
    int skor,langkah;
    Stack A, B, C;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);
    Push(&A, 9);
    Push(&A, 7);
    Push(&A, 5);
    Push(&A, 3);
    Push(&A, 1);
    displaystack(A, B, C);
    while (!IsFull(C))
    {
        printf("TIANG ASAL: ");
        STARTWORD();
        char *asal = KataToString(currentKata);
        printf("TIANG TUJUAN: ");
        STARTWORD();
        char *tujuan = KataToString(currentKata);
        if (isvalid(asal, tujuan, &A, &B, &C))
        {
            move(asal, tujuan, &A, &B, &C);
            langkah++;
        }
        else
        {
            printf("Tidak bisa dipindahkan\n");
        }
    }
    if (IsFull(C) && langkah == 31)
    {
        printf("Kamu berhasil!\n\n");
        skor = skor + 10;
    }
    else if (IsFull(C) && langkah > 31 && langkah < 40)
    {
        printf("Kamu berhasil!\n\n");
        skor = skor + 7;
    }
    else if(IsFull(C) && langkah > 40 && langkah < 50)
    {
        printf("Kamu berhasil!\n\n");
        skor = skor + 5;
    }
    else if(IsFull(C) && langkah > 50 && langkah <60)
    {
        printf("Kamu berhasil!\n\n");
        skor = skor + 3;
    }
    else
    {
        printf("Kamu berhasil\n\n");
        skor = skor + 1;
    }
    
    printf("Skor didapatkan : %d\n", skor);

    return 0;
}