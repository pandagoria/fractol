/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:44:21 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/22 03:00:26 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(t_data *data)
{
	int	n;

	n = 0;
	while (n < 100 && (data->z.re * data->z.re)
		+ (data->z.im * data->z.im) <= 4)
	{
		complex_sqr(&data->z);
		data->z.re += data->prm.re;
		data->z.im += data->prm.im;
		n++;
	}
	return (n);
}

int	mandelbrot_iter(t_data *data)
{
	int		n;

	n = 0;
	data->prm.re = data->z.re;
	data->prm.im = data->z.im;
	data->z.re = 0;
	data->z.im = 0;
	while (n < 100 && (data->z.re * data->z.re)
		+ (data->z.im * data->z.im) <= 4)
	{
		complex_sqr(&data->z);
		data->z.re += data->prm.re;
		data->z.im += data->prm.im;
		n++;
	}
	return (n);
}

int	newton_iter(t_data *data)
{
	int			n;
	t_complex	new_z;

	n = 0;
	new_z = data->z;
	while (n < 100 && check_roots(&new_z) == 1)
	{
		data->z = new_z;
		complex_mul(&new_z, &data->z);
		data->prm = new_z;
		complex_mul(&new_z, &data->z);
		new_z.re *= 2;
		new_z.im *= 2;
		new_z.re += 1;
		data->prm.re *= 3;
		data->prm.im *= 3;
		complex_div(&new_z, &data->prm);
		n++;
	}
	return (n);
}
