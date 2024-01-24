/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:17:19 by ehammoud          #+#    #+#             */
/*   Updated: 2023/12/20 11:18:24 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

int	max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

size_t	ft_strlen(char *s)
{
	int	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}

int	loop_print(int condition, int num, int end, char c)
{
	int	n;

	n = 0;
	while (condition && (num)-- > end)
		n += write(1, &c, 1);
	return (n);
}
