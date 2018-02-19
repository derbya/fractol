/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normsucks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:44:00 by aderby            #+#    #+#             */
/*   Updated: 2017/08/18 14:26:14 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

int		boring_fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = (or * or) - (oi * oi) + 0.0;
		ni = 2 * or * oi + 0.0;
		if ((nr * nr + ni * ni) > 8)
			break ;
	}
	return (pick_color(f, i));
}

int		l_fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = 2 * (or * or) - (oi * oi) + f->c_re;
		ni = 2 * or * oi + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}

int		w_fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = (or * or) - (oi * oi) + f->c_re;
		ni = 2 * fabs((or * oi)) + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}

int		fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = (or * or) - (oi * oi) + f->c_re;
		ni = 2 * (or * oi) + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}
