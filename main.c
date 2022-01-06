#include <mlx.h>
#define SIZE_MAX 1000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    double  re;
    double  im;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

t_complex   ft_complex_add(t_complex a, t_complex b)
{
    a.re += b.re;
    a.im += b.im;
    return (a);
}

t_complex   ft_complex_mul(t_complex a, t_complex b)
{
    t_complex res;
    res.re = (a.re * b.re) - (a.im * b.im);
    res.im = (a.re * b.im) + (a.im * b.re);
    return res;
}

int ft_fractal_julia_iter(t_complex x)
{
    t_complex   C;

    C.re = 0.2;
    C.im = -0.75;
    int iter_count = 0;
    while (iter_count < 100 && x.re * x.re + x.im * x.im <= 4)
    {
        x = ft_complex_add(ft_complex_mul(x, ft_complex_mul(x, x)), C);
        iter_count++;
    }
    return (iter_count);
}

int ft_get_color(int iter)
{
    return 100 * iter;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_MAX, SIZE_MAX, "fractol");
	img.img = mlx_new_image(mlx, SIZE_MAX, SIZE_MAX);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    
    for (int i = 0; i < SIZE_MAX; ++i)
    {
        for (int j = 0; j < SIZE_MAX; ++j)
        {
            t_complex   complex;
            complex.re = (double)(i - SIZE_MAX / 2) / 300;
            complex.im = (double)(j - SIZE_MAX / 2) / 300;
            int iter = ft_fractal_julia_iter(complex);
            int color = ft_get_color(iter);
            my_mlx_pixel_put(&img, i, j, color);
        }
    }
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}