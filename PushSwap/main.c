#include "stacks.h"

int main(int argc, char **argv)
{
	int		*tmp;
	t_stack	*stack;

	if (!valid_args(argc, argv))
	{
		printf ("Invalid args");
		return (1);
	}
	tmp = parse_args(argc, argv);
	if (!tmp)
	{
		printf("Parsing of args failed");
		return (1);
	}
	stack = make_stack(tmp, argc - 1);
	free(tmp);
	print_stack(stack);
	sort_stack(&stack);
	print_stack(stack);
	free_stack(&stack);
}
