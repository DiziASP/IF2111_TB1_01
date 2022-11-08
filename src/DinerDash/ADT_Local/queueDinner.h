/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEDINNER_H
#define QUEUEDINNER_H

#include "../../ADT/Boolean/boolean.h"
#include "../../ADT/Mesin/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IDX_UNDEF -1
<<<<<<< HEAD
#define CAPACITYF 7
=======
#define CAPACITY 7
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c

/* Definisi elemen dan address */
typedef struct
{
        char *OrderId;
        int durasi;
        int ketahanan;
        int harga;
} Food;

typedef struct
{
<<<<<<< HEAD
        Food buffer[CAPACITYF];
        int idxHead;
        int idxTail;
} QueueF;
=======
        Food buffer[CAPACITY];
        int idxHead;
        int idxTail;
} Queue;
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
<<<<<<< HEAD
void CreateQueueF(QueueF *q);
=======
void CreateQueueF(Queue *q);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
<<<<<<< HEAD
boolean isEmptyF(QueueF q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullF(QueueF q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthF(QueueF q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueF(QueueF *q, Food val);
=======
boolean isEmptyF(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullF(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthF(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueF(Queue *q, Food val);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

<<<<<<< HEAD
void dequeueF(QueueF *q, Food *val);
=======
void dequeueF(Queue *q, Food *val);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

<<<<<<< HEAD
int searchIdx(QueueF *q, char *id);

/* *** Display Queue *** */
void displayQueueOrder(QueueF q);
=======
int searchIdx(Queue *q, char *id);

/* *** Display Queue *** */
void displayQueueOrder(Queue q);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

<<<<<<< HEAD
void displayQueueCook(QueueF q);
=======
void displayQueueCook(Queue q);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

<<<<<<< HEAD
void displayQueueServe(QueueF q);
=======
void displayQueueServe(Queue q);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

#endif