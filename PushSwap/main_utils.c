/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:46:48 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/24 16:36:07 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_utils.h"

static void	*fill_up(int *arr, char **newargv)
{
	int	i;

	if (!newargv && arr)
		free(arr);
	if (!newargv)
		return (NULL);
	i = 0;
	while (arr && newargv[i])
	{
		arr[i] = ft_atoi(newargv[i]);
		if ((arr[i] < 0 && newargv[i][0] != '-')
			|| (arr[i] >= 0 && newargv[i][0] == '-'))
		{
			free(arr);
			arr = NULL;
			break ;
		}
		i++;
	}
	i = 0;
	while (newargv[i])
		free(newargv[i++]);
	free(newargv);
	return (arr);
}

int	valid_args(int c, char **s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < c)
	{
		while (s[i][j] == ' ')
			j++;
		j += (s[i][j] == '-' || s[i][j] == '+');
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
