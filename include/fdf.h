#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h> // to delete
# define WIDTH 2000
# define HEIGHT 1280

typedef struct  s_pt
{
	int 		x;
	int 		y;
	int         z;
	int 		print;
}               t_pt;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			size_w;
	int 		size_h;
	t_pt		**map;
	int			height;
	int 		scale;

}				t_mlx;

char	*file_to_line(char *name);
t_pt	**split_nbrs(char const *s, t_mlx *mlx);
t_pt	**fill_arr(char const *s, t_pt **arr, int size_w, int size_h, t_mlx fdf);
void	select_view(t_mlx fdf, int mode);
void	ft_fill(t_mlx fdf, t_pt **arr);
void	free_map(t_mlx *fdf);
#endif