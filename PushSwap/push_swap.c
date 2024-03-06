/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: codespace <codespace@student.42.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/25 16:50:28 by codespace		 #+#	#+#			 */
/*   Updated: 2024/01/25 16:50:28 by codespace		###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "stacks.h"
#include "algorithm.h"
#include "main_utils.h"

static void	leave(t_stack **s, int *tmp)
{
	if (s)
		free_stack(s);
	if (tmp)
		free(tmp);
	ft_print("Error\n");
	exit (1);
}

int	main(int argc, char **argv)
{
	int		*tmp;
	t_stack	*stack;

	if (argc == 1)
		return (0);
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
