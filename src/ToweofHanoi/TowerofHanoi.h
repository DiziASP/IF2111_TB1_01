#include "StackofHanoi.h"
#ifndef TowerofHanoi_H
#define TowerofHanoi_H

void pushdisk(int n, Stack *S);
/*Menambahkan disk ke stack*/
/* I.S. Stack kosong*/
/* F.S. Stack berisi n disk*/

void score(int n, int score, int langkah);
/*Menampilkan score dan langkah yang telah dilakukan*/

int TowerofHanoi();
/*Menampilkan permainan Tower of Hanoi*/

#endif