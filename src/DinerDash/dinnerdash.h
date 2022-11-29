#ifndef _DINNERDASH_H
#define _DINNERDASH_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ADT_Local/queueDinner.h"
#include "../ADT/Boolean/boolean.h"

extern char *query1;
extern char *query2;
extern int ordNum;

void rQuery(char **arg1, char **arg2);
/*Membaca query dari mesin kata dengan cara menerjemahkan kata ke string*/
/*I.S. 2 buah kata */
/*F.S. 2 buah string*/

char *conStr(char *str1, char *str2);
/*Menggabungkan 2 string menjadi 1 string*/
/*I.S. 2 buah string*/
/*F.S. 1 buah string*/

int charLength(char *str);
/*Menghitung panjang string*/

boolean cQuery(char *query, char *command);
/*membandingkan query dengan command yang ada*/

char *IntToString(int x);
/*Mengubah integer menjadi string*/

/* End of fungsi bantuan */
void PrintInitialState(int saldo, int ctr_layani, QueueF Order, QueueF Cook, QueueF RServe);
/*menampilkan isi queue sesuai spesifikasi*/
void QueueOrder(QueueF *Order);
/*menambahkan order ke queue dengan random generate number*/
/* I.S. queue order sembarang */
/* F.S. queue order bertambah satu */

void CookCycle(QueueF *Cook, QueueF *RServe, QueueF *Order);
/*mengurangi waktu cook dan menambahkan ke queue yang sudah siap di serve*/
/* I.S. queue cook, queue ready to serve, queue order sembarang */
/* F.S. queue cook berkurang waktunya, queue ready to serve bertambah jika waktu queue cook bernilai 0*/

void RServeCycle(QueueF *RServe, QueueF *Cook, QueueF *Order);
/*mengurangi waktu ketahanan dan menambahkan ke queue cook jika waktu ketahanan bernilai 0*/
/* I.S. queue ready to serve, queue cook, queue order sembarang */
/* F.S. queue ready to serve berkurang waktu ketahanannya, queue cook bertambah jika waktu queue ready to serve bernilai 0*/

boolean ValidInput(char *query1, char *query2);
/*mengembalikan true jika input valid*/

int dinnerdash();

/*memainkan game dinnerdash*/
#endif