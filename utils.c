/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:48:23 by hlaunch           #+#    #+#             */
/*   Updated: 2022/01/14 08:40:41 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	parse_double_bd(char *str, double *num)
{
	if (!*str)
		return (-1);
	*num = 0;
	if (*str == '-')
		str++;
	while (*str != '.' && *str != 0 && ft_isdigit(*str))
	{
		*num *= 10;
		*num += *str++ - '0';
	}
	if (!ft_isdigit(*str) && *str != 0 && *str != '.')
		return (-1);
	return (0);
}

int	parse_double_ad(char *str, double *num)
{
	int	sign;
	int	den;

	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '.' && *str != 0)
		str++;
	den = 10;
	if (*str == '.' && *(str + 1))
	{
		str++;
		while (ft_isdigit(*str))
		{
			*num += ((double)(*str++ - '0') / den) * sign;
			den *= 10;
		}
	}
	if (*str)
		return (-1);
	return (0);
}

int	check_given_params(char **argv, t_data *data)
{
	if (parse_double_bd(argv[2], &data->prm.re) == -1
		|| parse_double_bd(argv[3], &data->prm.im) == -1)
		return (-1);
	if (parse_double_ad(argv[2], &data->prm.re) == -1
		|| parse_double_ad(argv[3], &data->prm.im) == -1)
		return (-1);
	return (0);
}
