/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:35:23 by aderby            #+#    #+#             */
/*   Updated: 2017/08/16 14:12:38 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

int			pick_color(t_frac *f, int i)
{
	double ret;

	if (i == f->iter)
		return (0);
	else
	{
		ret = (double)i / f->iter * 256;
		return ((int)ret);
	}
}

void		set_color(double *r, double *g, double *b)
{
	static int boo;

	if (boo == 0)
	{
		*r = 255;
		*g = 9;
		*b = 10;
		boo = 1;
	}
	else
	{
		*r = rand() & 256;
		*g = rand() & 256;
		*b = rand() & 256;
	}
}

double		get_average(double color)
{
	int a;
	double ret;

	a = rand() % 256;
	if (color >= a)
		return (ret = (double)a / color);
	else
		return (ret = color / (double)a);
}

static void	fill_2(double r, double g, double b, int **color)
{
	int	br;
	int	bg;
	int bb;
	double ar;
	double ag;
	double ab;
	int	i;

	br = 0;
	bg = 0;
	bb = 0;
	ar = get_average(r);
	ag = get_average(g);
	ab = get_average(b);
	i = 128;
	set_color(&r, &g, &b);
	while (i < 256)
	{
		color[0][i] = (int)r << 16 | (int)g << 8 | (int)b;
		if (r - ar <= 0)
			br = 1;
		r -= (br == 1) ? -ar : ar;
		if (g + ag >= 255)
			bg = 1;
		g += (bg == 1) ? -ag : ag;
		if (b + ab >= 255)
			bb = 1;
		b += (bb == 1) ? -ab : ab;
		i++;
	}
}

int			*fill_color_arr(double r, double g, double b, int i)
{
	int		*color;
	int		br;
	int		bg;
	int		bb;
	double	ar;
	double	ag;
	double	ab;

	br = 0;
	bg = 0;
	bb = 0;
	ar = get_average(r);
	ag = get_average(g);
	ab = get_average(b);
	if (!(color = (int *)ft_memalloc(sizeof(int) * 256)))
		exit(1);
	while (i < 128)
	{
		color[i++] = (int)r << 16 | (int)g << 8 | (int)b;
		if (r - ar <= 0)
			br = 1;
		r -= (br == 1) ? -ar : ar;
		if (g - ag <= 0)
			bg = 1;
		g -= (bg == 1) ? -ag : ag;
		if (b - ab <= 0)
			bb = 1;
		b -= (bb == 1) ? -ab : ab;
	}
	fill_2(r, g, b, &color);
	return (color);
}
