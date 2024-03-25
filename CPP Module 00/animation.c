/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:42:56 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/06 20:51:03 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

void	get_cd_tex(t_map *g)
{
	int		i;
	int		x;
	int		y;
	char	*tmp;
	char	*cdn;

	i = 0;
	while (i < 18)
	{
		cdn = ft_itoa(i);
		tmp = ft_strjoin("./tex/CD", cdn);
		if (cdn)
			free(cdn);
		cdn = ft_strjoin(tmp, ".xpm");
		if (tmp)
			free(tmp);
		if (!cdn)
			g->tex.w.cd[i] = cdn;
		else
			g->tex.w.cd[i] = mlx_xpm_file_to_image(g->mlx, cdn, &x, &y);
		if (cdn)
			free(cdn);
		i++;
	}
}

void	check_textures(t_map g, t_tex t)
{
	int	i;

	if (!t.e.upside || !t.e.leftside || !t.e.rightside || !t.e.downside
		|| !t.e.trside || !t.e.tlside || !t.e.brside || !t.e.blside || !t.p.enemy
		|| !t.p.pleft || !t.p.pright || !t.w.back || !t.w.plat || !t.w.gend
		|| !t.s.dshad || !t.s.lshad || !t.s.dlshad || !t.s.cshad || !t.w.bend)
		free_up(&g, 8, 127);
	i = 0;
	while (i < 18)
	{
		if (!t.w.cd[i])
			free_up(&g, 8, 127);
		i++;	
	}
}

void	free_tex_2(t_map g)
{
	int	i;

	if (g.tex.s.cshad)
		mlx_destroy_image(g.mlx, g.tex.s.cshad);
	if (g.tex.s.lshad)
		mlx_destroy_image(g.mlx, g.tex.s.lshad);
	if (g.tex.s.dlshad)
		mlx_destroy_image(g.mlx, g.tex.s.dlshad);
	if (g.tex.s.dshad)
		mlx_destroy_image(g.mlx, g.tex.s.dshad);
	if (g.tex.w.back)
		mlx_destroy_image(g.mlx, g.tex.w.back);
	if (g.tex.w.gend)
		mlx_destroy_image(g.mlx, g.tex.w.gend);
	if (g.tex.w.bend)
		mlx_destroy_image(g.mlx, g.tex.w.bend);
	if (g.tex.w.plat)
		mlx_destroy_image(g.mlx, g.tex.w.plat);
	i = 0;
	while (i < 18)
	{
		if (g.tex.w.cd[i])
			mlx_destroy_image(g.mlx, g.tex.w.cd[i++]);
	}
}

void	free_textures(t_map g)
{
	if (g.tex.e.leftside)
		mlx_destroy_image(g.mlx, g.tex.e.leftside);
	if (g.tex.e.upside)
		mlx_destroy_image(g.mlx, g.tex.e.upside);
	if (g.tex.e.rightside)
		mlx_destroy_image(g.mlx, g.tex.e.rightside);
	if (g.tex.e.downside)
		mlx_destroy_image(g.mlx, g.tex.e.downside);
	if (g.tex.e.blside)
		mlx_destroy_image(g.mlx, g.tex.e.blside);
	if (g.tex.e.brside)
		mlx_destroy_image(g.mlx, g.tex.e.brside);
	if (g.tex.e.tlside)
		mlx_destroy_image(g.mlx, g.tex.e.tlside);
	if (g.tex.e.trside)
		mlx_destroy_image(g.mlx, g.tex.e.trside);
	if (g.tex.p.pleft)
		mlx_destroy_image(g.mlx, g.tex.p.pleft);
	if (g.tex.p.pright)
		mlx_destroy_image(g.mlx, g.tex.p.pright);
	if (g.tex.p.enemy)
		mlx_destroy_image(g.mlx, g.tex.p.enemy);
	free_tex_2(g);
}


