#include "fractol.h"

typedef struct s_complex
{
	double re;
	double im;
}	t_complex;

void	ft_complex_add(t_complex *first, t_complex *second)
{
	first->re += second->re;
	first->im += second->im;
}

void	ft_complex_mul(t_complex *first, t_complex *second)
{
	t_complex	res;

	res.re = first->re * second->re - first->im * second->im;
	res.im = first->re * second->im + second->re * first->im;
	*first = res;
}

void	ft_complex_div(t_complex *first, t_complex *second)
{
	t_complex	res;
	double		sqr;

	sqr = second->re * second->re + second->im * second->im;
	res.re = (first->re * second->re + first->im * second->im) / sqr;
	res.im = (first->im * second->re - first->re * second->im)  / sqr;
	*first = res;
}

int flag = 100;
int	ft_newton_iter(t_data *data)
{
	int			n;
	t_complex	z;
	t_complex	z0;
	t_complex	div;
	double		abs1 = 1;
	double		abs2 = 1;
	double		abs3 = 1;

	n = 0;
	z0.re = data->re;
	z0.im = data->im;
	z = z0;
	while (n < 100 && (abs1 > 0.001) && (abs2 > 0.001) && (abs3 > 0.001))
	{
		z0 = z;
		ft_complex_mul(&z, &z0);
		div = z;
		ft_complex_mul(&z, &z0);
		z.re *= 2;
		z.im *= 2;
		z.re += 1;
		div.re *= 3;
		div.im *= 3;
		ft_complex_div(&z, &div);
		abs2 = (z.re + 0.500000)*(z.re + 0.500000) + (z.im + 0.866025)*(z.im + 0.866025); // -0.5 -0.866025
		abs1 = (z.re - 1) * (z.re - 1) + z.im * z.im; // 1 0
		abs3 = (z.re + 0.500000)*(z.re + 0.500000) + (z.im - 0.866025)*(z.im - 0.866025); // -0.5 0.866025
		n++;
	}
	return (n);
}

// z = (2z^3 + 1) / 3z^2

// z = z - (z^3 - 1)/(3z^2)

int	ft_newton_pool(void)
{
	t_data  data;

	data.scale = 300;
	data.fractal = 2;
	data.mlx = init_mlx();
	data.func = ft_newton_iter;
	data.color = 1;
	render_fractol(&data);
	mlx_hook(data.mlx.mlx_win, 2, 4, close_esc, &data);
	mlx_hook(data.mlx.mlx_win, KEY_ESC, 0, close_esc, &data);
    mlx_hook(data.mlx.mlx_win, ON_DESTROY, 0, close, &data);
	mlx_hook(data.mlx.mlx_win, MOUSE_UP, 0, zoom, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}