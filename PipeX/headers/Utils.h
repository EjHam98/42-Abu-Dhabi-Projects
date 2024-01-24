/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:41:05 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 19:25:14 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

char	**free_array(char **arr);
size_t	ft_strlen(const char *str);
void	ft_print(char *str, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, int slash);

#endif