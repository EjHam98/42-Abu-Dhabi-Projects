/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:13:34 by ehammoud          #+#    #+#             */
/*   Updated: 2024/01/15 18:44:31 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static int	ft_atoi(const char *str)
{
	size_t	i;
	long	n;
	int		sign;
	int		lm;

	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1 - 2 * (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	lm = INT_MAX;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((str[i] - 48 > lm % 10 && n == lm / 10) || n > lm / 10)
			return (-1 * (sign == 1));
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

static int	signal01(int bit, int pid)
{
	if (!bit)
	{
		if (kill(pid, SIGUSR1))
			return (0);
		usleep(70);
	}
	else
	{
		if (kill(pid, SIGUSR2))
			return (0);
		usleep(70);
	}
	return (1);
}

static int	sendinfo(int pid, char *msg)
{
	int	i;

	while (*msg)
	{
		i = 8;
		while (--i >= 0)
			if (!signal01(((*msg) >> i) % 2, pid))
				return (0);
		msg++;
	}
	i = 0;
	while (++i <= 8)
		if (!signal01(0, pid))
			return (0);
	return (1);
}

void	msg_received(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Server received msg!\n", 21);
		exit (EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(1, "Client received an invalid number of arguments.\n", 48);
		write(1, "Run it as follows:\n./client <server pid> <message>\n", 51);
		exit (EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || !sendinfo(pid, av[2]))
	{
		write(1, "Client received an invalid server pid.\n", 40);
		write(1, "Please copy the pid of the server process.\n", 43);
		exit (EXIT_FAILURE);
	}
	while (1)
	{
		if (signal(SIGUSR2, msg_received))
			exit (EXIT_FAILURE);
		pause();
	}
}
