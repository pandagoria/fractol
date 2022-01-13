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
