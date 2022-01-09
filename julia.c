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
		// complex_sqrt(&data->re, &data->im);
		// complex_summ(data);
		
		// data->re = sin(data->re);
		// data->im = sin(data->im);
		// complex_sqrt(&data->re, &data->im);
		// data->re += data->re_prm;
		// data->im += data->im_prm; -1 0
		n++;
	}
	return (n);
}

int ft_julia(char **argv)
{
	t_data  data;

	if (check_given_params(argv, &data) == -1)
		return (-1);
	data.scale = 300;
	data.fractal = JULIA;
	data.mlx = init_mlx();
	data.func = ft_julia_iter;
	render_fractol(&data);
    //mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_hook(data.mlx.mlx_win, MOUSE_UP, 0, zoom, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}