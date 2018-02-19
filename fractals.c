/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:44:00 by aderby            #+#    #+#             */
/*   Updated: 2017/08/07 01:38:39 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

void	ship(t_frac *f, int x, int y)
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
			pixel_to_image(f->img, x, y, f->color[b_fractal_loop(nr, ni, f)]);
		}
	}
}

void	mountain(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			f->c_re = (X_COMPLEX(x)) + f->movex - 0.75;
			f->c_im = (Y_COMPLEX(y)) - f->movey;
			nr = 0.0;
			ni = 0.0;
			pixel_to_image(f->img, x, y, f->color[m_fractal_loop(nr, ni, f)]);
		}
	}
}

void	right(t_frac *f, int x, int y)
{
	double	nr;
	double	ni;

	while (++y < WIN_H + 1)
	{
		x = -1;
		while (++x < WIN_L)
		{
			f->c_re = (X_COMPLEX(x)) + f->movex - 0.75;
			f->c_im = (Y_COMPLEX(y)) - f->movey;
			nr = 0.0;
			ni = 0.0;
			pixel_to_image(f->img, x, y, f->color[r_fractal_loop(nr, ni, f)]);
		}
	}
}
