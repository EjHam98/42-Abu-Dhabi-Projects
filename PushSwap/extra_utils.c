/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   extra_utils.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: codespace <codespace@student.42.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/25 16:49:58 by codespace		 #+#	#+#			 */
/*   Updated: 2024/01/25 16:49:58 by codespace		###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "extra_utils.h"

t_stack	*make_stack(int *arr, int size)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = size - 1;
	while (i >= 0)
		push(&stack, new_node(arr[i--]));
	return (stack);
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

void	n_rotations(t_stack **s, int n1, t_stack **h, int n2)
{
	if ((n1 < 0 && n2 < 0) || (n1 > 0 && n2 > 0))
		double_rotate(s, h, &n1, &n2);
	while (s && *s && n1 < 0)
	{
		ft_print(rotate(s, 1, 1));
		n1++;
	}
	while (s && *s && n1 > 0)
	{
		ft_print(rotate(s, 0, 1));
		n1--;
	}
	while (h && *h && n2 < 0)
	{
		ft_print(rotate(h, 1, 0));
		n2++;
	}
	while (h && *h && n2 > 0)
	{
		ft_print(rotate(h, 0, 0));
		n2--;
	}
}

int	has_dups(int *arr, int c)
{
	int	i;
	int	j;

	i = 0;
	while (++i < c)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}
