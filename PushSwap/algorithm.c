#include "stacks.h"

// void	sort_stack(t_stack **s)
// {
// 	int		direction;
// 	int		min;
// 	int		max;
// 	t_stack	*helper;

// 	min = 0;
// 	max = 0;
// 	helper = NULL;
// 	while (*s)
// 	{
// 		if (!helper)
// 		{
// 			move_top(s, &helper);
// 			min = helper->value;
// 			max = helper->value;
// 		}
// 		else
// 		{
// 			if (!direction)
// 				direction = 1 - 2 * ((*s)->value < helper->value);
// 			if (direction == 1)
// 			{
// 				if ((*s)->value < min)
// 				{
// 					while (helper->value != min)
// 						rotate(&helper, 1);
// 					rotate(&helper, 1);
// 					move_top(s, &helper);
// 					min =  helper->value;
// 				}
// 				else
// 				{
// 					while ((*s)->value < helper->value)
// 						rotate(&helper, stack_size(helper) - 1);
// 					move_top(s, &helper);
// 					if (helper->value > max)
// 						max = helper->value;
// 				}
// 			}
// 			else
// 			{
// 				if ((*s)->value > max)
// 				{
// 					while (helper->value != min)
// 						rotate(&helper, 1);
// 					move_top(s, &helper);
// 					max = helper->value;
// 				}
// 				else
// 				{
// 					while ((*s)->value > helper->value)
// 						rotate(&helper, stack_size(helper) - 1);
// 					move_top(s, &helper);
// 					if (helper->value < min)
// 						min = helper->value;
// 				}
// 			}
// 		}
// 	}
// 	*s = helper;
// }

void	sort_stack(t_stack **s)
{
	int		min;
	int		max;
	int		hv;
	int		sv;
	t_stack	*helper;

	min = 0;
	max = 0;
	helper = NULL;
	while (*s)
	{
		if (stack_size(helper) < 2)
			move_top(s, &helper);
		else
		{
			hv = helper->value;
			sv = (*s)->value;
			if (sv > max || sv < min)
			{
				while (hv < helper->next->value)
					rotate(helper, stack_size(helper) - 1);
				
			}
			else
			{
				
				
			}
			rotate(helper, 1);
			move_top(s, &helper);
		}
		if (helper->value > max)
			max = helper->value;
		if (helper->value < min)
			min = helper->value;
	}
	*s = helper;
}