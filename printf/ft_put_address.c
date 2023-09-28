#include "ft_printf.h"

void ft_print_hexlong(unsigned long long n);

int ft_put_hexlong(unsigned long long n)
{
    int count;

    count = 3;
    write(1,"0x",2);
    ft_print_hexlong(n);
    while(n/16)
    {
        n = n/16;
        count++;
    }
    return count;
}

void ft_print_hexlong(unsigned long long n)
{
    int x;

    if(n < 16)
    {
        if(n >= 10)
        {
            x = n % 10 + 'a';
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
        ft_print_hexlong(n/16);
        ft_print_hexlong(n%16);
    }
}

int ft_put_address(void* add)
{
    int i;
    
    i = ft_put_hexlong((unsigned long long)add);
    return i;
}

// int main()
// {
//     int add = 2;

//     ft_put_address((void*)add);
//     return 0;

// }