/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:54:48 by codespace         #+#    #+#             */
/*   Updated: 2024/02/04 20:54:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	pushable(t_stack *a, t_stack *b)
{
	if (!a)
		return (-1);
	if (!b || !b->next)
		return (1);
    return ((a->value >= b->value && a->value <= stack_end(b))
        || (a->value <= b->value && a->value >= stack_end(b)));
}



static int  best_rots(t_stack *a, t_stack *b)
{
    int r1;
    int r2;
    int i;

    r1 = 0;
    r2 = 1;
    if (!a)
        return (INT_MAX);
    if (!b || !b->next)
        return (0);
    i = 0;
    while (!pushable(a, b))
    {
        rotate(&b, 0);
        i++;
    }
    // while (i < stack_size(b))
}

void	sort_stack(t_stack **s)
{
    t_stack *h;

    while (s)
    {

    }
}