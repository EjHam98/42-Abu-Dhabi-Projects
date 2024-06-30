/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:40:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/30 04:31:11 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_bool	kill_philo(t_pass *s, int pid)
{
	pthread_mutex_lock(&(s->m_death));
	if (s->dead_philo)
	{
		pthread_mutex_unlock(&(s->m_death));
		return (False);
	}
	s->dead_philo = True;
	pthread_mutex_unlock(&(s->m_death));
	pthread_mutex_lock(&(s->m_write));
	printf(PURPLE"%-5lu %-3d %s\n"RESET, militime() - s->start, pid + 1, DYING);
	pthread_mutex_unlock(&(s->m_write));
	return (False);
}

int	fork_available(t_pass *s, int pid)
{
	int		ret;
	t_bool	skip;

	skip = False;
	ret = NONE;
	pthread_mutex_lock(&(s->m_forks[pid]));
	pthread_mutex_lock(&(s->m_forks[left_index(pid, s->info[NP])]));
	pthread_mutex_lock(&(s->m_fed));
	skip = (s->fed < s->info[NP] / 2 && (s->forks[pid] != AVAILABLE
			|| s->forks[left_index(pid, s->info[NP])] != AVAILABLE));
	pthread_mutex_unlock(&(s->m_fed));
	if (s->forks[left_index(pid, s->info[NP])] == AVAILABLE && !skip)
	{
		s->forks[left_index(pid, s->info[NP])] = pid;
		ret += LEFT;
	}
	if (s->forks[pid] == AVAILABLE && !skip)
	{
		s->forks[pid] = pid;
		ret += RIGHT;
	}
	pthread_mutex_unlock(&(s->m_forks[left_index(pid, s->info[NP])]));
	pthread_mutex_unlock(&(s->m_forks[pid]));
	return (ret);
}

t_bool	wait_for_fork(t_pass *s, t_philo *p)
{
	int	fork;

	pthread_mutex_lock(&(s->m_forks[p->id]));
	pthread_mutex_lock(&(s->m_forks[left_index(p->id, s->info[NP])]));
	fork = -1 * (s->forks[p->id] == p->id
		&& s->forks[left_index(p->id, s->info[NP])] == p->id);
	pthread_mutex_unlock(&(s->m_forks[left_index(p->id, s->info[NP])]));
	pthread_mutex_unlock(&(s->m_forks[p->id]));
	if (fork == -1)
		return (True);
	while (True)
	{
		fork = fork_available(s, p->id);
		if (dead_philo(s))
			return (False);
		if ((int)(militime() - p->le) >= s->info[DT])
			return (kill_philo(s, p->id));
		if (fork)
			break ;
		usleep(100);
	}
	print_act(s, p->id, FORKING, 0);
	if (fork == BOTH)
		print_act(s, p->id, FORKING, 0);
	return (True);
}

t_bool	eating(t_pass *s, t_philo *p)
{
	p->ec++;
	print_act(s, p->id, EATING, 1);
	pthread_mutex_lock(&(s->m_fed));
	s->fed++;
	pthread_mutex_unlock(&(s->m_fed));
	p->le = militime();
	if (!ft_sleep(s, p->id, s->info[ET], p->le))
		return (False);
	return (True);
}

t_bool	sleeping(t_pass *s, t_philo *p)
{
	if (dead_philo(s))
		return (False);
	if (s->info[TTE] != p->ec)
		print_act(s, p->id, SLEEPING, 2);
	pthread_mutex_lock(&(s->m_forks[p->id]));
	s->forks[p->id] = AVAILABLE;
	s->forks[left_index(p->id, s->info[NP])] = AVAILABLE;
	pthread_mutex_unlock(&(s->m_forks[p->id]));
	if (s->info[TTE] == p->ec)
		return (True);
	if (!ft_sleep(s, p->id, s->info[ST], p->le))
		return (False);
	return (True);
}
