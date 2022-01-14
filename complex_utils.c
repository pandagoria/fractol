/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:38:33 by hlaunch           #+#    #+#             */
/*   Updated: 2022/01/14 03:58:21 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_sqrt(t_complex *data)
{
	double	re_tmp;
	double	im_tmp;

	re_tmp = data->re;
	im_tmp = data->im;
	data->re = (re_tmp * re_tmp) - (im_tmp * im_tmp);
	data->im = (re_tmp * im_tmp) * 2;
}

void	complex_summ(t_complex *first, t_complex *second)
{
	first->re += second->re;
	first->im += second->im;
}

void	complex_mul(t_complex *first, t_complex *second)
{
	t_complex	res;

	res.re = first->re * second->re - first->im * second->im;
	res.im = first->re * second->im + second->re * first->im;
	*first = res;
}

void	complex_div(t_complex *first, t_complex *second)
{
	t_complex	res;
	double		sqr;

	sqr = second->re * second->re + second->im * second->im;
	res.re = (first->re * second->re + first->im * second->im) / sqr;
	res.im = (first->im * second->re - first->re * second->im) / sqr;
	*first = res;
}

int	check_roots(t_complex *z)
{
	if ((z->re + 0.500000) * (z->re + 0.500000)
		+ (z->im + 0.866025) * (z->im + 0.866025) < 0.00001)
		return (-1);
	if (((z->re - 1) * (z->re - 1) + z->im * z->im) < 0.00001)
		return (-1);
	if (((z->re + 0.500000) * (z->re + 0.500000)
			+ (z->im - 0.866025) * (z->im - 0.866025)) < 0.00001)
		return (-1);
	return (1);
}
