/* File : Stack.h */
/* deklarasi Stackyang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "StackofHanoi.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateHanoi(StackHanoi *S)
{
    int i;
    for (i = 0; i < MaxHanoi; i++)
    {
        (*S).T[i] = NilHanoi;
    }
    (*S).TOP = NilHanoi;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHanoi S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StackHanoi kosong : TOP berNilHanoiai NilHanoi */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHanoi(StackHanoi S)
{
    return (TopHanoi(S) == NilHanoi);
}
/* Mengirim true jika StackHanoi kosong: lihat definisi di atas */
boolean IsFullHanoi(StackHanoi S)
{
    return (TopHanoi(S) == MaxHanoi - 1);
}
/* Mengirim true jika tabel penampung NilHanoiai elemen StackHanoi penuh */

/* ************ Menambahkan sebuah elemen ke StackHanoi ************ */
void PushHanoi(StackHanoi *S, infohanoi X)
{
    if (IsFullHanoi(*S))
    {
        printf("StackHanoi penuh\n");
    }
    else
    {
        TopHanoi(*S)++;
        InfoTopHanoi(*S) = X;
    }
}
/* Menambahkan X sebagai elemen StackHanoi S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHanoi TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackHanoi ************ */
void PopHanoi(StackHanoi *S, infohanoi *X)
{
    if (IsEmptyHanoi(*S))
    {
        printf("StackHanoi kosong\n");
    }
    else
    {
        *X = InfoTopHanoi(*S);
        InfoTopHanoi(*S) = NilHanoi;
        TopHanoi(*S)--;
    }
}

void displayStackHanoi(StackHanoi A, StackHanoi B, StackHanoi C, int n)
{
    int i;
    for (int i = n - 1; i >= 0; i--)
    {
        inttodisk(A.T[i], n);
        inttodisk(B.T[i], n);
        inttodisk(C.T[i], n);
        printf("\n");
    }
    displaygaris(A, n);
    displaygaris(B, n);
    displaygaris(C, n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    printf("A");
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    printf("B");
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    printf("C");
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
    printf("\n\n");
}

void displaygaris(StackHanoi s, int n)
{
    int i;
    int lenspace = 2 * n + 1;
    if (IsEmptyHanoi(s))
    {
        for (i = 0; i < (lenspace - 3) / 2; i++)
        {
            printf(" ");
        }
        printf("---");
        for (i = 0; i < (lenspace - 3) / 2; i++)
        {
            printf(" ");
        }
    }
    else
    {
        for (i = 0; i < (lenspace - 7) / 2; i++)
        {
            printf(" ");
        }
        printf("-------");
        for (i = 0; i < (lenspace - 7) / 2; i++)
        {
            printf(" ");
        }
    }
}

void inttodisk(int x, int n)
{
    int i, j;
    int lendisk = 2 * x - 1;
    int lenspace = ((2 * n + 1) - lendisk) / 2;

    if (x != NilHanoi)
    {
        for (i = 0; i < lenspace; i++)
        {
            printf(" ");
        }
        for (i = 0; i < lendisk; i++)
        {
            printf("*");
        }
        for (i = 0; i < lenspace; i++)
        {
            printf(" ");
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf(" ");
        }
        printf("|");
        for (i = 0; i < n; i++)
        {
            printf(" ");
        }
    }
}

void move(char *asal, char *tujuan, StackHanoi *A, StackHanoi *B, StackHanoi *C, int n)
{
    infohanoi x;
    if (*asal == 'A' && !IsEmptyHanoi(*A))
    {
        PopHanoi(A, &x);
        if (*tujuan == 'B')
        {
            PushHanoi(B, x);
            printf("Memindahkan piringan ke B...\n\n\n");
        }
        else if (*tujuan == 'C')
        {
            PushHanoi(C, x);
            printf("Memindahkan piringan ke C...\n\n\n");
        }
    }
    else if (*asal == 'B' && !IsEmptyHanoi(*B))
    {
        PopHanoi(B, &x);
        if (*tujuan == 'A')
        {
            PushHanoi(A, x);
            printf("Memindahkan piringan ke A...\n\n\n");
        }
        else if (*tujuan == 'C')
        {
            PushHanoi(C, x);
            printf("Memindahkan piringan ke C...\n\n\n");
        }
    }
    else if (*asal == 'C' && !IsEmptyHanoi(*C))
    {
        PopHanoi(C, &x);
        if (*tujuan == 'A')
        {
            PushHanoi(A, x);
            printf("Memindahkan piringan ke A...\n\n\n");
        }
        else if (*tujuan == 'B')
        {
            PushHanoi(B, x);
            printf("Memindahkan piringan ke B...\n\n\n");
        }
    }
    else
    {
        printf("Tidak bisa dipindahkan\n");
    }
    displayStackHanoi(*A, *B, *C, n);
}

boolean isvalid(char *asal, char *tujuan, StackHanoi *A, StackHanoi *B, StackHanoi *C)
{
    if (*asal != *tujuan)
    {
        if (*asal == 'A' && *tujuan == 'B')
        {
            if (IsEmptyHanoi(*A) || (!IsEmptyHanoi(*B) && InfoTopHanoi(*A) > InfoTopHanoi(*B)))
            {
                return false;
            }

            else
            {
                return true;
            }
        }
        else if (*asal == 'A' && *tujuan == 'C')
        {
            if (IsEmptyHanoi(*A) || (!IsEmptyHanoi(*C) && InfoTopHanoi(*A) > InfoTopHanoi(*C)))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (*asal == 'B' && *tujuan == 'C')
        {
            if (IsEmptyHanoi(*B) || (!IsEmptyHanoi(*C) && InfoTopHanoi(*B) > InfoTopHanoi(*C)))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (*asal == 'B' && *tujuan == 'A')
        {
            if (IsEmptyHanoi(*B) || (!IsEmptyHanoi(*A) && InfoTopHanoi(*B) > InfoTopHanoi(*A)))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (*asal == 'C' && *tujuan == 'A')
        {
            if (IsEmptyHanoi(*C) || (!IsEmptyHanoi(*A) && InfoTopHanoi(*C) > InfoTopHanoi(*A)))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (*asal == 'C' && *tujuan == 'B')
        {
            if (IsEmptyHanoi(*C) || (!IsEmptyHanoi(*B) && InfoTopHanoi(*C) > InfoTopHanoi(*B)))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int lengthStackHanoi(StackHanoi S)
{
    return TopHanoi(S) + 1;
}

boolean isnumber(char *x)
{
    int i;
    for (i = 0; i < len(x); i++)
    {
        if (x[i] < '0' || x[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int len(char *x)
{
    int i = 0;
    while (x[i] != '\0')
    {
        i++;
    }
    return i;
}

int strtoint(char *x)
{
    int i;
    int hasil = 0;
    for (i = 0; i < len(x); i++)
    {
        hasil = hasil * 10 + (x[i] - '0');
    }
    return hasil;
}