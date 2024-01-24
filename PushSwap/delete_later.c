#include "stacks.h"

void	read_stack(t_stack **s)
{
	printf(">> Enter the number of elements:\n");
	int n, x;
	scanf("%d", &n);
	int i;
	printf(">> Enter the values below:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d", &x);
		push(s, new_node(x));
	}
	printf(">> Reading Stack Done.");
}

void	print_stack(t_stack *s)
{
	if (!s)
	{
		printf("-- Empty t_stack --");
		return ;
	}
	while (s)
	{
		printf("%d\n", s->value);
		s = s->next;
	}
	printf("------\n");
}