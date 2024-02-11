/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_later.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:33 by codespace         #+#    #+#             */
/*   Updated: 2024/01/25 16:50:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	read_stack(t_stack **s)
{
	printf("%s", ">> Enter the number of elements:\n");
	int n, x;
	scanf("%d", &n);
	int i;
	printf("%s", ">> Enter the values below:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d", &x);
		push(s, new_node(x));
	}
	printf("%s", ">> Reading Stack Done.\n");
}

void	print_stack(t_stack *s)
{
	printf("%s", "------\n");
	if (!s)
		printf("%s", "-- Empty t_stack --");
	while (s)
	{
		printf("%d\n", s->value);
		s = s->next;
	}
	printf("%s", "------\n");
}