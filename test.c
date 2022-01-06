#include "fractol.h"

double  parse_double(char *str)
{
	double  num;
	double  den;

	num = 0;
	while (*str++ != '.')
	{
		num *= 10;
		num += (*str - '0');
		num /= 10;
	}
	str++;
	den = 10;
	while (*str++)
	{
		num += (double) ((*str - '0') / den);
		den *= 10;
	}
	return (num);
}

void    init_mlx(t_data *data)
{
    data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, SIZE, SIZE, "fractol");
	data->img = mlx_new_image(data->mlx, SIZE, SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
}

int ft_julia(int argc, char **argv)
{
	t_data  data;
	int     i;
	int     j;

	data.re_c = parse_double(argv[2]);
	data.im_c = parse_double(argv[3]);
	init_struct(&data);
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			data.re = (double) (i - SIZE / 2) + 300;
			data.im = (double) (i - SIZE / 2) + 300;
			data.i = ft_julia_iter(data);
			data.color = get_color(data.i);
			my_mlx_pixel_put(&data.img, i, j, data.color);
			j++;
		}
		i++;
	}
	// mlx_hook(data.mlx_win, 2, 1L<<0, close, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

int    check_fractol(int argc, char  **argv)
{
	if (argv[1] == "julia")
	{
		if (argv[2] && argv[3])
			ft_julia();
	}
	else if (atgv[1] == "mandelbrot")
		ft_fractal_mandelbrot();
	else
		{
			printf("only julia or mandelbrot");
			//d
			exit();
		}
}

int main(int argc, char **argv)
{
	t_data  data;

	check_fractol(argc, argv);
}