/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:50:14 by ibohun            #+#    #+#             */
/*   Updated: 2019/07/07 14:50:16 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_h(t_mlx *mlx, t_draw l, t_pt p1, int color)
{
	int x;
	int y;
	int i;

	l.d = (l.dy << 1) - l.dx;
	l.d1 = l.dy << 1;
	l.d2 = (l.dy - l.dx) << 1;
	mlx_pixel_put(mlx->mlx, mlx->win, p1.x, p1.y, color);
	x = p1.x + l.sx;
	y = p1.y;
	i = 1;
	while (i <= l.dx)
	{
		if (l.d > 0)
		{
			l.d += l.d2;
			y += l.sy;
		}
		else
			l.d += l.d1;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		i++;
		x += l.sx;
	}
}

void	draw_v(t_mlx *mlx, t_draw l, t_pt p1, int color)
{
	int x;
	int y;
	int i;

	l.d = (l.dx << 1) - l.dy;
	l.d1 = l.dx << 1;
	l.d2 = (l.dx - l.dy) << 1;
	mlx_pixel_put(mlx->mlx, mlx->win, p1.x, p1.y, color);
	y = p1.y + l.sy;
	x = p1.x;
	i = 1;
	while (i <= l.dy)
	{
		if (l.d > 0)
		{
			l.d += l.d2;
			x += l.sx;
		}
		else
			l.d += l.d1;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		i++;
		y += l.sy;
	}
}

void	line(t_pt p1, t_pt p2, t_mlx *mlx, int color)
{
	t_draw	l;

	l.dx = abs(p2.x - p1.x);
	l.dy = abs(p2.y - p1.y);
	l.sx = p2.x >= p1.x ? 1 : -1;
	l.sy = p2.y >= p1.y ? 1 : -1;
	if (l.dy <= l.dx)
		draw_h(mlx, l, p1, color);
	else
		draw_v(mlx, l, p1, color);
}
