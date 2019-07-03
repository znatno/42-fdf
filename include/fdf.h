#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h> // to delete
# define WIDTH 2000
# define HEIGHT 1280

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			size_w;
	int 		size_h;

}				t_mlx;

typedef struct  s_pt
{
	int 		x;
	int 		y;
    int         z;
    int 		print;
}               t_pt;

char	*file_to_line(char *name);
t_pt	**split_nbrs(char const *s, t_mlx *mlx);
t_pt	**fill_arr(char const *s, t_pt **arr, int size_w, int size_h);
#endif