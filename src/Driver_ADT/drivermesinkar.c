#include "../ADT/Mesin/mesinkar.h"

int main()
{
    STARTFILE("src/Driver_ADT/mesintext/drivermesinkar.txt");
    while (!EOP)
    {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");

    STARTFILE("src/Driver_ADT/mesintext/drivermesinkar2.txt");
    while (!EOP)
    {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");

    STARTFILE("src/Driver_ADT/mesintext/drivermesinkarUndef.txt");
    return 0;
}