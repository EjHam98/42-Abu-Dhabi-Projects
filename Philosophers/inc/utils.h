/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:48:43 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/30 02:38:00 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>

unsigned long	militime(void);
int				ft_atoi(char *str);
void			*ft_malloc(void **p, int elems, int size);
int				left_index(int pid, int n);

#endif