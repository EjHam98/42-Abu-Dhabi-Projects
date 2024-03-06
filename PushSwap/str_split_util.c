/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:00:18 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/20 11:00:19 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra_utils.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n || len == 0 || s[0] == '\0')
		return (ft_strdup(""));
	if (start + len > n)
		j = n - start;
	else
		j = len;
	news = malloc((j + 1) * sizeof(char));
	if (!news)
		return (NULL);
	j = 0;
	i = start;
	while (s[i] != '\0' && j < len)
		news[j++] = s[i++];
	news[j] = '\0';
	return (news);
}

static int	word_count(char *s, char sep)
{
	size_t	i;
	size_t	c;
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if (s[i] == sep && c > 0)
		{
			n++;
			c = 0;
		}
		else if (s[i] != sep)
			c++;
		i++;
	}
	if (c > 0)
		n++;
	return (n);
}

static char	**ft_freeup(char **arr)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**populate(char **ret, char *str, char sep)
{
	size_t	i;
	size_t	j;
	size_t	wc;

	if (!ret || !str)
		return (NULL);
	wc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] && str[i + j] != sep)
			j++;
		if (j > 0)
		{
			ret[wc++] = ft_substr(str, i, j);
			if (ret[wc - 1] == NULL)
				return (ft_freeup(ret));
		}
		i += j + (j == 0);
	}
	ret[wc] = NULL;
	return (ret);
}

char	**ft_split(char *s, char sep)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc((word_count(s, sep) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret = populate(ret, s, sep);
	return (ret);
}
