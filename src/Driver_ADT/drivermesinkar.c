#include "../ADT/Mesin2/mesinkar.h"

int main()
{
    STARTFILE("src/Driver_ADT/mesintext/drivermesinkar.txt");
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADVFILE();
    }
    printf("\n");

    STARTFILE("src/Driver_ADT/mesintext/drivermesinkar2.txt");
    while (!IsEOP())
    {
        printf("%c", GetCC());
        ADVFILE();
    }
    printf("\n");

    STARTFILE("src/Driver_ADT/mesintext/drivermesinkarUndef.txt");
    return 0;
}