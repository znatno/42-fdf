#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h> // to delete
# define WIDTH 1440
# define HEIGHT 1024

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
    int 		color;
}               t_pt;

char	*file_to_line(char *name);
t_pt	**split_nbrs(char const *s, t_mlx *mlx);
//t_pt	**to_structs(int **map);
//int 	valid(char **map);
#endif