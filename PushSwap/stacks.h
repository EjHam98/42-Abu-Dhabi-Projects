#ifndef STACKS_H
# define STACKS_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct stack_node
{
	int					value;
	struct stack_node	*next;
}	t_stack;

int		pop(t_stack **s);
int		push(t_stack **s, t_stack *node);
int		stack_size(t_stack *s);
t_stack	*new_node(int value);
void	free_stack(t_stack **s);
t_stack	*get_node(t_stack *s, int index);
t_stack	*last_node(t_stack *s);
int		rotate(t_stack **s, int rots);
void	move_top(t_stack **s1, t_stack **s2);
void	swap_top(t_stack **s1, t_stack **s2);
int		valid_args(int c, char **s);
int		ft_atoi(char *str);
int		*parse_args(int argc, char **argv);
t_stack	*make_stack(int *arr, int size);
void	sort_stack(t_stack **s);
void	print_stack(t_stack *s);
void	read_stack(t_stack **s);

#endif