#include "fractol.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	complex_cub(double *re, double *im)
{
	double	re_tmp;
	double	im_tmp;
	double	re_sqr;
	double	im_sqr;

	re_tmp = *re;
	im_tmp = *im;
	complex_sqrt(re, im);
	re_sqr = *re;
	im_sqr = *im;
	*re = (re_sqr * re_tmp) - (im_sqr * im_tmp);
	*im = (re_sqr * im_tmp) + (re_tmp * im_sqr);
}

/*void	complex_div(t_data *a)
{
	double	sqr;
	double	_re;
	double	_im;

	sqr = a->new_re * a->new_re + a->new_im * a->new_im;
	_re = (a->re * a->new_re + a->im * a->new_im) / sqr;
	_im = (a->im * a->new_re - a->re * a->new_im) / sqr;
	a->re = _re;
	a->im = _im;
}*/

void	complex_summ(t_data *a)
{
	a->re += a->re_prm;
	a->im += a->im_prm;
}

void	complex_sqrt(double *re, double *im)
{
	double	re_tmp;
	double	im_tmp;

	re_tmp = *re;
	im_tmp = *im;
	*re = (re_tmp * re_tmp) - (im_tmp * im_tmp);
	*im = (re_tmp * im_tmp) * 2;
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