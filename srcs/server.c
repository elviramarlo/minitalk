/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:09:07 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/13 19:01:21 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	msg(int signum)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, msg);
	signal(SIGUSR2, msg);
	while (1)
		pause();
	return (0);
}
