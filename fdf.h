#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# define WIDTH 1440
# define HEIGHT 1024
# define BUFF_SIZE 1000

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

char	*ft_rd(char *name);
#endif