#include "../ADT/Mesin/wordmachine.h"

int main()
{
    STARTWORD();
    while (cc != MARK)
    {
        printf("%s\n", currentKata.TabWord);
        ADVWORDSTD();
    }
    printf("%s", currentKata.TabWord); // Last Word
    return 0;
}