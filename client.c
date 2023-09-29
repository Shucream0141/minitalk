/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:38:34 by sendo             #+#    #+#             */
/*   Updated: 2023/09/29 16:27:49 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char *str)
{
	int	digit;
	int	err;

	while (*str != '\0')
	{
		digit = 7;
		while (digit >= 0)
		{
			if (*str & (1 << digit))
				err = kill(pid, SIGUSR1);
			else
				err = kill(pid, SIGUSR2);
			if (err == -1)
				exit(1);
			digit--;
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (1);
	if (pid <= 1000 || pid >= 99999)
	{
		ft_printf("argment pid is error. pid = %d", pid);
		return (1);
	}
	send_char(pid, argv[2]);
	return (0);
}
