/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:34:45 by ibohun            #+#    #+#             */
/*   Updated: 2019/07/06 22:34:49 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_map(t_mlx *fdf)
{
	int i;

	i = 0;
	if (fdf->map)
	{
		while (i < fdf->size_h)
		{
			free(fdf->map[i]);
			i++;
		}
	}
}

void	fill_pt(t_pt *arr, t_mlx fdf, int h, int i, int j)
{
	(*arr).z = (int)(h * fdf.height);
	(*arr).x = (j - (fdf.size_w / 2)) * fdf.scale;
	(*arr).y = (i - (fdf.size_h / 2)) * fdf.scale;
	(*arr).print = 1;
}

t_pt	**fill_arr(char const *s, t_pt **arr, t_mlx fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= fdf.size_w && *s != '\0')
	{
		while (*s == ' ')
			s++;
		if (*s == '\n')
		{
			i++;
			if (i > fdf.size_h || (*(s + 1) == '\0' || *(s + 1) == '\n'))
				break ;
			j = 0;
			++s;
		}
		while (!ft_isdigit(*s) && *s != '-' && *s != '\n' && *s != '\0')
			s++;
//		arr[i][j].z = (int)(ft_atoi(s) * fdf.height);
//		arr[i][j].x = (j - (fdf.size_w / 2)) * fdf.scale;
//		arr[i][j].y = (i - (fdf.size_h / 2)) * fdf.scale;
//		arr[i][j].print = 1;
		fill_pt(&arr[i][j], fdf, ft_atoi(s), i, j);
		while (ft_isdigit(*s) || *s == '-')
			s++;
		if (*s == ',')
			while (*s != ' ' && *s != '\t' && *s != '\n' && *s != '\0')
				s++;
		j++;
	}
	return (arr);
}
