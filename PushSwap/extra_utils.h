/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:17 by codespace         #+#    #+#             */
/*   Updated: 2024/01/26 08:12:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_UTILS_H
# define EXTRA_UTILS_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "stacks.h"

char	*ft_strdup(const char *s1);
size_t   ft_strlen(const char *str);
char	**ft_split(char *s, char sep);
char	*ft_strjoin(char *s1, char *s2);
int		valid_args(int c, char **s);
int		ft_atoi(char *str);
int		*parse_args(int *argc, char **argv);
t_stack	*make_stack(int *arr, int size);
int     min(int x, int y);

void	read_stack(t_stack **s);
void	print_stack(t_stack *s);

#endif