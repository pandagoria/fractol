#include "fractol.h"

int create_fractal(t_data *data)
{
	data->scale = 300;
	data->mlx = init_mlx();
	data->color = 1;
	render_fractol(data);
	mlx_hook(data->mlx.mlx_win, 2, 4, close_esc, data);
	mlx_hook(data->mlx.mlx_win, KEY_ESC, 0, close_esc, data);
    mlx_hook(data->mlx.mlx_win, ON_DESTROY, 0, close, data);
	mlx_hook(data->mlx.mlx_win, MOUSE_UP, 0, zoom, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

void	render_fractol(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			data->re = (double)(i - SIZE / 2) / data->scale;
			data->im = (double)(j - SIZE / 2) / data->scale;
			data->n = data->func(data);
			my_mlx_pixel_put(&data->mlx, i, j,
				data->color * get_color(data->n));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.mlx_win, data->mlx.img, 0, 0);
}

int	check_fractol(int argc, char **argv)
{
	t_data	data;

	if (ft_strncmp("julia", argv[1], 6) == 0)
	{
		data.fractal = JULIA;
		data.func = ft_julia_iter;
		if (check_given_params(argv, &data) == -1)
			return (-1);
		if (argc != 4 || create_fractal(&data) == -1)
			return (-1);
	}
	else if (ft_strncmp("mandelbrot", argv[1], 11) == 0 && argc == 2)
	{
		data.fractal = MANDELBROT;
		data.func = ft_mandelbrot_iter;
		create_fractal(&data);
	}
	else if (ft_strncmp("newton pool", argv[1], 12) == 0)
		ft_newton_pool();
	else
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || check_fractol(argc, argv) == -1)
		printf("Incorrect input. Write \"mandelbrot\" or \"julia {prm} {prm}\"\n");
	return (0);
}
