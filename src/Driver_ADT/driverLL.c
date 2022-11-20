#include "../ADT/LinkedList/linkedlist.h"

int main()
{
    List L;
    CreateEmptyLL(&L);
    infotype X;
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

    InversList(&L);
    PrintInfo(L);

    infotype Y = {3, 4};
    DelP(&L, Y);

    PrintInfo(L);
    return 0;
}