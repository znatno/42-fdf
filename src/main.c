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

int 		binds_mlx(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	else
		write(1, "There isn't such keybinding\n", 28);
	return (0);
}

int 		cross_close(void *param)
{
	(void)param;
	exit(0);
}

int		to_exit(void)
{
	//printf("err: %d\n", errno);
	if (errno == 2)
		ft_putstr("Usage: ./fdf <filename.fdf> [height scale -flat]\n");
	else if (errno == 1 || errno == 3 || errno == 13)
		ft_putstr("Error: invalid file\n");
	if (errno == 3 || errno == 2)
		exit(0);
	exit(0);
}

int main(int ac, char **av)
{

	t_mlx	fdf;

	if (ac > 1 && ac < 6)
	{
		if (ac >= 3)
			fdf.height = ft_atoi(av[2]);
		else
			fdf.height = 3;
		if (ac >= 4)
			fdf.scale = ft_atoi(av[3]);
		else
			fdf.scale = 10;
		//printf("z: %d\n", fdf.height);
		//printf("x: %d\n", fdf.scale);
	}
	else
		to_exit();
	if (!ft_strstr(av[1], ".fdf"))
		to_exit();
    if (!(fdf.map = split_nbrs(file_to_line(av[1]), &fdf)))
		to_exit();
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	if (ac == 5 && ft_strequ(av[4], "-flat"))
		select_view(fdf, 0);
	else
		select_view(fdf, 1);
	ft_fill(fdf, fdf.map);
	mlx_hook(fdf.win, 2, 0, binds_mlx, NULL);
	mlx_hook(fdf.win, 17, 0, cross_close, NULL);
	mlx_loop(fdf.mlx);
	return (0);
}
