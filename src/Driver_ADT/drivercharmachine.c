#include "../ADT/Mesin/charmachine.h"

int main()
{
    START();

    while (!EOT)
    {
        printf("%c", cc);
        ADV();
    }
    printf("\n");
    return 0;
}