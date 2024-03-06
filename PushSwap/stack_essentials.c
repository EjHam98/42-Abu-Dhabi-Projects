/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   stack_essentials.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: codespace <codespace@student.42.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/25 16:50:24 by codespace		 #+#	#+#			 */
/*   Updated: 2024/01/25 16:50:24 by codespace		###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "stacks.h"

int	pop(t_stack **s)
{
	int		n;
	t_stack	*tmp;

	if (!s || !(*s))
		return (-1);
	tmp = *s;
	n = tmp->value;
	*s = tmp->next;
	free(tmp);
	return (n);
}

int	push(t_stack **s, t_stack *node)
{
	if (!s || !node)
		return (-1);
	if (!(*s))
		*s = node;
	else
	{
		node->next = *s;
		*s = node;
	}
	return (node->value);
}

int	stack_size(t_stack *s)
{
	int	n;

	n = 0;
	while (s)
	{
		s = s->next;
		n++;
	}
	return (n);
}

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !(*s))
		return ;
	while (*s)
	{
		tmp = *s;
		*s = (*s)->next;
		free(tmp);
	}
}
