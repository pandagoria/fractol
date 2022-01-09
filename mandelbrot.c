#include "fractol.h"

int	ft_mandelbrot_iter(t_data *data)
{
	int		n;

	n = 0;
	data->re_prm = data->re;
	data->im_prm = data->im;
	data->re = 0;
	data->im = 0;
	while (n < 100 && (data->re * data->re) + (data->im * data->im) <= 4)
	{
		complex_sqrt(&data->re, &data->im);
		complex_summ(data);
		n++;
	}
	return (n);
}

int ft_mandelbrot(void)
{
	t_data  data;

	data.scale = 300;
	data.fractal = MANDELBROT;
	data.mlx = init_mlx();
	data.func = ft_mandelbrot_iter;
	render_fractol(&data);
	mlx_hook(data.mlx.mlx_win, MOUSE_UP, 0, zoom, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}