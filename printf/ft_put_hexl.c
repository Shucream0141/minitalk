#include "ft_printf.h"

void ft_print_hexl(unsigned int n);

int ft_put_hexl(unsigned int n)
{
    int count;

    count = 1;
    ft_print_hexl(n);
    while(n/16)
    {
        n = n/16;
        count++;
    }
    return count;
}

void ft_print_hexl(unsigned int n)
{
    int x;

    if(n < 16)
    {
        if(n >= 10)
        {
            x = n % 10 + 'A';
            write(1,&x,1);
        }    
        else
        {
            x = n % 16 + '0';
            write(1,&x,1);
        }
    }
    else
    {
        ft_print_hexl(n/16);
        ft_print_hexl(n%16);
    }
}

// #include <stdio.h>

// int main()
// {
//     unsigned int x =13;
//     int a = printf("%X",x);
//     printf("\n%d\n",a);

//     a = ft_put_hexl(x);
//     printf("\n%d\n",a);
//     return 0;
// }