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

#include "fdf.h"

char	*file_to_line(char *name)
{
	char	*res;
	char	buf[BUFF_SIZE];
	int		fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	else
		res = ft_strnew(1);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		res = ft_strjoin(res, buf);
		ft_bzero(buf, BUFF_SIZE);
	}
	close(fd);
	return (res);
}

static int	count_nbrs(char const *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s || !*s)
		return (0);
	/*if (ft_isdigit(s[0]))
		nb = 1;*/
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
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s || !*s)
		return (0);
	/*if (ft_isdigit(s[0]))
		nb = 1;*/
	while (s[i] != '\0')
	{
		if ((s[i] == '\n' && s[i + 1] != '\n'))
			nb++;
		i++;
	}
	return (nb);
}

static t_pt	**fill_arr(char const *s, t_pt **arr, int size_w, int size_h)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= size_w && *s != '\0')
	{
		while (*s == ' ')
			s++;
		if (*s == '\n' && (*(s + 1) == '\0' || *(s + 1) == '\n'))
			break ;
		if (*s == '\n')
		{
			i++;
			j = 0;
			if (count_nbrs(++s) != size_w || i > size_h)
				return (NULL);
		}
		while (!ft_isdigit(*s) && *s != '-' && *s != '\n' && *s != '\0')
			s++;
		arr[i][j].z = ft_atoi(s) *10;//* 20;
		arr[i][j].color = 0xFFFFFF;
		arr[i][j].x = (j - size_w / 2) * 10;
		arr[i][j].y = (i - size_h / 2) * 10;
		while (ft_isdigit(*s) || *s == '-')
			s++;

		j++;
	}
	return (arr);
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
	arr = (t_pt**)malloc(sizeof(t_pt*) * fdf->size_h);
	while (i < fdf->size_h)
	{
		arr[i] = (t_pt*)malloc(sizeof(t_pt) * fdf->size_w);
		i++;
	}
	if (!arr)
		return (NULL);
	return (fill_arr(s, arr, fdf->size_w, fdf->size_h));
}