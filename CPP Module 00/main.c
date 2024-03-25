/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:28:23 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/06 21:24:20 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "map_utils.h"
#include "hook_handles.h"
#include "render_utils.h"


int	exit_hook(t_map *g)
{
	free_up(g, 0, 0);
	return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	handle_deets(t_map g, t_deets ret)
{
	if (ret.ends == -1)
		return (7);
	if (!ret.ends)
		return (4);
	if (ret.discs != g.coins)
		return (5);
	return (0);
}

static int	setup_game(t_map *g, char **av)
{
	int		fd;
	char	**m;

	g->mvs = 0;
	g->speed = 10;
	g->mlx = mlx_init();
	if (!g->mlx)
		return (1);
	g->mw = mlx_new_window(g->mlx, g->cols * 64, g->rows * 64, "Hack & Battle");
	if (!g->mw)
		return (2);
	get_textures(g);
	fd = open(av[1], O_RDONLY);
	m = parse_map(fd, g);
	close(fd);
	if (!g->map)
		return (3);
	if (!m)
		return (9);
	if (handle_deets(*g, is_playable(*g, g->px, g->py)))
		return (handle_deets(*g, is_playable(*g, g->px, g->py)));
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		err;
	t_map	g;

	if (ac != 2 || ft_strlen(av[1]) < 5
		|| ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".ber"))
	{
		write(2, "Usage: ./so_long <map_name.ber>\n", 32);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	get_map_size(fd, &g.rows, &g.cols, &g);
	err = setup_game(&g, av);
	if (err)
		free_up(&g, err, EXIT_FAILURE);
	g.speed = 3;
	g.frame = 0;
	render_map(g);
	mlx_hook(g.mw, 17, 1L << 2, exit_hook, &g);
	mlx_hook(g.mw, 3, 0, handle_keys, &g);
	mlx_loop_hook(g.mlx, animations, &g);
	mlx_expose_hook(g.mw, expose_hook, &g);
	mlx_key_hook(g.mw, handle_keys, &g);
	mlx_loop(g.mlx);
	free_up(&g, 0, 0);
}
