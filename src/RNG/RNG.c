#include "RNG.h"

int RNG()
{
    srand(time(NULL));
    int x = rand() % 100;
    int tebak;
    printf("Tebakan:");
    scanf("%d", &tebak);
    while (tebak != x)
    {
        if (tebak > x)
        {
            printf("Lebih kecil\n");
        }
        else
        {
            printf("Lebih besar\n");
        }
        printf("Tebakan: ");
        scanf("%d", &tebak);
    }
    printf("Ya, X adalah %d.\n", x);
    return 0;
}