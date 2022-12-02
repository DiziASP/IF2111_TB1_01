#include "../ADT/LinkedList/linkedlist.h"
#include <stdio.h>

int main()
{
    List L;
    CreateEmptyLL(&L);
    infotypeLL X;
    X.x = 1;
    X.y = 2;
    InsVLast(&L, X);
    X.x = 3;
    X.y = 4;
    InsVLast(&L, X);
    X.x = 5;
    X.y = 6;
    InsVLast(&L, X);
    PrintInfo(L);
    printf("\n");
    DelVLast(&L, &X);
    PrintInfo(L);

    return 0;
}