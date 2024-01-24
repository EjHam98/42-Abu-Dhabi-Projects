#include "stacks.h"

t_stack	*get_node(t_stack *s, int index)
{
	int	n;

	if (!s || index < 0 || index >= stack_size(s))
		return (NULL);
	n = 0;
	while (n < index)
	{
		s = s->next;
		n++;
	}
	return (s);
}

t_stack	*last_node(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	rotate(t_stack **s, int rots)
{
	t_stack	*cutoff;
	t_stack	*last;

	if (!s || !(*s))
		return (-1);
	cutoff = get_node(*s, rots - 1);
	if (!cutoff)
		return (-1);
	last = last_node(*s);
	last->next = *s;
	*s = cutoff->next;
	cutoff->next = NULL;
	return ((*s)->value);
}

void	move_top(t_stack **s1, t_stack **s2)
{
	if (!s1 || !(*s1) || !s2)
		return ;
	push(s2, new_node(pop(s1)));
}

void	swap_top(t_stack **s1, t_stack **s2)
{
	int	tmp;

	if (!s1 || !s2 || !(*s1) || !(*s2))
		return ;
	tmp = pop(s2);
	move_top(s1, s2);
	push(s1, new_node(tmp));
}
