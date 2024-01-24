/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:02:51 by ehammoud          #+#    #+#             */
/*   Updated: 2024/01/11 20:20:04 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PipeX.h"

int	main(int ac, char **av, char **env)
{
	char	*path;

	if (ac < 5)
	{
		ft_print("Not enough arguments.", 2);
		ft_print("Usage: ./pipex <infile> <cmd1> <cmd2> ... <cmdn> <outfile>", 2);
		exit (EXIT_FAILURE);
	}
	path = get_path(env);
	handle(av + 1, ac - 1, path, env);
}
