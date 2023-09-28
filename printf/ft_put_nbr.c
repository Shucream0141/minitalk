#include "ft_printf.h"

size_t ft_put_nbr(int n)
{
    size_t count;

    count = 1;
	if(n < 0)
		count++;
    ft_putnbr_fd(n,1);
    while(n/10)
    {
        n = n/10;
        count++;
    }
    return count;
}


void	ft_putnbr_fd(int n, int fd)
{
	int	x;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n <= 9)
	{
		x = n % 10 + '0';
		write(fd, &x, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
