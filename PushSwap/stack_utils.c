/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:20 by codespace         #+#    #+#             */
/*   Updated: 2024/01/25 16:50:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

char	*rotate(t_stack **s, char *str)
{
	t_stack	*tmp;

	if (!s || !(*s) || !(*s)->next)
		return ("");
	if (str && str[0] == 'r' && str[1] == 'r')
	{
		tmp = *s;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *s;
		*s = tmp->next;
		tmp->next = NULL;
		return (str);
	}
	tmp = *s;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *s;
	*s = (*s)->next;
	tmp->next->next = NULL;
	return (str);
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

int	stack_end(t_stack *s)
{
	if (!s)
		return (-1);
	while (s->next)
		s = s->next;
	return (s->value);
}

void	get_min_max(t_stack *s, int *min, int *max)
{
	if (!s)
		return ;
	*min = s->value;
	*max = s->value;
	while (s)
	{
		if (s->value > *max)
			*max = s->value;
		if (s->value < *min)
			*min = s->value;
		s = s->next;
	}
}
