#include "get_next_line.h"
#include "stacks.h"
#include "algorithm.h"
#include "extra_utils.h"

static int  ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\n')
		return (1);
	return (s1[i] - s2[i] == 0);
}

static int	stack_sorted(t_stack *s)
{
	if (!s || !s->next)
		return (1);
	while (s->next && s->value < s->next->value)
		s = s->next;
	return (s->next == NULL);
}

static int	has_dups(int *arr, int c)
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

static void    leave(t_stack **a, t_stack **b, int *tmp)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (tmp)
		free(tmp);
	printf("Error\n");
	exit (1);
}

int main(int argc, char **argv)
{
	int		*tmp;
	t_stack *h;
	t_stack	*stack;
	char    *move;
	int		err;

	if (!valid_args(argc, argv))
		leave(NULL, NULL, NULL);
	tmp = parse_args(&argc, argv);
	if (!tmp || has_dups(tmp, argc))
		leave(NULL, NULL, tmp);
	stack = make_stack(tmp, argc);
	if (!stack)
		leave(NULL, NULL, tmp);
	free(tmp);
	h = NULL;
	err = 0;
	move = get_next_line(0);
	while (move)
	{
		if (!err && ft_strcmp(move, "pa\n"))
			move_top(&h, &stack, 0);
		else if (!err && ft_strcmp(move, "pb\n"))
			move_top(&stack, &h, 0);
		else if (!err && ft_strcmp(move, "sa\n"))
			swap_top(&stack, 0);
		else if (!err && ft_strcmp(move, "sb\n"))
			swap_top(&h, 1);
		else if (!err && ft_strcmp(move, "ss\n"))
		{
			swap_top(&stack, 0);
			swap_top(&h, 1);
		}
		else if (!err && ft_strcmp(move, "ra\n"))
			rotate(&stack, "ra");
		else if (!err && ft_strcmp(move, "rb\n"))
			rotate(&h, "rb");
		else if (!err && ft_strcmp(move, "rr\n"))
		{
			rotate(&stack, "ra");
			rotate(&h, "rb");
		}
		else if (!err && ft_strcmp(move, "rra\n"))
			rotate(&stack, "rra");
		else if (!err && ft_strcmp(move, "rrb\n"))
			rotate(&h, "rrb");
		else if (!err && ft_strcmp(move, "rrr\n"))
		{
			rotate(&stack, "rra");
			rotate(&h, "rrb");
		}
		else
			err = 1;
		free(move);
		move = get_next_line(0);
	}
	if (err)
		leave(&stack, &h, NULL);
	if (!stack_sorted(stack))
		printf("KO\n");
	else
		printf("OK\n");
	free_stack(&stack);
	free_stack(&h);
}