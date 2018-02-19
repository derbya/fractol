/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:27:01 by aderby            #+#    #+#             */
/*   Updated: 2017/09/19 00:12:10 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

int		mouse_move(int x, int y, t_frac *f)
{
	static int	px;
	static int	py;

	ft_putnbr((int)(f->c_re * 1000));
	ft_putstr("\n");
	ft_putnbr((int)(f->c_im * 1000));
	ft_putstr("\n");
	if (f->b == 0)
	{
		if (f->type != 1)
		{
			if (px > x)
				f->c_im += 0.025;
			else if (px < x)
				f->c_im -= 0.025;
			if (py > y)
				f->c_re -= 0.025;
			else if (py < y)
				f->c_re += 0.025;
			px = x;
			py = y;
			draw_stuff(f, 0, 0);
		}
	}
	return (1);
}

int		expose_hook(t_frac *f)
{
	draw_stuff(f, 0, 0);
	return (1);
}

int		mouse_press(int button, int x, int y, t_frac *f)
{
	button *= 1;
	if (x == 0)
		x = 1;
	if (y == 0)
		y = 1;
	if (button == 4)
	{
		f->zoom *= 1.05;
		f->movex += get_movex(x) / f->zoom;
		f->movey -= get_movey(y) / f->zoom;
		draw_stuff(f, 0, 0);
	}
	if (button == 5)
	{
		f->zoom *= 0.95;
		draw_stuff(f, 0, 0);
	}
	return (1);
}

int		exit_program(t_frac *f)
{
	if (f->next == NULL)
		exit(0);
	else
	{
		mlx_destroy_window(f->mlx, f->win);
		f->next->next = NULL;
		return (0);
	}
}

int		key_press(int keycode, t_frac *f)
{
	if (keycode == 53)
		exit_program(f);
	else if (keycode == 34 || keycode == 31)
	{
		f->iter += (keycode == 34 ? 24 : -24);
		draw_stuff(f, 0, 0);
	}
	else if (keycode == 12 || keycode == 14)
	{
		f->zoom *= (keycode == 14) ? 3 : (1 / f->zoom);
		draw_stuff(f, 0, 0);
	}
	else if (keycode == 15)
	{
		free(f->color);
		f->color = fill_color_arr(rand() % 256, rand() % 256, rand() % 256, 0);
		draw_stuff(f, 0, 0);
	}
	else if (keycode == 3)
		f->b = (f->b == 0) ? 1 : 0;
	else
		return (additional_hooks(keycode, f));
	return (0);
}
