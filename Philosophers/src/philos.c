/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:08:05 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/28 18:17:34 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philos.h>

void	*routine(void *data)
{
	t_pass		*s;
	t_philo		p;

	s = (t_pass *)data;
	pthread_mutex_lock(&(s->m_tid));
	p.id = s->id++;
	if (!s->start)
		s->start = militime();
	pthread_mutex_unlock(&(s->m_tid));
	p.le = militime();
	p.ec = 0;
	while (p.ec < s->info[TTE] || s->info[TTE] == -1)
	{
		if (dead_philo(s))
			return (NULL);
		if (p.ec)
			print_act(s, p.id, THINKING);
		if (!wait_for_fork(s, p.id) || !wait_for_fork(s, p.id))
			return (NULL);
		if (!eating(s, &p))
			return (NULL);
		if (!sleeping(s, &p))
			return (NULL);
	}
	return (NULL);
}

int	run_threads(pthread_t *philos, t_pass *shared, void *(*f)(void *))
{
	int	i;

	i = 0;
	while (i < shared->info[NP])
	{
		if (pthread_create(philos + i++, NULL, f, shared) != 0)
			return (ERR_PTC);
	}
	i = 0;
	while (i < shared->info[NP])
	{
		if (pthread_join(philos[i++], NULL))
			return (ERR_PTJ);
	}
	return (0);
}

void	handle_philos(int *info)
{
	t_pass		shared;
	pthread_t	*philos;
	int			ret;

	if (!ft_malloc((void **)&philos, info[NP], sizeof(pthread_t)))
		free_and_exit(NULL, NULL, ERR_MEM, 1);
	shared.info = info;
	init_shared_info(&shared);
	ret = run_threads(philos, &shared, routine);
	if (ret)
		free_and_exit(&shared, philos, ret, 1);
	else if (shared.dead_philo)
		free_and_exit(&shared, philos, FAILURE, 0);
	/*	 	Dont forget to destroy mutexes 		*/
	pthread_mutex_destroy(&shared.m_death);
	pthread_mutex_destroy(shared.m_forks);
	pthread_mutex_destroy(&shared.m_tid);
	pthread_mutex_destroy(&shared.m_write);
	/*		 Dont forget to destroy mutexes 	*/
	free_and_exit(&shared, philos, SUCCESS, 0);
}
