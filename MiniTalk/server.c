/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:09:17 by ehammoud          #+#    #+#             */
/*   Updated: 2024/01/15 15:11:54 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void	ft_printint(int x)
{
	char	c;

	if (x == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (x < 0)
	{
		write(1, "-", 1);
		ft_printint(x * -1);
	}
	if (x > 9)
		ft_printint(x / 10);
	c = (x % 10) + '0';
	write(1, &c, 1);
}

static void	signal_handler(int sid, siginfo_t *info, void *context)
{
	static int	bits_read = 0;
	static char	full_char = 0;

	(void)context;
	bits_read++;
	full_char = full_char * 2 + (sid == SIGUSR2);
	if (bits_read == 8)
	{
		write(1, &full_char, 1);
		if (!full_char)
		{
			write(1, "\n", 1);
			usleep(250);
			if (kill(info->si_pid, SIGUSR2) != 0)
				exit (EXIT_FAILURE);
		}
		full_char = 0;
		bits_read = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	act.sa_sigaction = signal_handler;
	act.sa_mask = block_mask;
	act.sa_flags = 0;
	write(1, "Server PID: ", 12);
	ft_printint(getpid());
	write(1, "\n", 1);
	while (1)
	{
		if (sigaction(SIGUSR2, &act, NULL) != 0)
			exit (EXIT_FAILURE);
		if (sigaction(SIGUSR1, &act, NULL) != 0)
			exit (EXIT_FAILURE);
		pause();
	}
}
