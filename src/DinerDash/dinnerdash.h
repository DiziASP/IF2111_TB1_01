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

char *conStr(char *str1, char *str2);

int charLength(char *str);

boolean cQuery(char *query, char *command);

char *IntToString(int x);

/* End of fungsi bantuan */
void PrintInitialState(int saldo, int ctr_layani, QueueF Order, QueueF Cook, QueueF RServe);

void QueueOrder(QueueF *Order);

void CookCycle(QueueF *Cook, QueueF *RServe, QueueF *Order);

void RServeCycle(QueueF *RServe, QueueF *Cook, QueueF *Order);

boolean ValidInput(char *query1, char *query2);

void dinnerdash();
#endif