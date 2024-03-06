/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:07:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/20 13:07:33 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

char	*rotate(t_stack **s, int r, int a)
{
	t_stack	*tmp;

	if (!s || !(*s) || !(*s)->next)
		return ("");
	tmp = *s;
	while ((!r && tmp->next) || (r && tmp->next->next))
		tmp = tmp->next;
	if (r)
	{
		tmp->next->next = *s;
		*s = tmp->next;
		tmp->next = NULL;
		if (a)
			return ("rra\n");
		return ("rrb\n");
	}
	tmp->next = *s;
	*s = (*s)->next;
	tmp->next->next = NULL;
	if (a)
		return ("ra\n");
	return ("rb\n");
}

char	*move_top(t_stack **s1, t_stack **s2, int atb)
{
	if (!s1 || !(*s1) || !s2)
		return ("");
	push(s2, new_node(pop(s1)));
	if (atb)
		return ("pb\n");
	return ("pa\n");
}

char	*swap_top(t_stack **s, int a)
{
	t_stack	*tmp;

	if (!s || !(*s) || !(*s)->next)
		return ("");
	tmp = *s;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	(*s)->next = tmp;
	if (a)
		return ("sa\n");
	return ("sb\n");
}

void	double_rotate(t_stack **s, t_stack **h, int *n1, int *n2)
{
	if (!h || !s || !(*h) || !(*s))
		return ;
	while (*n1 < 0 && *n2 < 0)
	{
		rotate(s, 1, 1);
		rotate(h, 1, 0);
		ft_print("rrr\n");
		(*n1)++;
		(*n2)++;
	}
	while (*n1 > 0 && *n2 > 0)
	{
		rotate(s, 0, 1);
		rotate(h, 0, 0);
		ft_print("rr\n");
		(*n1)--;
		(*n2)--;
	}
}

void	ft_print(char *s)
{
	if (ft_strcmp(s, "Error\n"))
		write(2, "Error\n", 6);
	else
		write(1, s, ft_strlen(s));
}
