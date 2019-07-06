void 		line_old(int x0, int x1, int y0, int y1, t_mlx *mlx)
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