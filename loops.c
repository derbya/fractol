/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:44:00 by aderby            #+#    #+#             */
/*   Updated: 2017/08/18 14:17:23 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

void	draw_stuff(t_frac *f, int x, int y)
{
	if (f->type == 0)
		julia(f, x, y);
	else if (f->type == 1)
		mandelbrot(f, x, y);
	else if (f->type == 2)
		circles(f, x, y);
	else if (f->type == 3)
		mountain(f, x, y);
	else if (f->type == 4)
		ship(f, x, y);
	else if (f->type == 5)
		right(f, x, y);
	else if (f->type == 6)
		juliav2(f, x, y);
	else if (f->type == 7)
		juliav3(f, x, y);
	else if (f->type == 8)
		web(f, x, y);
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
	mlx_string_put(f->mlx, f->win, 10, 25, 0, "Iterations:");
	mlx_string_put(f->mlx, f->win, 130, 25, 0, ft_itoa((int)f->iter));
}

int		b_fractal_loop(double nr, double ni, t_frac *f)
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
		ni = 2 * fabs(or * oi) + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}

int		m_fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = (or * or) + (oi * oi) + f->c_re;
		ni = 2 * fabs(or * oi) + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}

int		r_fractal_loop(double nr, double ni, t_frac *f)
{
	double	or;
	double	oi;
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		or = nr;
		oi = ni;
		nr = fabs((or * or)) + (oi * oi) + f->c_re;
		ni = 2 * (or * oi) + f->c_im;
		if ((nr * nr + ni * ni) > 4)
			break ;
	}
	return (pick_color(f, i));
}

t_image	*create_image(t_wincon w)
{
	t_image	*img;

	if (!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		exit(1);
	img->img = mlx_new_image(w.mlx, WIN_L, WIN_H);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->line, &img->e);
	img->bpp /= 8;
	return (img);
}
