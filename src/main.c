/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:01:06 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/25 15:01:07 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** 1. Read +
** -
** 2. Valid +
** -
** 3. Align by figure center +
** 4. Align by screen center +
** 5. Isometric +
 * 6. Parallel/Conic
 * 7. fix reading all maps
** >>> bonus <<<
** 8. Gradient
** 9. Menu
** 10. Scaling
** 11. Moving
** 13. Rotating
** 14. Multimaps
 *
 *
 * НОВІ КРОКИ
 * 1. ф-ція для малювання лінії між 2 точками
 * 2. ф-ція для розміщення першої точки і всіх наступних так
 * 		щоб фігура була по центру
 * 3. ф-ція для перетворення координат кожної точки відносно її вистоти
 * 		щоб утворилось ізометричний вигляд фігури
 * 4. відмалювати лінії між точками в буфер
 * 5. вивести буфер
 *
*/

int binds_mlx(int key, void *param)
{
	(void)param;
	printf("KEY = %d\n", key);
	if (key == 53)
		exit(0);
	else if (key == 18) // ізометрія
	{
		printf("обама чмо\n");
	}
	else if (key == 19) // вигляд згори
	{
		printf("обама чмо\n");
	}
	else
		printf("There isn't such keybinding\n");
	return (0);
}

static void iso(t_pt *p)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = -p->z + (previous_x + previous_y) * sin(0.523599);
	p->x += WIDTH / 2;
	p->y += HEIGHT / 2;
}

void line (int x0, int x1, int y0, int y1, t_mlx *mlx)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x1 >= x0 ? 1 : -1;
	int sy = y1 >= y0 ? 1 : -1;
	int color = 0xFFFFFF;

	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, color);
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
		{
			if (d > 0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, color);
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
		{
			if ( d >0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		}
	}
}

void	ft_fill(t_mlx fdf, t_pt **arr)
{
	int i;
	int j;

	i = 0;
	while (i < fdf.size_h)
	{
		j = 0;
		while (j < fdf.size_w)
		{
			if (i < fdf.size_h - 1 && ((arr[i][j].print == 1) && (arr[i + 1][j].print == 1)))
				line(arr[i][j].x, arr[i + 1][j].x,
						arr[i][j].y, arr[i + 1][j].y, fdf.mlx);
			if (j < fdf.size_w - 1 && ((arr[i][j].print == 1) && (arr[i][j + 1].print == 1)))
				line(arr[i][j].x, arr[i][j + 1].x,
						arr[i][j].y, arr[i][j + 1].y, fdf.mlx);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_pt	**map;
	t_mlx	fdf;
	int		i;
	int 	j;

	i = 0;
	j = 0;
    if (!(map = split_nbrs(file_to_line(av[1]), &fdf)))
    	return (-1);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	while (i < fdf.size_h)
	{
		j = 0;
		while (j < fdf.size_w)
		{
			iso(&map[i][j]);
			j++;
		}
		i++;
	}
	ft_fill(fdf, map);
	mlx_hook(fdf.win, 2, 0, binds_mlx, NULL);
	mlx_loop(fdf.mlx);
	return (0);
}
