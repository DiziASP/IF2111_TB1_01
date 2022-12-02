#ifndef _USER_CREATED_H
#define _USER_CREATED_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/Tree/tree.h"

extern BinTree tree;
extern int question_node;

int generate_num();

BinTree CreateTree(int n);

int generate_question();

int check_answer(BinTree P, int x);

int treeoflife();

#endif
