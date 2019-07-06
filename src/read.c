/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:02:27 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/25 15:02:55 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*file_to_line(char *name)
{
	int		fd;
	char	*file;
	char	*tmp;
	int		i;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	file = ft_strnew(1);
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		if (i < 0)
		{
			ft_memdel((void **)&file);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(file, buf);
		ft_memdel((void **)&file);
		file = tmp;
	}
	close(fd);
	return (file);
}

static int	count_nbrs(char const *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (ft_isdigit(s[i]) && !ft_isdigit(s[i + 1]) && s[i + 1] != '\0')
			nb++;
		i++;
	}
	return (nb);
}

static int	count_lns(char const *s)
{
	int	nb;
	int flag;

	flag = 0;
	nb = 0;
	if (!s || !*s)
		return (0);
	while (*s != '\0')
	{
		if ((*s == '\n' && *(s + 1) != '\n'))
		{
			nb++;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		s++;
	}
	if (!flag)
		nb++;
	return (nb);
}

void		init_arr(t_pt ***arr, int size_w, int size_h)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size_h)
	{
		while (j < size_w)
		{
			(*arr)[i][j].print = 0;
			j++;
		}
		i++;
	}
}

t_pt		**split_nbrs(char const *s, t_mlx *fdf)
{
	t_pt	**arr;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	fdf->size_w = count_nbrs(s);
	fdf->size_h = count_lns(s);
	fdf->flag_sizes = 1;
	if (fdf->size_w <= 1 || fdf->size_h <= 1)
		to_exit(fdf);
	arr = (t_pt**)malloc(sizeof(t_pt*) * fdf->size_h);
	while (i < fdf->size_h)
	{
		arr[i] = (t_pt*)malloc(sizeof(t_pt) * fdf->size_w);
		i++;
	}
	if (!arr)
		return (NULL);
	init_arr(&arr, fdf->size_w, fdf->size_h);
	return (fill_arr(s, arr, *fdf));
}
