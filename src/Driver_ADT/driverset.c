#include "../ADT/Set/set.h"

int main()
{
    Set S1, S2, S3;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    Insert(&S1, "A");
    Insert(&S1, "B");
    Insert(&S1, "C");
    Insert(&S1, "D");
    Insert(&S1, "E");
    Insert(&S2, "A");
    Insert(&S2, "B");
    Insert(&S2, "C");
    Insert(&S2, "D");
    Insert(&S2, "E");
    Insert(&S2, "F");
    Insert(&S2, "G");
    Insert(&S2, "H");
    Insert(&S2, "I");
    Insert(&S2, "J");
    Insert(&S2, "K");
    Insert(&S2, "L");
    Insert(&S2, "M");
    Insert(&S2, "N");
    Insert(&S2, "O");
    Insert(&S2, "P");
    Insert(&S2, "Q");
    Insert(&S2, "R");
    Insert(&S2, "S");
    Insert(&S2, "T");
    Insert(&S2, "U");
    Insert(&S2, "V");
    Insert(&S2, "W");
    Insert(&S2, "X");
    Insert(&S2, "Y");
    Insert(&S2, "Z");
    PrintSet(S1);
    PrintSet(S2);
    Union(&S1, &S2, &S3);
    PrintSet(S3);
    Delete(&S3, "A");
    Delete(&S3, "B");
    Delete(&S3, "C");
    PrintSet(S3);
    return 0;
}