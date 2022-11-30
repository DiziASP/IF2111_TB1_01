
/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackofHanoi_H
#define stackofHanoi_H

#include "../ADT/Boolean/boolean.h"
#include "../ADT/Mesin/mesinkata.h"

#define NilHanoi -1
#define MaxHanoi 1000
/* Nil adalah stack dengan elemen kosong . */

typedef int infohanoi;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    infohanoi T[MaxHanoi]; /* tabel penyimpan elemen */
    address TOP;           /* alamat TOP: elemen puncak */
} StackHanoi;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxHanoi-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopHanoi(S) (S).TOP
#define InfoTopHanoi(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateHanoi(StackHanoi *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHanoi S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StackHanoi kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHanoi(StackHanoi S);
/* Mengirim true jika StackHanoi kosong: lihat definisi di atas */
boolean IsFullHanoi(StackHanoi S);
/* Mengirim true jika tabel penampung nilai elemen StackHanoi penuh */

/* ************ Menambahkan sebuah elemen ke StackHanoi ************ */
void PushHanoi(StackHanoi *S, infohanoi X);
/* Menambahkan X sebagai elemen StackHanoi S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHanoi TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackHanoi ************ */
void PopHanoi(StackHanoi *S, infohanoi *X);
/* Menghapus X dari StackHanoi S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void displayStackHanoi(StackHanoi A, StackHanoi B, StackHanoi C, int n);
/* Menampilkan Piringan yang ada dalam stack */

void displaygaris(StackHanoi s, int n);
/* Menampilkan Piringan yang ada dalam stack */

void inttodisk(int x, int n);
/* merubah bentuk integer menjadi display disk pada tower */

void move(char *asal, char *tujuan, StackHanoi *A, StackHanoi *B, StackHanoi *C, int n);
/* Menggerakan piringan dari tower asal ke tower tujuan */
/* I.S. Stack asal tidak boleh kosong */
/* F.S. Stack tujuan bertambah 1 dan stack asal berkurang 1*/

boolean isvalid(char *asal, char *tujuan, StackHanoi *A, StackHanoi *B, StackHanoi *C);
/*mengembalikan nilai true jika syarat terpenuhi seperti */

int lengthStackHanoi(StackHanoi S);
/* Mengembalikan panjang stack */

boolean isnumber(char *x);
/* Mengirim nilai true jika current character pada mesin kata bernilai angka */

int len(char *x);
/* mengembalikan panjang string */

int strtoint(char *x);
/* mengembalikan nilai integer dari string */

int currenkatalength(char *x);
/*Mengembalikan nilai panjang currentkata*/

#endif