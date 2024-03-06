/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:58:28 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/21 15:56:18 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_utils.h"

int	stack_sorted(t_stack *s)
{
	if (!s || !s->next)
		return (1);
	while (s->next && s->value < s->next->value)
		s = s->next;
	return (s->next == NULL);
}

int	apply_move1(t_stack **stack, t_stack **h, char *move)
{
	if (ft_strcmp(move, "pa\n"))
		move_top(h, stack, 0);
	else if (ft_strcmp(move, "pb\n"))
		move_top(stack, h, 0);
	else if (ft_strcmp(move, "sa\n"))
		swap_top(stack, 0);
	else if (ft_strcmp(move, "sb\n"))
		swap_top(h, 1);
	else if (ft_strcmp(move, "ss\n"))
	{
		swap_top(stack, 0);
		swap_top(h, 1);
	}
	else
		return (0);
	return (1);
}

int	apply_move2(t_stack **stack, t_stack **h, char *move)
{
	if (ft_strcmp(move, "ra\n"))
		rotate(stack, 0, 1);
	else if (ft_strcmp(move, "rb\n"))
		rotate(h, 0, 0);
	else if (ft_strcmp(move, "rr\n"))
	{
		rotate(stack, 0, 1);
		rotate(h, 0, 0);
	}
	else if (ft_strcmp(move, "rra\n"))
		rotate(stack, 1, 1);
	else if (ft_strcmp(move, "rrb\n"))
		rotate(h, 1, 0);
	else if (ft_strcmp(move, "rrr\n"))
	{
		rotate(stack, 1, 1);
		rotate(h, 1, 0);
	}
	else
		return (0);
	return (1);
}
