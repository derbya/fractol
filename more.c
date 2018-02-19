/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:44:00 by aderby            #+#    #+#             */
/*   Updated: 2017/08/07 03:49:46 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

int		z_fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = (or / or) - (oi * oi) + f->c_re;
		ni = fabs((or / oi)) + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}

void	web(t_frac *f, int x, int y)
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
			pixel_to_image(f->img, x, y, f->color[z_fractal_loop(nr, ni, f)]);
		}
	}
}
