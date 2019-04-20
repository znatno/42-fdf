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

#include "fdf.h"

/*
** 1. Read +
** -
** 2. Valid +
** -
** 3. Align by figure center
** 4. Align by screen center
** 5. Isometric
** >>> bonus <<<
** 6. Gradient
** 7. Menu
** 8. Scaling
** 9. Moving
** 10. Rotating
** 11. Multimaps
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

int close_mlx(int key, void *param)
{
	(void)param;
	printf("KEY = %d\n", key);
	if (key == 53)
		exit(0);
	else
		printf("There isn't such keybinding\n");
	return (0);
}

static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void line (int x0, int x1, int y0, int y1, t_mlx *mlx)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = (dy << 1) - dx;
	int d1 = dy << 1;
	int d2 = (dy - dx) << 1;
	int color = 0xFFFFFF;

	mlx_pixel_put(mlx->mlx, mlx->win,x0, y0, color);
	for (int x = x0 + 1, y = y0; x <= x1; x++)
	{
		if ( d >0)
		{
			d += d2;
			y += 1;
		}
		else
			d += d1;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
	}
}

void	ft_fill(t_mlx *fdf, t_pt ***arr)
{
	int i;
	int k;
	int x = 0, y = 0;

	i = 0;
	while (i < 1024)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xff);
		x++;
		i++;
		y++;
	}
	y = 0;
	while (i > 0)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xff);
		x--;
		i--;
		y++;
	}
}

int main(int ac, char **av)
{
	t_pt	**map;
	char 	*c_nb;
	t_pt	**arr;
	t_mlx	fdf;

    if (!(map = split_nbrs(file_to_line(av[1]), &fdf)))
    	return (-1); /* не валідна */
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	ft_fill(&fdf, &arr);
	mlx_hook(fdf.win, 2, 0, close_mlx, NULL);
	mlx_loop(fdf.mlx);
	return (0);
}
