#include "fractol.h"

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
			data->color = get_color(data->n);
			my_mlx_pixel_put(&data->mlx, i, j, data->color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
}

int    check_fractol(int argc, char  **argv)
{
	if (ft_strncmp("julia", argv[1], 6) == 0)
	{
		if (argc != 4 || ft_julia(argv) == -1)
			return (-1);
	}
	else if (ft_strncmp("mandelbrot", argv[1], 11) == 0 && argc == 2)
		ft_mandelbrot();
	else
		return (-1);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2 || check_fractol(argc, argv) == -1)
		printf("Incorrect input. Write \"mandelbrot\" or \"julia {prm} {prm}\"\n");
	return (0);
}