/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:58:49 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/26 10:36:35 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	to_bin(int c)
{
	int	i;

	return (jsp);
}

int	client(int pid, char *str)
{
	int	i;

	i = 0;
	// kill(pid, SIGUSR1);
	while (str[i])
	{
		to_bin(str[i]);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		while (ft_is_digit(av[1][i]) == 1)
			i++;
		if (av[1][i] == '\0')
			client(ft_atoi(av[1]), av[2]);
		else
			write(1, "error : wrong pid\n", 18);
	}
	else
		write(1, "error : wrong number of arguments\n", 34);
	return (0);
}
