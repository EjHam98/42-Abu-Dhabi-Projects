/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:00:07 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/21 15:54:32 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_UTILS_H
# define CHECKER_UTILS_H

# include "get_next_line.h"
# include "stacks.h"
# include "algorithm.h"
# include "extra_utils.h"
# include "main_utils.h"

int	stack_sorted(t_stack *s);
int	has_dups(int *arr, int c);
int	apply_move1(t_stack **stack, t_stack **h, char *move);
int	apply_move2(t_stack **stack, t_stack **h, char *move);

#endif