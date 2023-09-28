#include "ft_printf.h"

int ft_put_str(const char* str)
{
    size_t i;

    i = 0;
    if(!str)
        return 0;
    while(str[i]!='\0' && str[i]!='%')
    {
        write(1,&str[i],1);
        i++;
    }
    return i;
}