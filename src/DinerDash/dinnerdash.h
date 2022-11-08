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

<<<<<<< HEAD
void rQuery(char **arg1, char **arg2);

char *conStr(char *str1, char *str2);

int charLength(char *str);

boolean cQuery(char *query, char *command);
=======
void readQuery(char **arg1, char **arg2);

char *concatStr(char *str1, char *str2);

int charLength(char *str);

boolean compQuery(char *query, char *command);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c

char *IntToString(int x);

/* End of fungsi bantuan */
<<<<<<< HEAD
void PrintInitialState(int saldo, int ctr_layani, QueueF Order, QueueF Cook, QueueF RServe);

void QueueOrder(QueueF *Order);

void CookCycle(QueueF *Cook, QueueF *RServe, QueueF *Order);

void RServeCycle(QueueF *RServe, QueueF *Cook, QueueF *Order);
=======
void PrintInitialState(int saldo, int ctr_layani, Queue Order, Queue Cook, Queue RServe);

void QueueOrder(Queue *Order);

void CookCycle(Queue *Cook, Queue *RServe, Queue *Order);

void RServeCycle(Queue *RServe, Queue *Cook, Queue *Order);
>>>>>>> b9e9aa7fbae1c523553cb01d061d02895df47d7c

boolean ValidInput(char *query1, char *query2);

void dinnerdash();
#endif