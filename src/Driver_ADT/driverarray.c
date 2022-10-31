#include "../ADT/Array/array.h"

int main()
{
    ArrayDin Arr = MakeArrayDin();
    printf("Length: %d\n", Length(Arr));
    printf("Capacity: %d\n", GetCapacity(Arr));
    printf("IsEmpty: %d\n", IsEmpty(Arr));

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            InsertLast(&Arr, "Tubes");
        }
        else
        {
            InsertLast(&Arr, "Hello");
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("char%d: %s\n", i, Get(Arr, i));
    }
    DeallocateArrayDin(&Arr);
    return 0;
}