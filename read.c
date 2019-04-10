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
    ft_bzero(res, ft_strlen(res));
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

int			**split_nbrs(char const *s)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	size_w;
	size_t	size_h;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size_w = count_nbrs(s);
	size_h = count_lns(s);
	arr = (int**)malloc(size_w * size_h * sizeof(int*));
	if (!arr)
		return (NULL);
	while (i < size_w)
	{
		if (*s == '\n')
		{
			j++;
			i = 0;
			if (count_nbrs(s) != size_w)
				return (-1);
		}
		while (!ft_isdigit(*s))
			s++;
		arr[i][j] = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}