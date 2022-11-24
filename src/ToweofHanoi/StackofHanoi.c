/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "StackofHanoi.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
{
    int i;
    for (i = 0; i < MaxEl; i++)
    {
        (*S).T[i] = Nil;
    }
    (*S).TOP = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
{
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S)
{
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X)
{
    if (IsFull(*S))
    {
        printf("Stack penuh\n");
    }
    else
    {
        Top(*S)++;
        InfoTop(*S) = X;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X)
{
    if (IsEmpty(*S))
    {
        printf("Stack kosong\n");
    }
    else
    {
        *X = InfoTop(*S);
        InfoTop(*S) = Nil;
        Top(*S)--;
    }
}

void displaystack(Stack A, Stack B, Stack C)
{
    for (int i = MaxEl-1; i >= 0; i--)
    {
        inttodisk(i,&A);
        inttodisk(i,&B);
        inttodisk(i,&C);
        printf("\n");
    }
    displaygaris(A);
    displaygaris(B);
    displaygaris(C);
    printf("\n");
    printf("     A     ");
    printf("     B     ");
    printf("     C     ");
    printf("\n\n");
}

void displaygaris(Stack s)
{
    if (IsEmpty(s))
    {
        printf("    ---    ");
    }
    else
    {
        printf("  -------  ");
    }
}

void inttodisk(int i, Stack *s)
{
    if((*s).T[i] == 1){
        printf("     *     ");
    }
    else if((*s).T[i] == 3){
        printf("    ***    ");
    }
    else if((*s).T[i] == 5){
        printf("   *****   ");
    }
    else if((*s).T[i] == 7){
        printf("  *******  ");
    }
    else if((*s).T[i] == 9){
        printf(" ********* ");
    }
    else{
        printf("     |     ");
    }
}

void move(char *asal, char *tujuan, Stack *A, Stack *B, Stack *C)
{
    infotype x;
    if (*asal == 'A' && !IsEmpty(*A))
    {
        Pop(A, &x);
        if (*tujuan == 'B')
        {
            Push(B, x);
            printf("Memindahkan piringan ke B...\n\n\n");
        }
        else if (*tujuan == 'C')
        {
            Push(C, x);
            printf("Memindahkan piringan ke C...\n\n\n");
        }
    }
    else if (*asal == 'B' && !IsEmpty(*B))
    {
        Pop(B, &x);
        if (*tujuan == 'A')
        {
            Push(A, x);
            printf("Memindahkan piringan ke A...\n\n\n");
        }
        else if (*tujuan == 'C')
        {
            Push(C, x);
            printf("Memindahkan piringan ke C...\n\n\n");
        }
    }
    else if (*asal == 'C' && !IsEmpty(*C))
    {
        Pop(C, &x);
        if (*tujuan == 'A')
        {
            Push(A, x);
            printf("Memindahkan piringan ke A...\n\n\n");
        }
        else if(*tujuan == 'B')
        {
            Push(B, x);
            printf("Memindahkan piringan ke B...\n\n\n");
        }
    }
    else
    {
        printf("Tidak bisa dipindahkan\n");
    }
    displaystack(*A, *B, *C);
}

boolean isvalid(char *asal, char *tujuan, Stack *A, Stack *B, Stack *C)
{
    if(*asal != *tujuan){
        if (*asal == 'A' && *tujuan == 'B')
        {
            if(IsEmpty(*A) || (!IsEmpty(*B) && InfoTop(*A) > InfoTop(*B))){
                return false;
            }
            
            else
            {
                return true;
            }
        }
        else if (*asal == 'A' && *tujuan == 'C')
        {
            if (IsEmpty(*A) || (!IsEmpty(*C) && InfoTop(*A) > InfoTop(*C)))
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
            if (IsEmpty(*B) || (!IsEmpty(*C) && InfoTop(*B) > InfoTop(*C)))
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
            if (IsEmpty(*B) || (!IsEmpty(*A) && InfoTop(*B) > InfoTop(*A)))
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
            if (IsEmpty(*C) || (!IsEmpty(*A) && InfoTop(*C) > InfoTop(*A)))
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
            if (IsEmpty(*C) || (!IsEmpty(*B) && InfoTop(*C) > InfoTop(*B)))
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
    }else{
        return false;
    }
}