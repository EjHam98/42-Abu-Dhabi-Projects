/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:35:43 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 19:24:36 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Split.h"

static size_t	word_count(char *s, char c)
{
	size_t	w;
	size_t	n;

	w = 0;
	n = 0;
	while (s[n])
	{
		while (s[n] == c)
			n++;
		if (s[n] != '\0')
			w++;
		while (s[n] && s[n] != c)
			n++;
	}
	return (w);
}

static char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;
	size_t	n;

	n = ft_strlen(s1);
	dst = malloc((n + 1) * sizeof(char));
	if (dst)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
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
				return (free_array(ret));
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
