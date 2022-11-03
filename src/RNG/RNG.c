#include "RNG.h"
int mod = 107; // bilangan prima
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
    int a = rand()%mod;
    int b= rand()%(1000000007);

    //printf("a b %d %d\n",a,b);
    return binary_exponent(a,b);

}
