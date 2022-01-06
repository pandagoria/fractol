#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 1000
# include <mlx.h>
# include <stdio.h>

typedef struct	s_data {
    void    *mlx;
    void    *mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     i;
    int     col;
    double  re;
    double  im;
    double  re_c;
    double  im_c;
}				t_data;

#endif