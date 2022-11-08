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

void readQuery(char **arg1, char **arg2);

char *concatStr(char *str1, char *str2);

int charLength(char *str);

boolean compQuery(char *query, char *command);

char *IntToString(int x);

/* End of fungsi bantuan */
void PrintInitialState(int saldo, int ctr_layani, Queue Order, Queue Cook, Queue RServe);

void QueueOrder(Queue *Order);

void CookCycle(Queue *Cook, Queue *RServe, Queue *Order);

void RServeCycle(Queue *RServe, Queue *Cook, Queue *Order);

boolean ValidInput(char *query1, char *query2);

void dinnerdash();
#endif