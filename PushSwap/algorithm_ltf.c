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
		rotate(s, 0, 1);
		i++;
	}
	if (ret > 1 || (ret == 1 && stack_end(*s) > top))
		return (0);
	while (stack_end(*s) < (*s)->value)
		ft_print(rotate(s, !(pos <= stack_size(*s) - pos), 1));
	return (1);
}

static void	ltf_stack_sort(t_stack **s)
{
	int	min;
	int	max;

	get_min_max(*s, &min, &max);
	while (!is_sorted(s))
	{
		while ((*s)->value > (*s)->next->value && !((*s)->value == max
				&& (*s)->next->value == min))
		{
			ft_print(swap_top(s, 1));
			if (is_sorted(s))
				break ;
			ft_print(rotate(s, (stack_end(*s) > (*s)->value
						&& stack_end(*s) <= (*s)->next->value), 1));
		}
		while (!is_sorted(s) && (*s)->value <= (*s)->next->value)
		{
			ft_print(rotate(s, (stack_end(*s) > (*s)->value
						&& stack_end(*s) <= (*s)->next->value), 1));
		}
		if ((*s)->value == max && (*s)->next->value == min)
			ft_print(rotate(s, 0, 1));
	}
}

void	sort_five_or_less(t_stack **s)
{
	int	tmp;
	int	pb;
	int	min;
	int	max;

	if (!s || !*s || !(*s)->next)
		return ;
	pb = 0;
	get_min_max(*s, &min, &max);
	if ((*s)->value == max && ((*s)->next->value == min || stack_size(*s) < 5))
		ft_print(rotate(s, 0, 1));
	if ((*s)->value == max)
	{
		tmp = pop(s);
		ft_print("pb\n");
		pb = 1;
	}
	ltf_stack_sort(s);
	if (pb)
	{
		push(s, new_node(tmp));
		ft_print("pa\n");
		ft_print(rotate(s, 0, 1));
	}
}
