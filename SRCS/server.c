/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:58:57 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/26 10:36:49 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	bin_to_char(int	i)
{
	char	c;

	return (c);
}

void	server()
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, recup_sig);
	// signal(SIGUSR2, recup_sig);
	while (1)
		pause();
}

int	main(int ac)
{
	if (ac == 1)
		server();
	return (0);
}
