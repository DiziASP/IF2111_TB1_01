/* File: snakeonmeteor.h */

#ifndef SNAKEONMETEOR_H
#define SNAKEONMETEOR_H

#include "../ADT/Array/array.h"
#include "../ADT/Mesin/mesinkata.h"
#include "../ADT/LinkedList/linkedlist.h"
#include <time.h>

extern List ular;
extern int turn;
extern boolean can;
extern boolean gothitbymeteor;
extern char * command;
extern infotypeLL meteor;


void move();

void initialize();

void makemeteor();

void makefood();

boolean iscommandvalid(char * cmd);

void printsnake();

infotypeLL createrandominfotype();

int snakeonmeteor();

#endif