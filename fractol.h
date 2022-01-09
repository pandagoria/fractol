#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 1500
# define MOUSE_UP		4
# define MOUSE_DOWN		5
# define MAINP_ESC		53
# define MAINP_SPACE	49
# define ON_DESTROY		17
# define JULIA			1
# define MANDELBROT		2

# include <mlx.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_mlx {
	void    *mlx;
	void    *mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_mlx;

struct	s_data;

typedef int (*iter_func)(struct s_data *data);

typedef struct	s_data {
	int		fractal;
	int     n;
	int     color;
	double  re;
	double  im;
	double  re_prm;
	double  im_prm;
	int     scale;
	iter_func	func;
	t_mlx	mlx;
}   t_data;

int     ft_julia(char **argv);
void	complex_summ(t_data *a);
void	complex_sqrt(double *re, double *im);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
t_mlx   init_mlx(void);
int     get_color(int i);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int	    ft_isdigit(char c);
int     ft_mandelbrot(void);
int		zoom(int button, int x, int y, t_data *data);
void	render_fractol(t_data *data);
int		ft_julia_iter(t_data *data);
int		ft_mandelbrot_iter(t_data *data);

#endif