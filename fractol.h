/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:23:37 by hlaunch           #+#    #+#             */
/*   Updated: 2022/01/14 08:36:48 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 1500
# define MOUSE_UP	4
# define MOUSE_DOWN	5
# define KEY_ESC	53
# define SPACE	49
# define ON_DESTROY	17
# define KEY 2
# define JULIA	0
# define MANDELBROT	1
# define NEWTON 2

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

struct		s_data;
typedef int	(*t_iter_func)(struct s_data *data);

typedef struct s_data {
	int			fractal;
	int			n;
	int			color;
	int			scale;
	t_complex	z;
	t_complex	prm;
	t_iter_func	func;
	t_mlx		mlx;
}	t_data;

int		create_fractal(t_data *data);
int		get_color(int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(char c);
int		zoom(int button, int x, int y, t_data *data);
int		close(t_data *data);
int		key_press(int keycode, t_data *data);
int		julia_iter(t_data *data);
int		mandelbrot_iter(t_data *data);
int		check_given_params(char **argv, t_data *data);
int		newton_iter(t_data *data);
int		check_roots(t_complex *z);
t_mlx	init_mlx(void);
void	complex_summ(t_complex *first, t_complex *second);
void	complex_sqrt(t_complex *data);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	render_fractal(t_data *data);
void	complex_div(t_complex *first, t_complex *second);
void	complex_mul(t_complex *first, t_complex *second);

#endif