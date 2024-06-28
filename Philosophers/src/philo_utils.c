/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:18:54 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/28 20:41:35 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	free_and_exit(t_pass *shared, pthread_t *philos, int msg, int status)
{
	if (msg == SUCCESS)
		write(2, GREEN_BOLD"Success!\nSimulation over!\n"RESET, 37);
	if (msg == ERR_MEM)
		write(2, RED_BOLD"Error\nMemory allocation failed!\n"RESET, 43);
	if (msg == ERR_PTC)
		write(2, RED_BOLD"Error\nPThread creation failed!\n"RESET, 42);
	if (msg == ERR_PTJ)
		write(2, RED_BOLD"Error\nPThread joining failed!\n"RESET, 41);
	if (msg == ERR_GEN)
		write(2, RED_BOLD"Error\nUnexpected error occurred!\n"RESET, 44);
	if (msg == FAILURE)
		write(2, PURPLE_BOLD"Failure!\nA philosopher has died!\n"RESET, 44);
	if (shared->forks)
		free(shared->forks);
	if (shared->m_forks)
		free(shared->m_forks);
	if (philos)
		free(philos);
	exit (status);
}

t_bool	init_shared_info(t_pass *shared)
{
	int	i;

	shared->id = 0;
	shared->fed = 0;
	shared->start = 0;
	shared->dead_philo = False;
	ft_malloc((void **)&(shared->forks), shared->info[NP], sizeof(int));
	ft_malloc((void **)&(shared->m_forks), shared->info[NP],
		sizeof(pthread_mutex_t));
	if (!shared->forks || !shared->m_forks)
		return (False);
	i = 0;
	while (i < shared->info[NP])
	{
		if (pthread_mutex_init(shared->m_forks + i, NULL) != 0)
			return (False);
		shared->forks[i++] = 0;
	}
	if (pthread_mutex_init(&(shared->m_tid), NULL) != 0)
		return (False);
	if (pthread_mutex_init(&(shared->m_write), NULL) != 0)
		return (False);
	if (pthread_mutex_init(&(shared->m_death), NULL) != 0)
		return (False);
	return (True);
}

void	print_act(t_pass *s, int philo_id, char *act)
{
	pthread_mutex_lock(&(s->m_write));
	printf("%lu %d %s\n", militime() - s->start, philo_id + 1, act);
	pthread_mutex_unlock(&(s->m_write));
}

t_bool	dead_philo(t_pass *s)
{
	t_bool	ret;

	pthread_mutex_lock(&(s->m_death));
	ret = s->dead_philo;
	pthread_mutex_unlock(&(s->m_death));
	return (ret);
}

t_bool	ft_sleep(t_pass *s, int pid, unsigned long ms, unsigned long last)
{
	unsigned long	start;

	start = militime();
	while (militime() - start < ms)
	{
		if ((int)(militime() - last) >= s->info[DT])
			return (kill_philo(s, pid));
		if (dead_philo(s))
			return (False);
		usleep(250);
	}
	return (True);
}
