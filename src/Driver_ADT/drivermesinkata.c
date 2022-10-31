#include "../ADT/Mesin/mesinkata.h"

int main()
{
    /* Kata dibaca per line dengan newline sebagai MARK */
    char *filename = "src/Driver_ADT/mesintext/coba.txt";
    STARTWORDFILE(filename);
    int i = 1;
    while (!EOP)
    {
        printf("Word %d : %s\n", i, WordToString(currentWord));
        ADVWORD();
        i++;
    }
    printf("Word %d : %s\n", i, WordToString(currentWord));
    return 0;
}