#include "TowerofHanoi.h"

void pushdisk(int n, Stack *S){
    for(int i= n; i>=1 ;i--){
        Push(S, i);
    }
}

void scorer(int n, int *score, int langkah){
    int max,i, langkahmax;
    max = 1;
    for(i=0;i<n;i++){
        max = max*2;
    }
    langkahmax = max-1;
    if(langkah == langkahmax){
        *score += 2*n;
    }
    else{
        *score += n;
    }
}



int TowerofHanoi()
{
    int skor,langkah,validasi;
    skor = 0;
    langkah = 0;
    Stack A, B, C;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);
    printf("Masukkan jumlah disk: ");
    STARTWORD();
    char *x = KataToString(currentKata);
    while(!isnumber(x)){
        printf("Input tidak valid! Masukkan jumlah disk: ");
        STARTWORD();
        x = KataToString(currentKata);
        validasi = strtoint(x);
        while(validasi<=0){
            printf("Input tidak valid! Masukkan jumlah disk: ");
            STARTWORD();
            x = KataToString(currentKata);
            validasi = strtoint(x);
        }
    }
    int n = strtoint(x);
    pushdisk(n, &A);
    displaystack(A, B, C,n);
    while (lengthStack(C)!=n)
    {
        printf("TIANG ASAL: ");
        STARTWORD();
        char *asal = KataToString(currentKata);
        printf("TIANG TUJUAN: ");
        STARTWORD();
        char *tujuan = KataToString(currentKata);
        if (isvalid(asal, tujuan, &A, &B, &C) && currenkatalength(asal) == 1 && currenkatalength(tujuan) == 1)
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
    printf("Nama: ");
    STARTWORD();
    char *nama = KataToString(currentKata);
    return 0;
}