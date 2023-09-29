/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:38:29 by sendo             #+#    #+#             */
/*   Updated: 2023/09/29 16:38:35 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_bits = 0;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	char		c;

	(void)info;
	(void)context;
	g_bits = g_bits << 1;
	if (signal == SIGUSR1)
		g_bits |= 1;
	i++;
	if (i == 8)
	{
		c = g_bits;
		write(1, &c, 1);
		i = 0;
	}
}

void	receiver(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	ft_memset(&act1, 0, sizeof(act1));
	ft_memset(&act2, 0, sizeof(act2));
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	sigemptyset(&act1.sa_mask);
	sigemptyset(&act2.sa_mask);
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act2.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
}

int	main(void)
{
	ft_printf("pid = %d\nsend pid num from client\n", getpid());
	receiver();
	while (1)
		pause();
}
