/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:34:59 by ibohun            #+#    #+#             */
/*   Updated: 2019/07/06 22:35:00 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	iso(t_pt *p)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (int)((previous_x - previous_y) * cos(0.523599));
	p->y = (int)(-p->z + (previous_x + previous_y) * sin(0.523599));
	p->x += WIDTH / 2;
	p->y += HEIGHT / 2;
}

static void	flat(t_pt *p)
{
	p->x += WIDTH / 2;
	p->y += HEIGHT / 2;
}

void		select_view(t_mlx *fdf, int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->size_h)
	{
		j = 0;
		while (j < fdf->size_w)
		{
			if (ac == 6 && ft_strequ(av[5], "-flat"))
				flat(&(fdf->map)[i][j]);
			else
				iso(&(fdf->map)[i][j]);
			j++;
		}
		i++;
	}
}
