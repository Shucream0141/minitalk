#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
    va_start(ap,str);
    size_t i;
    size_t count;

    count = 0;
    i = 0;
    while(str[i]!='\0')
    {
        if(str[i]=='%')
        {
            i++;
            count += ft_flag(&str[i],&ap);
            i++;
        }
        else
        {
            count += ft_put_str(&str[i]);
            while(str[i]!='\0' && str[i]!='%')
                i++;
        }
    }
    va_end(ap);
    return count;
}

// #include <stdio.h>

// int main()
// {
//     char a;
//     a = 'a';
//     unsigned int num = 12345;
//     int integer = -6789;
//     const char* str = "Hello, World!";

//     int i = ft_printf("%d %% %i %u %x %X %p %s %c\n",integer,integer,num,num,num,&num,str,a);
//     ft_printf("%d\n",i);
//     i = printf("%d %% %i %u %x %X %p %s %c\n",integer,integer,num,num,num,&num,str,a);
//     printf("%d\n",i);
//     return 0;
// }