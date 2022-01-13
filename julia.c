#include "fractol.h"

double  parse_double(char *str)
{
	double	num;
	double	den;
	double	sign;

	sign = 1;
	num  = 0;
	if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	while (*str != '.' && *str != 0)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	den = 10;
	if (*str == '.')
	{
		str++;
		while (*str != 0)
		{
			num += (double) ((*str - '0') / den);
			den *= 10;
			str++;
		}
	}
	return (sign * num);
}

int	check_given_params(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[2][i])
	{
		if (!ft_isdigit(argv[2][i]) && argv[2][i] != '.' && argv[2][i] != '-')
			return (-1);
		i++;
	}
	i = 0;
	while (argv[3][i])
	{
		if (!ft_isdigit(argv[3][i]) && argv[3][i] != '.' && argv[3][i] != '-')
			return (-1);
		i++;
	}
	data->re_prm = parse_double(argv[2]);
	data->im_prm = parse_double(argv[3]);
	return (0);
}

int	ft_julia_iter(t_data *data)
{
	int	n;

	n = 0;
	while (n < 100 && (data->re * data->re) + (data->im * data->im) <= 4)
	{
		complex_sqrt(&data->re, &data->im);
		complex_summ(data);
		n++;
	}
	return (n);
}