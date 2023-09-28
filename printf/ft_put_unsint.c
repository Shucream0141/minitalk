#include "ft_printf.h"

void ft_print_unsint(unsigned int n);

int ft_put_unsint(unsigned int n)
{
    int i;

    i = 1;
    ft_print_unsint(n);
    while(n/10)
    {
        n = n/10;
        i++;
    }
    return i;
}

void ft_print_unsint(unsigned int n)
{
    int x;

    if(n <= 9)
    {
        x = n % 10 + '0';
        write(1,&x,1);
    }
    else
    {
        ft_print_unsint(n/10);
        ft_print_unsint(n%10);
    }
}

// #include <stdio.h>
// int main()
// {
//     int          y = ft_put_unsint(4294967295);
//     unsigned int x = 4294967295;

//     ft_print_unsint(4294967295);
//     printf("\n%u\n%d",x,y);

//     return 0;
// }