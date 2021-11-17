/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:08:59 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/17 18:31:29 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	mens(int signum)
{
	if (signum == SIGUSR1)
		write(1, "-", 1);
}

static void	send_string(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(200);
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		signal(SIGUSR1, mens);
		usleep(200);
	}
}

static int	get_pid_server(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr("Error");
			return (1);
		}
		i++;
	}
	return (ft_atoi(str));
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Error");
		return (1);
	}
	else
	{
		pid = get_pid_server(argv[1]);
		while (argv[2][i])
		{
			send_string(pid, argv[2][i]);
			i++;
		}
	}
	send_string(pid, '\n');
	return (0);
}
