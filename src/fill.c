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

t_pt	**fill_arr(char const *s, t_pt **arr, int size_w, int size_h, t_mlx fdf)
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
			if (i > size_h)
				break ;
			j = 0;
			++s;
		}
		while (!ft_isdigit(*s) && *s != '-' && *s != '\n' && *s != '\0')
			s++;
		arr[i][j].z = (int)(ft_atoi(s) * fdf.height); // height;
		arr[i][j].x = (j - (size_w / 2)) * fdf.scale; // x axis
		arr[i][j].y = (i - (size_h / 2)) * fdf.scale; // y axis
		arr[i][j].print = 1;
		while (ft_isdigit(*s) || *s == '-')
			s++;
		if (*s == ',')
			while (*s != ' ' && *s != '\t' && *s != '\n' && *s != '\0')
				s++;
		j++;
	}
	return (arr);
}

