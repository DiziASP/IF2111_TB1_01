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

void displaystack(Stack A, Stack B, Stack C,int n)
{
    int i;
    for (int i = n-1; i >= 0; i--)
    {
        inttodisk(A.T[i],n);
        inttodisk(B.T[i],n);
        inttodisk(C.T[i],n);
        printf("\n");
    }
    displaygaris(A,n);
    displaygaris(B,n);
    displaygaris(C,n);
    printf("\n");
    if(n>2){
        for(i=0;i<n;i++)
        {
            printf(" ");
        }
        printf("A");
        for(i=0;i<n;i++)
        {
            printf(" ");
        }
        for(i=0;i<n;i++)
        {
            printf(" ");
        }
        printf("B");
        for(i=0;i<n;i++)
        {
            printf(" ");
        }
        for(i=0;i<n;i++)
        {
            printf(" ");
        }
        printf("C");
        for(i=0;i<n;i++)
        {
            printf(" ");
        }
    }else{
        for(i=0;i<3;i++)
        {
            printf(" ");
        }
        printf("A");
        for(i=0;i<3;i++)
        {
            printf(" ");
        }
        for(i=0;i<3;i++)
        {
            printf(" ");
        }
        printf("B");
        for(i=0;i<3;i++)
        {
            printf(" ");
        }
        for(i=0;i<3;i++)
        {
            printf(" ");
        }
        printf("C");
        for(i=0;i<3;i++)
        {
            printf(" ");
        }
    }
    printf("\n\n");
}

void displaygaris(Stack s, int n)
{
    int i;
    int lenspace = 2*n+1;
    if(n>2){
        if (IsEmpty(s))
        {
            for(i=0;i<(lenspace-3)/2;i++)
            {
                printf(" ");
            }
            printf("---");
            for(i=0;i<(lenspace-3)/2;i++)
            {
                printf(" ");
            }
        }else{
            for(i=0;i<(lenspace-7)/2;i++)
            {
                printf(" ");
            }
            printf("-------");
            for(i=0;i<(lenspace-7)/2;i++)
            {
                printf(" ");
            }
        }
    }else{
        if (IsEmpty(s))
        {
            for(i=0;i<2;i++)
            {
                printf(" ");
            }
            printf("---");
            for(i=0;i<2;i++)
            {
                printf(" ");
            }
        }else{
            for(i=0;i<0;i++)
            {
                printf(" ");
            }
            printf("-------");
            for(i=0;i<0;i++)
            {
                printf(" ");
            }
        }
    }
}



void inttodisk(int x,int n)
{
    int i,j;
    int lendisk = 2 * x - 1;
    int lenspace = ((2*n +1) - lendisk)/2;
    
    if(n>2){
        if(x != Nil){
            for(i=0;i<lenspace;i++)
            {
                printf(" ");
            }
            for(i = 0; i<lendisk; i++){
                printf("*");
            }
            for(i=0;i<lenspace;i++)
            {
                printf(" ");
            }
        }else{
            for(i=0;i<n;i++)
            {
                printf(" ");
            }
            printf("|");
            for(i=0;i<n;i++)
            {
                printf(" ");
            }
        }
    }else if (n==2){
        if(x != Nil){
            for(i=0;i<(7 - lendisk)/2;i++)
            {
                printf(" ");
            }
            for(i = 0; i<lendisk; i++){
                printf("*");
            }
            for(i=0;i<(7 - lendisk)/2;i++)
            {
                printf(" ");
            }
        }else{
            for(i=0;i<3;i++)
            {
                printf(" ");
            }
            printf("|");
            for(i=0;i<3;i++)
            {
                printf(" ");
            }
        }    
    }else{
        if(x != Nil){
            for(i=0;i<(7 - lendisk)/2;i++)
            {
                printf(" ");
            }
            for(i = 0; i<lendisk; i++){
                printf("*");
            }
            for(i=0;i<(7 - lendisk)/2;i++)
            {
                printf(" ");
            }
        }else{
            for(i=0;i<3;i++)
            {
                printf(" ");
            }
            printf("|");
            for(i=0;i<3;i++)
            {
                printf(" ");
            }
        }
    }
}

void move(char *asal, char *tujuan, Stack *A, Stack *B, Stack *C,int n)
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
    displaystack(*A, *B, *C,n);
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

int lengthStack(Stack S)
{
    return Top(S) + 1;
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

int len(char *x){
    int i = 0;
    while(x[i] != '\0'){
        i++;
    }
    return i;
}

int strtoint(char *x){
    int i;
    int hasil = 0;
    for(i=0;i<len(x);i++){
        hasil = hasil * 10 + (x[i] - '0');
    }
    return hasil;
}

int currenkatalength(char *x){
    int i = 0;
    while(x[i] != ' ' && x[i] != '\0'){
        i++;
    }
    return i;
}