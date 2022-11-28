#include "../ADT/Map/map.h"
#include <stdio.h>

int main()
{
    Map M;
    CreateMap(&M);
    printf("Empty? %d\n", IsEmptyMap(M));
    printf("Full? %d\n", IsFullMap(M));
    InsertMap(&M, "MarioBrodi", 1);
    InsertMap(&M, "Riandra4trend", 2);
    InsertMap(&M, "Jonjonjon", 3);
    InsertMap(&M, "Danangz", 4);
    InsertMap(&M, "DiziCapekbgt", 5);
    printf("Empty? %d\n", IsEmptyMap(M));
    printf("Full? %d\n", IsFullMap(M));

    printf("Cari Skor dari Nama\n");
    printf("Value MarioBrodi: %d\n", ValueMap(M, "MarioBrodi") != UndefMap ? ValueMap(M, "MarioBrodi") : 0);
    printf("Value Riandra4trend: %d\n", ValueMap(M, "Riandra4trend") != UndefMap ? ValueMap(M, "Riandra4trend") : 0);
    printf("Value Jonjonjon: %d\n", ValueMap(M, "Jonjonjon") != UndefMap ? ValueMap(M, "Jonjonjon") : 0);
    printf("Value Danangz: %d\n", ValueMap(M, "Danangz") != UndefMap ? ValueMap(M, "Danangz") : 0);
    printf("Value DiziCapekbgt: %d\n", ValueMap(M, "DiziCapekbgt") != UndefMap ? ValueMap(M, "DiziCapekbgt") : 0);

    DeleteMap(&M, "MarioBrodi");
    DeleteMap(&M, "Riandra4trend");

    printf("Cari Nama dari Skor\n");
    printf("Value MarioBrodi: %d\n", ValueMap(M, "MarioBrodi") != UndefMap ? ValueMap(M, "MarioBrodi") : 0);
    printf("Value Riandra4trend: %d\n", ValueMap(M, "Riandra4trend") != UndefMap ? ValueMap(M, "Riandra4trend") : 0);
    printf("Value Jonjonjon: %d\n", ValueMap(M, "Jonjonjon") != UndefMap ? ValueMap(M, "Jonjonjon") : 0);
    printf("Value Danangz: %d\n", ValueMap(M, "Danangz") != UndefMap ? ValueMap(M, "Danangz") : 0);
    printf("Value DiziCapekbgt: %d\n", ValueMap(M, "DiziCapekbgt") != UndefMap ? ValueMap(M, "DiziCapekbgt") : 0);

    return 0;
}