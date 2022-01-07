#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 1000
# include <mlx.h>
# include <stdio.h>

typedef struct	s_data {
    int     i;
    int     col;
    double  re;
    double  im;
    double  re_prm;
    double  im_prm;
}				t_data;

typedef struct	s_mlx {
    void    *mlx;
    void    *mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_mlx;

#endif