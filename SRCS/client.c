/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:58:49 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/30 22:11:23 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_end(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	to_bin(int pid, int c)
{
	int	cmp;

	cmp = 128;
	while (cmp > 0)
	{
		if (cmp <= c)
		{
			c = c - cmp;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		cmp = cmp / 2;
		usleep(100);
	}
}

void	client(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		to_bin(pid, (int)str[i]);
		i++;
	}
	send_end(pid);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (ft_isdigit(av[1][i]) == 1)
			i++;
		if (av[1][i] == '\0' && i > 0)
			client(ft_atoi(av[1]), av[2]);
		else
			write(1, "error : wrong pid\n", 18);
	}
	else
		write(1, "error : wrong number of arguments\n", 34);
	system("leaks client");
	return (0);
}
