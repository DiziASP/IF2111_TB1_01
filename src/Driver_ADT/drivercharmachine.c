#include "../ADT/Mesin/charmachine.h"

int main()
{
    START();

    while (cc != MARK)
    {
        printf("%c", cc);
        ADV();
    }
    printf("\n");
    return 0;
}