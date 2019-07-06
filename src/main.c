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

int 		binds_mlx(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	else if (key == 4)
		ft_putstr("Use \"-flat\" as 4th argument to flatten map\n");
	else
		ft_putstr("Press ESC to quit\n");
	return (0);
}

int 		cross_close(void *param)
{
	(void)param;
	exit(0);
}

int		to_exit(t_mlx *fdf)
{
	free_map(fdf);
	if (((fdf->size_h <= 1) || (fdf->size_w <= 1)) && fdf->flag_sizes == 1)
		ft_putstr("Error: invalid map\n");
	else if (errno == 2)
		ft_putstr("Usage: ./fdf <filename.fdf> [height] [scale] [-flat]\n");
	else if (errno == 1 || errno == 3 || errno == 13)
		ft_putstr("Error: invalid file\n");
	if (errno == 3 || errno == 2)
		exit(0);
	exit(0);
}

void	init_check(int ac, char **av, t_mlx *fdf)
{
	if (ac > 1 && ac < 6)
	{
		if (ac >= 3)
			fdf->height = ft_atoi(av[2]);
		else
			fdf->height = 3;
		if (ac >= 4)
			fdf->scale = ft_atoi(av[3]);
		else
			fdf->scale = 10;
	}
	else
		to_exit(fdf);
	if (!ft_strstr(av[1], ".fdf"))
		to_exit(fdf);
	if (!(fdf->map = split_nbrs(file_to_line(av[1]), fdf)))
		to_exit(fdf);
}

int main(int ac, char **av)
{
	t_mlx	fdf;

	init_check(ac, av, &fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	select_view(&fdf, ac, av);
	ft_fill(fdf, fdf.map);
	mlx_hook(fdf.win, 2, 0, binds_mlx, NULL);
	mlx_hook(fdf.win, 17, 0, cross_close, NULL);
	mlx_loop(fdf.mlx);
	free_map(&fdf);
	return (0);
}
