#include "../ADT/Mesin2/mesinkata.h"

int main()
{
    /* Kata dibaca per line dengan newline sebagai MARK */
    char *filename = "data/config.txt";
    STARTCONFIG(filename);
    int i = 1;
    while (!IsEOP())
    {
        printf("Word %d : %s\n", i, KataToString(currentKata));
        ADVCONFIG();
        i++;
    }
    printf("Kata %d : %s\n", i, KataToString(currentKata));
    return 0;
}