/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:49:47 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/24 15:04:21 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_utils.h"

static void	leave(t_stack **a, t_stack **b, int *tmp, int status)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (tmp)
		free(tmp);
	if (status == 2)
		ft_print("Error\n");
	else if (status == 1)
		ft_print("KO\n");
	else
		ft_print("OK\n");
	exit ((status == 2));
}

static t_stack	*handle_args(int argc, char **argv)
{
	int		*tmp;
	t_stack	*s;

	if (!valid_args(argc, argv))
		leave(NULL, NULL, NULL, 2);
	tmp = parse_args(&argc, argv);
	if (!tmp || has_dups(tmp, argc))
		leave(NULL, NULL, tmp, 2);
	s = make_stack(tmp, argc);
	if (!s)
		leave(NULL, NULL, tmp, 2);
	free(tmp);
	return (s);
}

int	main(int argc, char **argv)
{
	char	*move;
	int		err;
	t_stack	*h;
	t_stack	*stack;

	if (argc == 1)
		return (0);
	h = NULL;
	stack = handle_args(argc, argv);
	move = get_next_line(0);
	err = 0;
	while (move)
	{
		if (!err
			&& !apply_move1(&stack, &h, move) && !apply_move2(&stack, &h, move))
			err = 1;
		free(move);
		move = get_next_line(0);
	}
	if (err)
		leave(&stack, &h, NULL, 2);
	leave(&stack, &h, NULL, !stack_sorted(stack));
}
