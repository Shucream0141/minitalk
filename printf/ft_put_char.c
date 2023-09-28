#include "ft_printf.h"

int ft_put_char(char c)
{
    return write(1,&c,1);
}