/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:33:45 by ibohun            #+#    #+#             */
/*   Updated: 2019/07/06 22:33:47 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# define WIDTH 2000
# define HEIGHT 1280

typedef struct	s_pt
{
	int x;
	int y;
	int z;
	int print;
}				t_pt;

typedef struct	s_draw
{
	int	dx;
	int dy;
	int sx;
	int sy;
	int d;
	int d1;
	int d2;

}				t_draw;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		size_w;
	int		size_h;
	int		flag_sizes;
	t_pt	**map;
	int		height;
	int		scale;
	int		color;
	int		i;
	int		j;
}				t_mlx;

char			*file_to_line(char *name);
t_pt			**split_nbrs(char const *s, t_mlx *mlx);
t_pt			**fill_arr(char const *s, t_pt **arr, t_mlx fdf);
void			select_view(t_mlx *fdf, int ac, char **av);
void			ft_fill(t_mlx fdf, t_pt **arr);
void			free_map(t_mlx *fdf);
int				to_exit(t_mlx *fdf);
void			line(t_pt p1, t_pt p2, t_mlx *mlx, int color);
#endif
