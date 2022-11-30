#include "linkedlist.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL(List L)
{
    return (First(L) == NilLL && Last(L) == NilLL);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLL(List *L)
{
    First(*L) = NilLL;
    Last(*L) = NilLL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressLL AlokasiLL(infotypeLL X)
{
    addressLL P = (addressLL)malloc(sizeof(ElmtList));
    if (P != NilLL)
    {
        Info(P) = X;
        Next(P) = NilLL;
    }
    return P;
}
/* Mengirimkan addressLL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLL tidak NilLL, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=NilLL */
/* Jika alokasi gagal, mengirimkan NilLL */
void DealokasiLL(addressLL *P)
{
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLL P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLL SearchLL(List L, infotypeLL Point)
{
    addressLL p = First(L);
    boolean found = false;

    while (p != NilLL && !found)
    {
        if (InfoX(p) == Point.x && InfoY(p) == Point.y)
        {
            found = true;
        }
        else
        {
            p = Next(p);
        }
    }
    return found ? p : NilLL;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressLL elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLL */

int indexOfLL(List L, infotypeLL X)
{
    addressLL p = First(L);
    int i = 1;
    boolean found = false;

    while (p != NilLL && !found)
    {
        if (InfoX(p) == X.x && InfoY(p) == X.y)
        {
            found = true;
        }
        else
        {
            p = Next(p);
            i++;
        }
    }
    return found ? i : -1;
}
/****************** PRIMITIF BERDASARKAN NilLLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotypeLL X)
{
    addressLL P = AlokasiLL(X);
    if (P != NilLL)
    {
        InsertFirstLL(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilLLai X jika alokasi berhasil */
void InsVLast(List *L, infotypeLL X)
{
    addressLL P = AlokasiLL(X);
    if (P != NilLL)
    {
        InsertLastLL(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotypeLL *X)
{
    addressLL P;
    DelFirstLL(L, &P);
    *X = Info(P);
    DealokasiLL(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilLLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast(List *L, infotypeLL *X)
{
    addressLL P;
    DelLastLL(L, &P);
    *X = Info(P);
    DealokasiLL(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilLLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLL(List *L, addressLL P)
{
    if (IsEmptyLL(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLL P sebagai elemen pertama */
void InsertAfterLL(List *L, addressLL P, addressLL Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastLL(List *L, addressLL P)
{
    if (IsEmptyLL(*L))
    {
        InsertFirstLL(L, P);
    }
    else
    {
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLL(List *L, addressLL *P)
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = NilLL;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP(List *L, infotypeLL X)
{
    addressLL P = SearchLL(*L, X);
    if (P != NilLL)
    {
        if (P == First(*L))
        {
            DelFirstLL(L, &P);
        }
        else
        {
            addressLL Prec = First(*L);
            while (Next(Prec) != P)
            {
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
        }
        DealokasiLL(&P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLL P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastLL(List *L, addressLL *P)
{
    addressLL Last = Last(*L);
    if (Last == First(*L))
    {
        DelFirstLL(L, P);
    }
    else
    {
        addressLL Prec = First(*L);
        while (Next(Prec) != Last)
        {
            Prec = Next(Prec);
        }
        DelAfter(L, P, Prec);
        Last(*L) = Prec;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter(List *L, addressLL *Pdel, addressLL Prec)
{
    *Pdel = Next(Prec);
    if (Next(Prec) != NilLL)
    {
        Next(Prec) = Next(Next(Prec));
        Next(*Pdel) = NilLL;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
{
    addressLL p = First(L);
    printf("[");
    while (p != NilLL)
    {
        if (Next(p) != NilLL)
        {
            printf("<%d,%d>,", InfoX(p), InfoY(p));
        }
        else
        {
            printf("<%d,%d>", InfoX(p), InfoY(p));
        }
        p = Next(p);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilLLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt(List L)
{
    int count = 0;
    addressLL p = First(L);
    while (p != NilLL)
    {
        p = Next(p);
        count++;
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/

void InversList(List *L)
{
    addressLL P = First(*L);

    if (P != NilLL)
    {
        addressLL Q = Next(P);
        addressLL R = NilLL;
        while (Q != NilLL)
        {
            Next(P) = R;
            R = P;
            P = Q;
            Q = Next(Q);
        }
        Next(P) = R;
        First(*L) = P;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1(List *L1, List *L2, List *L3)
{
    CreateEmptyLL(L3);

    addressLL last = Last(*L1);
    if (IsEmptyLL(*L1))
    {
        First(*L3) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L1);
        Next(last) = First(*L2);
    }
    CreateEmptyLL(L1);
    CreateEmptyLL(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */