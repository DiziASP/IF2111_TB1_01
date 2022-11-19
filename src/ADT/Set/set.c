#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
{
    S->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
{
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S)
{
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

int length(Set S)
{
    return S.Count;
}
/* Mengirimkan banyaknya elemen Set S, mungkin 0 */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
{
    if (!IsMember(*S, Elmt))
    {
        S->Elements[S->Count] = Elmt;
        S->Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt)
{
    int i = 0;
    while (i < S->Count && S->Elements[i] != Elmt)
    {
        i++;
    }
    if (i < S->Count)
    {
        while (i < S->Count - 1)
        {
            S->Elements[i] = S->Elements[i + 1];
            i++;
        }
        S->Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean compSet(char *c1, char *c2)
{
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0')
    {
        if (c1[i] != c2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
boolean IsMember(Set S, infotype Elmt)
{
    int i = 0;
    while (i < S.Count && !compSet(S.Elements[i], Elmt))
    {
        i++;
    }
    return i < S.Count;
}
/* Mengembalikan true jika Elmt adalah member dari S */

/* ********** Primitif Dasar Set ********* */
void Union(Set *S1, Set *S2, Set *S3)
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count)
    {
        Insert(S3, S1->Elements[i]);
        i++;
    }
    i = 0;
    while (i < S2->Count)
    {
        Insert(S3, S2->Elements[i]);
        i++;
    }
}
/* Menghasilkan S3 yang merupakan hasil gabungan S1 dan S2 */

void Intersection(Set *S1, Set *S2, Set *S3)
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count)
    {
        if (IsMember(*S2, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }
}
/* Menghasilkan S3 yang merupakan hasil irisan S1 dan S2 */

void Difference(Set *S1, Set *S2, Set *S3)
{
    CreateEmpty(S3);
    int i = 0;
    while (i < S1->Count)
    {
        if (!IsMember(*S2, S1->Elements[i]))
        {
            Insert(S3, S1->Elements[i]);
        }
        i++;
    }
}
/* Menghasilkan S3 yang merupakan hasil selisih S1 dan S2 */

void PrintSet(Set S)
{
    int i = 0;
    while (i < S.Count)
    {
        printf("%s ", S.Elements[i]);
        i++;
    }
    printf("\n");
}
/* Mencetak set S ke layar */

void CopySet(Set Sin, Set *Sout)
{
    CreateEmpty(Sout);
    int i = 0;
    while (i < Sin.Count)
    {
        Insert(Sout, Sin.Elements[i]);
        i++;
    }
}
/* Menyalin Sin ke Sout */

boolean IsSubset(Set S1, Set S2)
{
    int i = 0;
    while (i < S1.Count && IsMember(S2, S1.Elements[i]))
    {
        i++;
    }
    return i == S1.Count;
}
/* Menghasilkan true jika S1 merupakan subset dari S2 */

boolean IsEqual(Set S1, Set S2)
{
    return IsSubset(S1, S2) && IsSubset(S2, S1);
}
/* Menghasilkan true jika S1 sama dengan S2 */