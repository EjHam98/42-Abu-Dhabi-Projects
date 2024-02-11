/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:58 by codespace         #+#    #+#             */
/*   Updated: 2024/01/25 16:49:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra_utils.h"

int	valid_args(int c, char **s)
{
	int	i;
	int	j;

	if (!s || !*s || c < 2)
		return (0);
	i = 1;
	j = 0;
	while (i < c)
	{
		while (s[i][j] == ' ')
			j++;
		j += (s[i][0] == '-' || s[i][0] == '+');
		if (s[i][j] == '\0')
			return (0);
		while (s[i][j] >= '0' && s[i][j] <= '9')
			j++;
		if ((s[i][j] != '\0' && s[i][j] != ' ') || j == 0)
			return (0);
		while (s[i][j] == ' ')
			j++;
		if (s[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (1);
}

void	*fill_up(int *arr, char **newargv)
{
	int	i;

	if (!newargv)
	{
		if (arr)
			free(arr);
		return (NULL);
	}
	i = 0;
	while (arr && newargv[i])
	{
		arr[i] = ft_atoi(newargv[i]);
		i++;
	}
	i = 0;
	while (newargv[i])
		free(newargv[i++]);
	free(newargv);
	return (arr);
}

int	*parse_args(int *argc, char **argv)
{
	int		i;
	int		*arr;
	char	*all;
	char	**newargv;

	all = NULL;
	i = 1;
	while (i < *argc)
		all = ft_strjoin(all, argv[i++]);
	newargv = ft_split(all, ' ');
	if (all)
		free(all);
	if (!newargv)
		return (NULL);
	i = 0;
	while (newargv[i])
		i++;
	*argc = i;
	arr = malloc(sizeof(int) * i);
	return (fill_up(arr, newargv));
}

t_stack	*make_stack(int *arr, int size)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	// i = 0;
	// while (i < size)
	// 	push(&stack, new_node(arr[i++]));
	i = size - 1;
	while (i >= 0)
		push(&stack, new_node(arr[i--]));
	return (stack);
}

int	min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}