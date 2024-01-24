/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:40:50 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 19:52:19 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	ft_print(char *str, int fd)
{
	if (!str)
		write(2, "(null)\n", 7);
	else
	{
		write(2, str, ft_strlen(str));
		if (fd == 2)
			write(2, "\n", 1);
	}
}

char	**free_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i++])
		free(arr[i - 1]);
	if (arr)
		free(arr);
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2, int slash)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (slash != 1 && slash != 0)
		return (NULL);
	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1 + slash) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	if (slash)
		ret[i++] = '/';
	j = 0;
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
