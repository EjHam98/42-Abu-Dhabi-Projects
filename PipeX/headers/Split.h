/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:07:30 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 19:16:40 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
#define SPLIT_H

# include "Utils.h"
# include <stdlib.h>
# include <stdio.h>

char	**ft_split(char *s, char sep);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif