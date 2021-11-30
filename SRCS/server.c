/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:58:57 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/30 22:14:00 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	put_in_buf(int c)
{
	static char	buffer[1024];
	static	int	i = 0;

	buffer[1023] = '\0';
	if (c == 0)
	{
		ft_putstr_fd(buffer, 1);
		i = 0;
		ft_memset(buffer, '\0', 1023);
		return ;
	}
	buffer[i] = (char)c;
	i++;
}

void	to_ascii(char *str)
{
	int	c;

	c = 0;
	if (str[0] == '1')
		c = c + 128;
	if (str[1] == '1')
		c = c + 64;
	if (str[2] == '1')
		c = c + 32;
	if (str[3] == '1')
		c = c + 16;
	if (str[4] == '1')
		c = c + 8;
	if (str[5] == '1')
		c = c + 4;
	if (str[6] == '1')
		c = c + 2;
	if (str[7] == '1')
		c = c + 1;
	put_in_buf(c);
}

void	recup_sig(int	s)
{
	static	char	str[8];
	static	int		i = 0;

	if (s == SIGUSR1)
		str[i] = '1';
	else
		str[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		to_ascii(str);
	}
}

void	server(int pid)
{
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, recup_sig);
	signal(SIGUSR2, recup_sig);
	while (1)
		pause();
}

int	main(void)
{
	int	pid;

	pid = getpid();
	server(pid);
	return (0);
}
