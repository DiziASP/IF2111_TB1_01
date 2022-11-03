#ifndef DINNERDASH_H
#define DINNERDASH_H
#include <stdio.h>
#include "queueDinner.h"
#include <stdlib.h>
#include "../ADT/Boolean/boolean.h"
#include <time.h>

void faseAwal(int saldo, Queue Order, Queue Cook, Queue Rserve);
void queueOrder(Queue *qOrder);
void waktu(Queue *Order, Queue *Cook, Queue *RServe, char command[5]);
int dinnerDash();

#endif