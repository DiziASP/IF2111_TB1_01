#ifndef DINNERDASH_H
#define DINNERDASH_H
#include <stdio.h>
#include "ADT/queueDinner.h"
#include <stdlib.h>
#include "../ADT/Boolean/boolean.h"
#include "../ADT/Mesin/wordmachine.h"
#include <time.h>

extern char *query;
extern char *arg;
void faseAwal(int saldo, Queue Order, Queue Cook, Queue Rserve);
void queueOrder(Queue *qOrder);
void waktu(Queue *Order, Queue *Cook, Queue *RServe, char command[5]);
int dinnerDash();

#endif