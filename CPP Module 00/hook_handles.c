/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:13:19 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/06 20:42:47 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_handles.h"

static void	msg_prnt(int msg)
{
	if (msg == 0)
		write(1, "\n\n\n\n\n\n\n\n\nThanks for playing!\n", 30);
	if (msg == 1)
		write(2, "Failed to create mlx pointer.\n", 30);
	if (msg == 2)
		write(2, "Failed to create mlx window.\n", 29);
	if (msg == 3)
		write(2, "Failed to malloc for the map.\n", 30);
	if (msg == 4)
		write(2, "Failed to reach the ending.\n", 28);
	if (msg == 5)
		write(2, "Failed to collect all coins.\n", 29);
	if (msg == 6)
		write(1, "\n\n\n\n\n\n\n\n\nYou lose! Good day, sir!\n", 34);
	if (msg == 7)
		write(2, "Failed to malloc helper array.\n", 31);
	if (msg == 8)
		write(2, "Texture file missing or corrupted.\n", 35);
	if (msg == 9)
		write(2, "Map invalid due to characters\n", 30);
		
}

int	free_up(t_map *game, int msg, int ex)
{
	int		i;

	free_textures(*game);
	if (game->mlx && game->mw)
		mlx_destroy_window(game->mlx, game->mw);
	if (game->mlx)
		free(game->mlx);
	i = 0;
	while (game->map && game->map[i])
		free(game->map[i++]);
	if (game->map)
		free(game->map);
	msg_prnt(msg);
	exit (ex);
}

static int	move(t_map *g, int xm, int ym)
{
	if (g->px + xm > g->rows || g->px + xm < 0 || g->py + ym > g->cols
		|| g->py + ym < 0 || g->map[g->px + xm][g->py + ym] == '1')
		return (0);
	g->px += xm;
	g->py += ym;
	g->mvs++;
	write(1, "Moves: ", 7);
	ft_putnbr(g->mvs);
	write(1, "\n", 1);
	if (g->map[g->px][g->py] == 'X')
		free_up(g, 6, 0);
	if (g->map[g->px][g->py] == 'E' && !g->coins)
		free_up(g, 0, 0);
	if (g->map[g->px][g->py] == 'E')
		g->on_end = 1;
	if (g->map[g->px][g->py] == 'C')
		g->coins--;
	g->map[g->px - xm][g->py - ym] = '0';
	if (g->on_end && g->map[g->px][g->py] != 'E')
	{
		g->map[g->px - xm][g->py - ym] = 'E';
		g->on_end = 0;
	}
	g->map[g->px][g->py] = 'P';
	render_map(*g);
	return (0);
}

int	handle_keys(int keycode, t_map *g)
{
	int	xm;
	int	ym;

	xm = 0;
	ym = 0;
	if (keycode == 53)
		free_up(g, 0, 0);
	else if (keycode == 13 || keycode == 126)
		xm = -1;
	else if (keycode == 0 || keycode == 123)
		ym = -1;
	else if (keycode == 1 || keycode == 125)
		xm = 1;
	else if (keycode == 2 || keycode == 124)
		ym = 1;
	else
		return (0);
	return (move(g, xm, ym));
}

int	animations(t_map *game)
{
	game->frame = (game->frame + 1) % (36 * game->speed);
	render_map(*game);
	return (0);
}

int	expose_hook(t_map *game)
{
	render_map(*game);
	return (0);
}
