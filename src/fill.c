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

void	free_map(t_mlx *fdf)
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

void	fill_pt(t_pt *arr, t_mlx fdf, int h)
{
	(*arr).z = (int)(h * fdf.height);
	(*arr).x = (fdf.j - (fdf.size_w / 2)) * fdf.scale;
	(*arr).y = (fdf.i - (fdf.size_h / 2)) * fdf.scale;
	(*arr).print = 1;
}

void	*find_and_skip(const char **s)
{
	while (ft_isdigit(**s) || **s == '-')
		(*s)++;
	if (**s == ',')
		while (**s != ' ' && **s != '\t' && **s != '\n' && **s != '\0')
			(*s)++;
}

t_pt	**fill_arr(char const *s, t_pt **arr, t_mlx fdf)
{
	fdf.i = 0;
	fdf.j = 0;
	while (fdf.j <= fdf.size_w && *s != '\0')
	{
		while (*s == ' ')
			s++;
		if (*s == '\n')
		{
			fdf.i++;
			if (fdf.i > fdf.size_h || (*(s + 1) == '\0' || *(s + 1) == '\n'))
				break ;
			fdf.j = 0;
			++s;
		}
		while (!ft_isdigit(*s) && *s != '-' && *s != '\n' && *s != '\0')
			s++;
		fill_pt(&arr[fdf.i][fdf.j], fdf, ft_atoi(s));
		find_and_skip(&s);
		fdf.j++;
	}
	return (arr);
}
