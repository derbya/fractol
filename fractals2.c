/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:44:00 by aderby            #+#    #+#             */
/*   Updated: 2017/08/07 03:50:14 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

void	julia(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			nr = 1.5 * (x - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->movex;
			ni = 1.5 * (y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) - f->movey;
			pixel_to_image(f->img, x, y, f->color[fractal_loop(nr, ni, f)]);
		}
	}
}

void	juliav3(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			nr = 1.5 * (x - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->movex;
			ni = 1.5 * (y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) - f->movey;
			pixel_to_image(f->img, x, y, f->color[w_fractal_loop(nr, ni, f)]);
		}
	}
}

void	juliav2(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			nr = 1.5 * (x - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->movex;
			ni = 1.5 * (y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) - f->movey;
			pixel_to_image(f->img, x, y, f->color[l_fractal_loop(nr, ni, f)]);
		}
	}
}

void	mandelbrot(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			f->c_re = (X_COMPLEX(x)) + f->movex;
			f->c_im = (Y_COMPLEX(y)) - f->movey;
			nr = 0.0;
			ni = 0.0;
			pixel_to_image(f->img, x, y, f->color[fractal_loop(nr, ni, f)]);
		}
	}
}

void	circles(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			nr = 1.5 * (x - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->movex;
			ni = 1.5 * (y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) - f->movey;
			pixel_to_image(f->img, x, y, f->color[NORMSUCKS]);
		}
	}
}
