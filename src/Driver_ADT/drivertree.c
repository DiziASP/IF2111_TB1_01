#include "../ADT/Tree/tree.h"

int main()
{
    /* Create Tree */
    BinTree P = Tree(1, Tree(2, Tree(4, NilRec, NilRec), Tree(5, NilRec, NilRec)), Tree(3, Tree(6, NilRec, NilRec), Tree(7, NilRec, NilRec)));

    PrintTree(P, 5);
    return 0;
}