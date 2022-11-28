#include "RNG.h"
<<<<<<< HEAD
int mod = 107; // bilangan prima
<<<<<<< HEAD
int binary_exponent(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;

        /*
                if(result < 0)
                {
                    printf("TIDAK BERHASIL %d %d %d \n", result,a,b);
                    return 0;
                }

        */
    }

    return result;
}

int random_generate()
=======
<<<<<<< HEAD
int mod = 107; // bilangan prima
=======
>>>>>>> 254323316e2db3b5d9260e0fc77ff61fb90a2834
int binary_exponent(int a,int b)
{
    int result = 1;
    while(b > 0)
    {
        if(b%2) result = (result*a)%mod;
        a = (a*a)%mod;
        b >>=1;

/*
        if(result < 0)
        {
            printf("TIDAK BERHASIL %d %d %d \n", result,a,b);
            return 0;
        }

*/
    }

    
    return result;
}


int random_generate()
{
    srand(time(NULL));
    int a = rand()%mod;
    int b= rand()%(1000000007);

    //printf("a b %d %d\n",a,b);
    return binary_exponent(a,b);

}
=======

int RNG()
>>>>>>> 254323316e2db3b5d9260e0fc77ff61fb90a2834
{
    srand(time(NULL));
<<<<<<< HEAD
    int a = rand() % mod;
    int b = rand() % (1000000007);

    // printf("a b %d %d\n",a,b);
    return binary_exponent(a, b);
}
=======
    int x = rand() % 100;
    int tebak;
    printf("Tebakan:");
    STARTWORD();
    tebak = KataToInt(currentKata);
    while (tebak > 100 && tebak < 0)
    {
        printf("Tebakan:");
        STARTWORD();
        tebak = KataToInt(currentKata);
    }
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
        score -= 4;
        printf("Tebakan: ");
        scanf("%d", &tebak);
    }
    printf("Ya, X adalah %d.\n", x);
    return score;
}
>>>>>>> ff1f6b35bc970b2a0374610d52f5b32f5275f6d7
<<<<<<< HEAD
>>>>>>> 254323316e2db3b5d9260e0fc77ff61fb90a2834
=======
>>>>>>> 254323316e2db3b5d9260e0fc77ff61fb90a2834
