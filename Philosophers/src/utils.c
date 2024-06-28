/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:48:29 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/23 16:42:17 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_malloc(void **p, int elems, int size)
{
	*p = malloc(elems * size);
	return (*p);
}

int	ft_atoi(char *str)
{
	long	x;

	x = 0;
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + *str - '0';
		str++;
		if (x > INT_MAX)
			return (-1);
	}
	return (x);
}

unsigned long	militime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
