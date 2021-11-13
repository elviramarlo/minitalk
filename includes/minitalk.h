/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:02:56 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/13 18:32:26 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
int		ft_isdigit(int a);

#endif