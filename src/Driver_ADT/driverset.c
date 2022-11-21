#include "../ADT/Set/set.h"

int main()
{
    Set S1, S2, S3;
    CreateSet(&S1);
    CreateSet(&S2);
    CreateSet(&S3);
    InsertSet(&S1, "A");
    InsertSet(&S1, "B");
    InsertSet(&S1, "C");
    InsertSet(&S1, "D");
    InsertSet(&S1, "E");
    InsertSet(&S2, "A");
    InsertSet(&S2, "B");
    InsertSet(&S2, "C");
    InsertSet(&S2, "D");
    InsertSet(&S2, "E");
    InsertSet(&S2, "F");
    InsertSet(&S2, "G");
    InsertSet(&S2, "H");
    InsertSet(&S2, "I");
    InsertSet(&S2, "J");
    InsertSet(&S2, "K");
    InsertSet(&S2, "L");
    InsertSet(&S2, "M");
    InsertSet(&S2, "N");
    InsertSet(&S2, "O");
    InsertSet(&S2, "P");
    InsertSet(&S2, "Q");
    InsertSet(&S2, "R");
    InsertSet(&S2, "S");
    InsertSet(&S2, "T");
    InsertSet(&S2, "U");
    InsertSet(&S2, "V");
    InsertSet(&S2, "W");
    InsertSet(&S2, "X");
    InsertSet(&S2, "Y");
    InsertSet(&S2, "Z");
    PrintSet(S1);
    PrintSet(S2);
    Union(&S1, &S2, &S3);
    PrintSet(S3);
    DeleteSet(&S3, "A");
    DeleteSet(&S3, "B");
    DeleteSet(&S3, "C");
    PrintSet(S3);
    return 0;
}