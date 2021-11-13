/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:08:59 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/13 18:56:02 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_string(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

static int	get_pid(char *str)
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
		pid = get_pid(argv[1]);
		while (argv[2][i])
		{
			send_string(pid, argv[2][i]);
			i++;
		}
		send_string(pid, '\n');
	}
	return (0);
}
