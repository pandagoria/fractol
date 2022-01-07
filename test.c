#include "fractol.h"

double  parse_double(char *str)
{
	double  num;
	double  den;

	num = 0;
	while (*str != '.')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	str++;
	den = 10;
	while (*str != 0)
	{
		num += (double) ((*str - '0') / den);
		den *= 10;
		str++;
	}
	if (str[0] == '-')
		num *= -1;
	return (num);
}

void    init_mlx(t_mlx *data)
{
    data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, SIZE, SIZE, "fractol");
	data->img = mlx_new_image(data->mlx, SIZE, SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
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

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_color(int i)
{
	return (100 * i);
}

t_data	complex_summ(t_data a)
{
	a.re += a.re_prm;
	a.im += a.im_prm;
	return (a);
}

t_data	complex_multiply(t_data a, t_data b)
{
	t_data	temp;

	temp.re = (a.re * b.re) - (a.im * b.im);
	temp.im = (a.re * b.im) + (a.im * b.re);
	return (temp);
}

int	ft_julia_iter(t_data data)
{
	int	n;

	n = 0;
	while (n < 100 && (data.re * data.re) + (data.im * data.im) <= 4)
	{
		data = complex_summ(complex_multiply(data, data));
		n++;
	}
	return (n);
}

int ft_julia(int argc, char **argv)
{
	t_data  data;
	t_mlx	mlx;
	int		i;
	int		j;

	(void) argc;
	data.re_prm = parse_double(argv[2]);
	data.im_prm = parse_double(argv[3]);
	printf("1 %s %f 2 %s %f\n", argv[2], data.re_prm, argv[3], data.im_prm);
	init_mlx(&mlx);
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			data.re = (double) (i - SIZE / 2) / 300;
			data.im = (double) (i - SIZE / 2) / 300;
			data.i = ft_julia_iter(data);
			data.col = get_color(data.i);
			my_mlx_pixel_put(&mlx, i, j, data.col);
			j++;
		}
		i++;
	}
	//mlx_hook(data.mlx_win, 2, 1L<<0, close, &data);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

int    check_fractol(int argc, char  **argv)
{
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (argv[2] && argv[3])
			ft_julia(argc, argv);
	}
/*	else if (argv[1] == "mandelbrot")
		ft_fractal_mandelbrot();
	else
		{
			printf("only julia or mandelbrot");
			//d
			exit();
		}*/
	return (0);
}

int main(int argc, char **argv)
{
	check_fractol(argc, argv);
	return (0);
}