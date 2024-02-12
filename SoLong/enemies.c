#include "structs.h"
#include <stdlib.h>
#include <time.h>

static int	enemy_count(t_map g)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (i < g.rows)
	{
		j = 0;
		while (j < g.cols)
		{
			c += (g.map[i][j] == 'C' || g.map[i][j] == '0');
			j++;
		}
		i++;
	}
	return (c / 20);
}

static void	generate(t_map g, int *x, int *y)
{
	int	tmp;
	int	done;
	int	loops;

	done = 0;
	loops = 0;
	*x = rand() % (g.rows - 2) + 1;
	while (!done && loops < g.rows - 2)
	{
		*y = rand() % (g.cols - 2) + 1;
		tmp = 0;
		while (!done && tmp++ < g.cols - 2)
		{
			done += (g.map[*x][*y] == 'C' || g.map[*x][*y] == '0');
			if (!done)
				*y = (*y + 1) % (g.cols - 2) + 1;
		}
		if (!done)
			(*x)++;
		loops++;
	}
}

void	place_enemies(t_map *g)
{
	int	i;

	srand(time(NULL));
	g->enemy_cnt = enemy_count(*g);
	g->enemies = malloc(g->enemy_cnt * sizeof(t_enemy));
	if (!g->enemies)
	{
		g->enemy_cnt = 0;
		return ;
	}
	i = 0;
	while (i++ < g->enemy_cnt)
	{
		g->enemies[i].direction = rand() % 4;
		generate(*g, &g->enemies[i].x, &g->enemies[i].y);
	}
}