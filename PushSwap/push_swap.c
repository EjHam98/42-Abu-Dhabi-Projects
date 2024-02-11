/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:28 by codespace         #+#    #+#             */
/*   Updated: 2024/01/25 16:50:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "algorithm.h"
#include "extra_utils.h"

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

static void	leave(t_stack **s, int *tmp)
{
	if (s)
		free_stack(s);
	if (tmp)
		free(tmp);
	printf("Error\n");
	exit (1);
}

int main(int argc, char **argv)
{
	int		*tmp;
	t_stack	*stack;

	if (!valid_args(argc, argv))
		leave(NULL, NULL);
	tmp = parse_args(&argc, argv);
	if (!tmp || has_dups(tmp, argc))
		leave(NULL, tmp);
	stack = make_stack(tmp, argc);
	if (!stack)
		leave(&stack, tmp);
	free(tmp);
	sort_stack(&stack);
	free_stack(&stack);
}
