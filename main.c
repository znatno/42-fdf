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

#include <stdio.h> // to delete
#include "fdf.h"

/*
** 1. Read
** -
** 2. Valid
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
*/

/*int closee(void *param, int key)
{
	(void)param;
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

void	ft_fill(t_mlx *mlx)
{
	int i;
	int k;
	int x, y;

	i = 0;
	k = 0;
	while (i <= 500)
	{
		k = 0;
		while (k <= 500)
		{
			x = k;
			y = i;
			iso(&x, &y, 2);
			mlx_pixel_put(mlx->mlx, mlx->win, y, x, 0xff);
			k++;
		}
		i++;
	}
}*/

int main(int ac, char **av)
{
//    int		fd;
//    char	*line;
//
//    if (ac == 1)
//        fd = 0;
//    else if (ac == 2)
//        fd = open(av[1], O_RDONLY);
//    else
//        return (2);
//    if (get_next_line(fd, &line) == 1)
//    {
//
//    }
//    if (ac == 2)
//        close(fd);


	char *line;
	char **map;

	line = file_to_line(av[1]);
	//map = fill_map(line);
    printf("%s\n", line);
//    map = ft_strsplit(line, '\n');
    map = split_nbrs(line);

	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", map[i]);
	}

	/*t_mlx	mlx;

	mlx.mx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FdF");
	ft_fill(&mlx);
	mlx_hook(mlx.win, 2, 0, closee, NULL);
	mlx_loop(mlx.mlx);*/
	return (0);
}
