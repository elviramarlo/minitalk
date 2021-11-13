/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:19:03 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/13 18:31:50 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	int		i;
	char	c[10];

	if (n == 0)
		(ft_putchar('0'));
	else if (n == -2147483648)
		(ft_putstr("-2147483648"));
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	while (n > 0)
	{
		c[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(c[i--]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long long int	signo;
	long long int	sol;

	signo = 1;
	sol = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signo = -signo;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sol * signo > 2147483648)
			return (-1);
		else if (sol * signo < -2147483648)
			return (0);
		sol = sol * 10 + (*str - 48);
		str++;
	}
	return (signo * sol);
}
