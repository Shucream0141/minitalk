#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_flag(const char *str, va_list *ap);
int ft_printf(const char *str, ...);
int ft_put_char(char c);
size_t ft_put_nbr(int n);
int ft_put_str(const char *str);
void	ft_putnbr_fd(int n, int fd);
int ft_put_unsint(unsigned int n);
int ft_put_hexs(unsigned int n);
int ft_put_hexl(unsigned int n);
int ft_put_hexlong(unsigned long long n);
int ft_put_address(void* add);
void	*ft_memset(void *b, int c, size_t len);

#endif
