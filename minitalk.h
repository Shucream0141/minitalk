#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>


int	ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
int ft_printf(const char *str, ...);
//校舎に行ったら最新のprintfに取り替えること
#endif