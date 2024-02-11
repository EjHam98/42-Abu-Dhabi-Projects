/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:03 by codespace         #+#    #+#             */
/*   Updated: 2024/01/25 16:50:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	is_sorted(t_stack **s)
{
	int	ret;
	int	top;
	int	pos;
	int	i;

	if (!(*s) || !(*s)->next)
		return (1);
	top = (*s)->value;
	i = 0;
	ret = 0;
	while (i < stack_size(*s))
	{
		if (i < stack_size(*s) - 1 && (*s)->value > (*s)->next->value)
			ret++;
		if (i < stack_size(*s) - 1 && (*s)->value > (*s)->next->value)
			pos = i + 1;
		rotate(s, "ra");
		i++;
	}
	if (ret > 1 || (ret == 1 && stack_end(*s) > top))
		return (0);
	while (stack_end(*s) < (*s)->value)
		printf("%s", rotate(s, "rra\n" + (pos <= stack_size(*s) - pos)));
	return (1);
}

static void	ltf_stack_sort(t_stack **s, int min, int max)
{
	while (!is_sorted(s))
	{
		while ((*s)->value > (*s)->next->value && !((*s)->value == max && (*s)->next->value == min))
		{
			printf("%s", swap_top(s, 1));
			if (is_sorted(s))
				break ;
			printf("%s", rotate(s, "rra\n" + !(stack_end(*s) > (*s)->value
				&& stack_end(*s) <= (*s)->next->value)));
		}
		while (!is_sorted(s) && (*s)->value <= (*s)->next->value)
		{
			printf("%s", rotate(s, "rra\n" + !(stack_end(*s) > (*s)->value
				&& stack_end(*s) <= (*s)->next->value)));
		}
		if ((*s)->value == max && (*s)->next->value == min)
			printf("%s", rotate(s, "ra\n"));
	}
}

void	double_rotate(t_stack **s, t_stack **h, int *n1, int *n2)
{
	if (!h || !s || !(*h) || !(*s))
		return ;
	while (*n1 < 0 && *n2 < 0)
	{
		rotate(s, "rra");
		rotate(h, "rrb");
		printf("%s", "rrr\n");
		(*n1)++;
		(*n2)++;
	}
	while (*n1 > 0 && *n2 > 0)
	{
		rotate(s, "ra");
		rotate(h, "rb");
		printf("%s", "rr\n");
		(*n1)--;
		(*n2)--;
	}
}

void	sort_five_or_less(t_stack **s)
{
	int	min;
	int	max;
	int	tmp;
	int	pb;

	if (!s || !*s || !(*s)->next)
		return ;
	get_min_max(*s, &min, &max);
	pb = 0;
	if ((*s)->value == max)
	{
		if ((*s)->next->value == min || stack_size(*s) < 5)
			printf("%s", rotate(s, "ra\n"));
		else
		{
			tmp = pop(s);
			printf("%s", "pb\n");
			pb = 1;
			get_min_max(*s, &min, &max);
		}
	}
	ltf_stack_sort(s, min, max);
	if (pb)
	{
		push(s, new_node(tmp));
		printf("%s", "pa\n");
		printf("%s", rotate(s, "ra\n"));
	}
}
