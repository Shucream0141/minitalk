/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:33:18 by sendo             #+#    #+#             */
/*   Updated: 2023/09/29 12:33:19 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
int		ft_printf(const char *str, ...);
//校舎に行ったら最新のprintfに取り替えること
#endif