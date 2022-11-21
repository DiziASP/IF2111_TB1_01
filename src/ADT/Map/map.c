#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateMap(Map *M)
{
    M->Count = NilMap;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
{
    return M.Count == NilMap;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M)
{
    return M.Count == MaxMap;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count && !compMapKey(M.Elements[i].Key, k))
    {
        i++;
    }
    if (i == M.Count)
    {
        return UndefMap;
    }
    else
    {
        return M.Elements[i].Value;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v)
{
    int i = 0;
    while (i < M->Count && !compMapKey(M->Elements[i].Key, k))
    {
        i++;
    }
    if (i == M->Count)
    {
        M->Elements[i].Key = k;
        M->Elements[i].Value = v;
        M->Count++;
    }
    else
    {
        M->Elements[i].Value = v;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k)
{
    int i = 0;
    while (i < M->Count && !compMapKey(M->Elements[i].Key, k))
    {
        i++;
    }
    if (i != M->Count)
    {
        M->Elements[i] = M->Elements[M->Count - 1];
        M->Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count && !compMapKey(M.Elements[i].Key, k))
    {
        i++;
    }
    return i != M.Count;
}
/* Mengembalikan true jika k adalah member dari M */

/* Fungsi Bantuan Map */

boolean compMapKey(keytype k1, keytype k2)
{
    int i = 0;
    while (k1[i] != '\0' && k2[i] != '\0')
    {
        if (k1[i] != k2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}