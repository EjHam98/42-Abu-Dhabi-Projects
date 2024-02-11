/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:17 by codespace         #+#    #+#             */
/*   Updated: 2024/01/27 08:46:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "stacks.h"
# include "extra_utils.h"

int 	is_sorted(t_stack **s);
void	sort_stack(t_stack **s);
void	sort_five_or_less(t_stack **s);
void	double_rotate(t_stack **s, t_stack **h, int *n1, int *n2);

#endif
