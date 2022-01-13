#include "fractol.h"

int	zoom(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == MOUSE_UP)
	{
		data->scale *= 1.1;
		render_fractol(data);
	}
	else if (button == MOUSE_DOWN)
	{
		data->scale /= 1.1;
		render_fractol(data);
	}
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int i)
{
	if (i >= 100)
		return (0);
	else
		return (create_trgb(0, 218, 112, 214) * i);
}

t_mlx    init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, SIZE, SIZE, "fractol");
	mlx.img = mlx_new_image(mlx.mlx, SIZE, SIZE);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	return (mlx);
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

int	close_esc(int keycode, t_data *data)
{
	if (!data)
		return (0);
	if (keycode == SPACE)
	{
		if (data->color * 2 > 1000000)
			data->color = 1;
		data->color *= 2;
		render_fractol(data);
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