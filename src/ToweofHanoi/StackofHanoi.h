
/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackofHanoi_H
#define stackofHanoi_H

#include "../ADT/Mesin/wordmachine.h"
#include "../ADT/Boolean/boolean.h"

#define Nil -1
#define MaxEl 1000
/* Nil adalah stack dengan elemen kosong . */

typedef int infotype;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    infotype T[MaxEl]; /* tabel penyimpan elemen */
    address TOP;       /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void displaystack(Stack A, Stack B, Stack C,int n);
/*Menampilkan Piringan yang ada dalam stack*/

void displaygaris(Stack s, int n);
/*Menampilkan garis pada display tower sebagai alas tower*/

void inttodisk (int x,int n);
/*merubah bentuk integer menjadi display disk pada tower*/

void move(char *asal, char *tujuan, Stack *A, Stack *B, Stack *C, int n);
/*menggerakan piringan dari tower asal ke tower tujuan*/
/* I.S. Stack asal tidak boleh kosong */
/* F.S. Stack tujuan bertambah 1 dan stack asal berkurang 1*/

boolean isvalid(char *asal, char *tujuan, Stack *A, Stack *B, Stack *C);
/*mengembalikan nilai true jika syarat terpenuhi seperti */

int lengthStackHanoi(Stack S);
/*mengembalikan panjang stack*/

boolean isnumber(char *x);
/*mengirim nilai true jika current character pada mesin kata bernilai angka*/

int len(char *x);
/*mengembalikan panjang string*/

int strtoint(char *x);
/*mengembalikan nilai integer dari string*/

int currenkatalength(char *x);
/*Mengembalikan nilai panjang currentkata*/
#endif