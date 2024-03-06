/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   algorithm.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: codespace <codespace@student.42.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/25 16:50:03 by codespace		 #+#	#+#			 */
/*   Updated: 2024/01/25 16:50:03 by codespace		###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "algorithm.h"

static int	rotations(int a, t_stack *b)
{
	int	i;
	int	forwards;
	int	backward;

	if (!b || !b->next)
		return (0);
	i = 0;
	forwards = -1;
	while (i < stack_size(b))
	{
		forwards += (i + 1) * (((a >= b->value && (a <= stack_end(b)
							|| stack_end(b) < b->value)) || (a <= b->value
						&& a <= stack_end(b) && stack_end(b) < b->value))
				&& forwards == -1);
		backward = stack_size(b) - forwards;
		rotate(&b, 0, 0);
		i++;
	}
	if (forwards <= backward)
		return (forwards);
	return (-1 * backward);
}

static int	get_moves(t_stack *s, t_stack *h, int i)
{
	int	m1;
	int	m2;

	m1 = i - (stack_size(s) - i < i) * stack_size(s);
	m2 = rotations(s->value, h);
	if ((m1 >= 0 && m2 <= 0) || (m1 <= 0 && m2 >= 0))
		return (abs(m1 - m2));
	if (abs(m1) >= abs(m2))
		return (abs(m1));
	return (abs(m2));
}

static void	place(t_stack **s, t_stack **h)
{
	int	i;
	int	p;
	int	v;
	int	moves;

	p = 0;
	moves = 0;
	i = 0;
	while (i < stack_size(*s))
	{
		if (!i || moves > get_moves(*s, *h, i))
		{
			moves = get_moves(*s, *h, i);
			p = i;
			v = (*s)->value;
		}
		rotate(s, 0, 1);
		i++;
	}
	i = p - (p > stack_size(*s) - p) * stack_size(*s);
	n_rotations(s, i, h, rotations(v, *h));
	ft_print(move_top(s, h, 1));
}

void	clean_up(t_stack **s, t_stack **h)
{
	if (*h && (*s)->value <= (*h)->value)
	{
		while (*h && stack_end(*s) >= (*h)->value)
			ft_print(rotate(s, 1, 1));
	}
	while (*h)
	{
		ft_print(move_top(h, s, 0));
		while (*h && stack_end(*s) <= (*s)->value
			&& stack_end(*s) >= (*h)->value)
			ft_print(rotate(s, 1, 1));
	}
	is_sorted(s);
	free_stack(h);
}

void	sort_stack(t_stack **s)
{
	int		i;
	int		p;
	t_stack	*h;

	if (!s || !(*s) || !(*s)->next || is_sorted(s))
		return ;
	h = NULL;
	while (!is_sorted(s) && stack_size(*s) > 5)
		place(s, &h);
	if (!is_sorted(s))
		sort_five_or_less(s);
	i = 0;
	p = 0;
	while (h && h->next && i < stack_size(h))
	{
		if (h->value < h->next->value)
			p = i + 1;
		i++;
		rotate(&h, 0, 0);
	}
	n_rotations(NULL, 0, &h, p - (stack_size(h) - p < p) * stack_size(h));
	clean_up(s, &h);
}
