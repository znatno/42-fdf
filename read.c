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
	if (ft_isdigit(s[0]))
		nb = 1;
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
	if (ft_isdigit(s[0]))
		nb = 1;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

static int	**fill_arr(char const *s, int **arr, int size_w, int size_h)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size_w && *s != '\0')
	{
		if (*s == '\n' && *(s + 1) == '\0')
			break ;
		if (*s == '\n')
		{
			i++;
			j = 0;
			if (count_nbrs(++s) != size_w)
				return (NULL);
		}
		while (!ft_isdigit(*s))
			s++;
		arr[i][j] = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
		j++;
	}
	return (arr);
}

int			**split_nbrs(char const *s)
{
	int	**arr;
	int	i;
	int	size_w;
	int size_h;

	i = 0;
	if (!s)
		return (NULL);
	size_w = count_nbrs(s);
	size_h = count_lns(s);
	arr = (int**)malloc(sizeof(int*) * size_h);
	while (i < size_h)
	{
		arr[i] = (int*)malloc(sizeof(int) * size_w);
		i++;
	}
	if (!arr)
		return (NULL);
	return (fill_arr(s, arr, size_w, size_h));
}