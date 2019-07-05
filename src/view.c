#include "../include/fdf.h"

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

static void flat(t_pt *p)
{
	p->x += WIDTH / 2;
	p->y += HEIGHT / 2;
}

void	select_view(t_mlx fdf, int mode)
{
	int i;
	int j;

	i = 0;
	while (i < fdf.size_h)
	{
		j = 0;
		while (j < fdf.size_w)
		{
			if (mode)
				iso(&(fdf.map)[i][j]);
			else
				flat(&(fdf.map)[i][j]);
			j++;
		}
		i++;
	}
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