/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:00:45 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/26 20:05:00 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_utils.h"

void	get_textures(t_map *g)
{
	int	x;
	int	y;

	g->on_end = 0;
	g->tex.e.upside = mlx_xpm_file_to_image(g->mlx, "./tex/UpTile.xpm", &x, &y);
	g->tex.e.leftside = mlx_xpm_file_to_image(g->mlx, "./tex/RightTile.xpm", &x, &y);
	g->tex.e.rightside = mlx_xpm_file_to_image(g->mlx, "./tex/LeftTile.xpm", &x, &y);
	g->tex.e.downside = mlx_xpm_file_to_image(g->mlx, "./tex/DownTile.xpm", &x, &y);
	g->tex.e.trside = mlx_xpm_file_to_image(g->mlx, "./tex/TRTile.xpm", &x, &y);
	g->tex.e.tlside = mlx_xpm_file_to_image(g->mlx, "./tex/TLTile.xpm", &x, &y);
	g->tex.e.brside = mlx_xpm_file_to_image(g->mlx, "./tex/BRTile.xpm", &x, &y);
	g->tex.e.blside = mlx_xpm_file_to_image(g->mlx, "./tex/BLTile.xpm", &x, &y);
	g->tex.p.pleft = mlx_xpm_file_to_image(g->mlx, "./tex/PLeft0.xpm", &x, &y);
	g->tex.p.pright = mlx_xpm_file_to_image(g->mlx, "./tex/PRight0.xpm", &x, &y);
	g->tex.p.enemy = mlx_xpm_file_to_image(g->mlx, "./tex/Enemy.xpm", &x, &y);
	g->tex.w.back = mlx_xpm_file_to_image(g->mlx, "./tex/BackTile.xpm", &x, &y);
	g->tex.w.plat = mlx_xpm_file_to_image(g->mlx, "./tex/PlatformTile.xpm", &x, &y);
	g->tex.w.bend = mlx_xpm_file_to_image(g->mlx, "./tex/BadEnding.xpm", &x, &y);
	g->tex.w.gend = mlx_xpm_file_to_image(g->mlx, "./tex/HappyEnding.xpm", &x, &y);
	g->tex.s.dshad = mlx_xpm_file_to_image(g->mlx, "./tex/DownShadow.xpm", &x, &y);
	g->tex.s.lshad = mlx_xpm_file_to_image(g->mlx, "./tex/LeftShadow.xpm", &x, &y);
	g->tex.s.dlshad = mlx_xpm_file_to_image(g->mlx, "./tex/DLShadow.xpm", &x, &y);
	g->tex.s.cshad = mlx_xpm_file_to_image(g->mlx, "./tex/CornerShadow.xpm", &x, &y);
	get_cd_tex(g);
	check_textures(g, g->tex);
}

static void	draw_edge(t_map g, t_tex t, int x, int y)
{
	if (!x)
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.e.upside, y * 64, x * 64);
		if (!y)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.tlside, y * 64, x * 64);
		if (y == g.cols - 1)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.trside, y * 64, x * 64);
	}
	else if (!y)
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.e.rightside, y * 64, x * 64);
		if (x == g.rows - 1)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.blside, y * 64, x * 64);
	}
	else if (y == g.cols - 1)
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.e.leftside, y * 64, x * 64);
		if (x == g.rows - 1)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.brside, y * 64, x * 64);
	}
	else if (x == g.rows - 1)
		mlx_put_image_to_window(g.mlx, g.mw, t.e.downside, y * 64, x * 64);
}

static void	draw_shadow(t_map g, t_tex t, int i, int j)
{
	int	val;

	if (i && j < g.cols - 1 && g.map[i - 1][j + 1] == '1'
		&& g.map[i - 1][j] != '1' && g.map[i][j + 1] != '1')
		val = 4;
	else
		val = (i && g.map[i - 1][j] == '1') + 2
			* (j < g.cols - 1 && g.map[i][j + 1] == '1');
	if (val == 0)
		mlx_put_image_to_window(g.mlx, g.mw, t.w.back, j * 64, i * 64);
	if (val == 1)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.dshad, j * 64, i * 64);
	if (val == 2)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.lshad, j * 64, i * 64);
	if (val == 3)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.cshad, j * 64, i * 64);
	if (val == 4)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.dlshad, j * 64, i * 64);
}

static void	draw(t_map g, t_tex t, int i, int j)
{
	draw_shadow(g, t, i, j);
	if (g.map[i][j] == '1')
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.w.plat, j * 64, i * 64);
		draw_edge(g, t, i, j);
	}
	if (g.map[i][j] == 'E' || (g.map[i][j] == 'P' && g.on_end))
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.w.bend, j * 64, i * 64);
		if (!g.coins)
			mlx_put_image_to_window(g.mlx, g.mw, t.w.gend, j * 64, i * 64);
	}
	if (g.map[i][j] == 'P')
		mlx_put_image_to_window(g.mlx, g.mw, t.p.pleft, j * 64, i * 64);
	if (g.map[i][j] == 'X')
		mlx_put_image_to_window(g.mlx, g.mw, t.p.enemy, j * 64, i * 64);
	if (g.map[i][j] == 'C' && g.frame < 18 * g.speed)
		mlx_put_image_to_window(g.mlx, g.mw, t.w.cd[g.frame / g.speed], j * 64, i * 64);
	else if (g.map[i][j] == 'C')
		mlx_put_image_to_window(g.mlx, g.mw, t.w.cd[35 - (g.frame / g.speed)], j * 64, i * 64);
}

void	render_map(t_map g)
{
	int		i;
	int		j;
	char	*cn;

	i = -1;
	while (g.map[++i])
	{
		j = -1;
		while (g.map[i][++j])
			draw(g, g.tex, i, j);
	}
	mlx_string_put(g.mlx, g.mw, 20, 23, 0xff00, "Discs: ");
	cn = ft_itoa(g.coins);
	mlx_string_put(g.mlx, g.mw, 75, 23, 0xff00, cn);
	free(cn);
	mlx_string_put(g.mlx, g.mw, 20, 42, 0xff00, "Moves: ");
	cn = ft_itoa(g.mvs);
	mlx_string_put(g.mlx, g.mw, 75, 42, 0xff00, cn);
	free(cn);
}
