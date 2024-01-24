/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:16:19 by ehammoud          #+#    #+#             */
/*   Updated: 2024/01/11 16:35:29 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_utils.h"

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1u];
	char		*ret;
	int			bytes;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	ret = NULL;
	while (!ret || !ft_strchr(ret, '\n'))
	{
		if (buffer[fd][0] == '\0')
		{
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes == 0)
				return (ret);
			if (bytes < 0 && ret)
				free (ret);
			if (bytes < 0)
				return (NULL);
			buffer[fd][bytes] = '\0';
		}
		ret = ft_add_next(ret, buffer[fd]);
	}
	return (ret);
}
