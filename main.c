/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:51:25 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/22 03:08:35 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			data->z.re = (double)(i - SIZE / 2) / data->scale;
			data->z.im = (double)(j - SIZE / 2) / data->scale;
			data->n = data->func(data);
			//data->color * get_color(data->n);
			data->n = (data->n)%10 * create_trgb((int)(sqrt(data->z.re * data->z.re + data->z.im * data->z.im) * 133) % 255, (int)(sqrt(data->z.re * data->z.re + data->z.im * data->z.im) * 1000) % 255, (int)(sqrt(data->z.re * data->z.re + data->z.im * data->z.im) * 2912) % 255);
			my_mlx_pixel_put(&data->mlx, i, j,
				data->n * data->color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.mlx_win, data->mlx.img, 0, 0);
}

int	create_fractal(t_data *data)
{
	data->scale = 300;
	data->mlx = init_mlx();
	data->color = 1;
	render_fractal(data);
	mlx_hook(data->mlx.mlx_win, KEY, 0, key_press, data);
	mlx_hook(data->mlx.mlx_win, ON_DESTROY, 0, close, data);
	mlx_hook(data->mlx.mlx_win, MOUSE_UP, 0, zoom, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

int	check_fractal(int argc, char **argv)
{
	
	t_data	data;

	if (ft_strncmp("julia", argv[1], 6) == 0)
	{
		data.func = julia_iter;
		if (argc != 4 || check_given_params(argv, &data) == -1)
			return (-1);
	}
	else if (ft_strncmp("mandelbrot", argv[1], 11) == 0 && argc == 2)
		data.func = mandelbrot_iter;
	else if (argc == 3 && ft_strncmp("newton", argv[1], 7) == 0
		&& ft_strncmp("pool", argv[2], 5) == 0)
		data.func = newton_iter;
	else
		return (-1);
	create_fractal(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || check_fractal(argc, argv) == -1)
	{
		printf("Incorrect input. ");
		printf("Write \"mandelbrot\" or \"julia prm1 prm2\" or \"newton pool\"\n");
	}
	return (0);
}
