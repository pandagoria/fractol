/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:44:42 by hlaunch           #+#    #+#             */
/*   Updated: 2022/01/14 08:35:24 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == MOUSE_UP)
	{
		data->scale *= 1.1;
		render_fractal(data);
	}
	else if (button == MOUSE_DOWN)
	{
		data->scale /= 1.1;
		render_fractal(data);
	}
	return (0);
}

int	close(t_data *data)
{
	if (!data)
		return (0);
	if (data->mlx.mlx)
	{
		if (data->mlx.img)
			mlx_destroy_image(data->mlx.mlx, data->mlx.img);
		if (data->mlx.mlx_win)
			mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	}
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (!data)
		return (0);
	if (keycode == SPACE)
	{
		if (data->color * 2 > 1000000)
			data->color = 1;
		data->color *= 2;
		render_fractal(data);
	}
	if (keycode == KEY_ESC)
	{
		if (data->mlx.img)
			mlx_destroy_image(data->mlx.mlx, data->mlx.img);
		if (data->mlx.mlx_win)
			mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		exit(0);
	}
	return (0);
}
