#include "RandomIntegerGenerator.h"

long long int binary_exponent(int a,int b,int batas)
{
    long long int result = 1;
    int a_awal = a;
    a %= batas;
    while(b > 0)
    {
        if(b%2) result = ((result*a)%batas) + 1;
        a = (a*a)%batas;
        b >>=1;
    }

    if(result < 0)
    {
        result = (a_awal)%batas + 1;
    }


    return result;
}


long long int random_generate(int batas)
{
    batas+=1;
    srand(time(NULL));
    int a = ((rand())%batas)+1;
    int b= rand()%(1000000007);



    //printf("a b %d %d\n",a,b);
    return binary_exponent(a,b,batas-1);

}