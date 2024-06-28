/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:40:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/28 19:56:56 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_bool	kill_philo(t_pass *s, int pid)
{
	pthread_mutex_lock(&(s->m_death));
	s->dead_philo = True;
	pthread_mutex_unlock(&(s->m_death));
	print_act(s, pid, DYING);
	return (False);
}

int	fork_available(t_pass *s, int fork_cnt, int pid)
{
	int	left;
	int	right;
	int	ret;

	ret = 0;
	left = pid - 1;
	if (pid == 0)
		left = fork_cnt - 1;
	right = pid + 1;
	if (right == fork_cnt)
		right = 0;
	// printf("%d, %d, %d\n", left, pid, right);
	pthread_mutex_lock(&(s->m_forks[left]));
	ret += (s->forks[left] < 2) * LEFT;
	pthread_mutex_unlock(&(s->m_forks[left]));
	// printf("%d, %d, %d\n", left, pid, right);
	pthread_mutex_lock(&(s->m_forks[right]));
	ret += (s->forks[right] % 2 == 0) * RIGHT;
	pthread_mutex_unlock(&(s->m_forks[right]));
	// printf("%d, %d, %d\n", left, pid, right);
	pthread_mutex_lock(&(s->m_forks[pid]));
	if (ret == 3 || s->forks[pid] == ret)
		ret -= s->forks[pid];
	if (s->forks[pid] == 3)
		ret = 0;
	pthread_mutex_unlock(&(s->m_forks[pid]));
	// printf("%d, %d, %d\n", left, pid, right);
	return (ret);
}

t_bool	wait_for_fork(t_pass *s, int pid)
{
	int	fork;

	pthread_mutex_lock(&(s->m_forks[pid]));
	if (s->forks[pid] == BOTH)
	{
		pthread_mutex_unlock(&(s->m_forks[pid]));
		return (True);
	}
	pthread_mutex_unlock(&(s->m_forks[pid]));
	fork = fork_available(s, s->info[NP], pid);
	while (!fork)
	{
		// printf("--%d\n", fork);
		usleep(250);
		fork = fork_available(s, s->info[NP], pid);
		if (dead_philo(s))
			return (False);
	}
	pthread_mutex_lock(&(s->m_forks[pid]));
	s->forks[pid] += fork;
	pthread_mutex_unlock(&(s->m_forks[pid]));
	print_act(s, pid, FORKING);
	if (fork == BOTH)
		print_act(s, pid, FORKING);
	return (True);
}

t_bool	eating(t_pass *s, t_philo *p)
{
	p->ec++;
	print_act(s, p->id, EATING);
	p->le = militime();
	if (!ft_sleep(s, p->id, s->info[ET], p->le))
		return (False);
	return (True);
}

t_bool	sleeping(t_pass *s, t_philo *p)
{
	print_act(s, p->id, SLEEPING);
	pthread_mutex_lock(&(s->m_forks[p->id]));
	s->forks[p->id] = 0;
	pthread_mutex_unlock(&(s->m_forks[p->id]));
	if (!ft_sleep(s, p->id, s->info[ST], p->le))
		return (False);
	return (True);
}
