/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:59:52 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/06 21:16:53 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra_utils.h"

void	ft_putnbr(int x)
{
	char	c;

	if (x > 9)
		ft_putnbr(x / 10);
	c = (x % 10) + '0';
	write(1, &c, 1);
}

static int	valid_borders(char **m, int r, int c)
{
	int	i;

	i = -1;
	while (++i < c)
	{
		if (m[0][i] != '1')
			return (0);
	}
	i = 0;
	while (++i < r)
	{
		if (m[i][0] != '1' || m[i][c - 1] != '1')
			return (0);
	}
	i = 0;
	while (++i < c)
	{
		if (m[r - 1][i] != '1')
			return (0);
	}
	return (1);
}

int	map_valid(char **m, int r, int c)
{
	int	i;
	int	j;
	int	e;
	int	p;
	int	cc;

	i = -1;
	e = 0;
	p = 0;
	cc = 0;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			e += (m[i][j] == 'E');
			p += (m[i][j] == 'P');
			cc += (m[i][j] == 'C');
			if (m[i][j] != '0' && m[i][j] != '1' && m[i][j] != 'P'
				&& m[i][j] != 'C' && m[i][j] != 'E')
				return (0);
		}
	}
	return (e == 1 && p == 1 && cc >= 1 && valid_borders(m, r, c));
}