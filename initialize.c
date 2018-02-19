/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:35:23 by aderby            #+#    #+#             */
/*   Updated: 2017/09/23 14:08:59 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

void			initialize_hooks(t_frac *f)
{
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 4, 0, mouse_press, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_hook(f->win, 12, 0, expose_hook, f);
	mlx_hook(f->win, 17, 0, exit_program, f);
}

static int		type_check(char *type)
{
	if (ft_strequ(type, "Julia"))
		return (0);
	else if (ft_strequ(type, "Mandelbrot"))
		return (1);
	else if (ft_strequ(type, "Circles"))
		return (2);
	else if (ft_strequ(type, "Peaks"))
		return (3);
	else if (ft_strequ(type, "Right"))
		return (5);
	else if (ft_strequ(type, "Julia v2.0001"))
		return (6);
	else if (ft_strequ(type, "Julia v2.0002"))
		return (7);
	else if (ft_strequ(type, "Web"))
		return (8);
	else
		return (4);
}

static t_frac	*new_frac(char *type)
{
	t_frac	*frac;

	if (!(frac = (t_frac*)ft_memalloc(sizeof(t_frac))))
		exit(1);
	frac->type = type_check(type);
	frac->mlx = NULL;
	frac->next = NULL;
	return (frac);
}

static void		initialize_wincon_next(t_wincon *w, char **av)
{
	w->fractal->next = new_frac(av[2]);
	w->fractal->next->win = mlx_new_window(w->mlx, WIN_L, WIN_H, av[2]);
	w->fractal->next->next = w->fractal;
	w->fractal->next->mlx = w->mlx;
	initialize_hooks(w->fractal->next);
	w->fractal->next->img = create_image(*w);
	w->fractal->next->c_re = -0.7;
	w->fractal->next->c_im = 0.27135;
	w->fractal->next->iter = 150;
	w->fractal->next->zoom = 1.0;
	w->fractal->next->movex = 0;
	w->fractal->next->movey = 0;
	w->fractal->next->b = 0;
	w->fractal->next->color = fill_color_arr(RED, GREEN, BLUE, 0);
	expose_hook(w->fractal);
}

void			initialize_wincon(t_wincon *w, int ac, char **av)
{
	w->mlx = mlx_init();
	w->fractal = new_frac(av[1]);
	w->fractal->win = mlx_new_window(w->mlx, WIN_L, WIN_H, av[1]);
	w->fractal->img = create_image(*w);
	w->fractal->mlx = w->mlx;
	w->fractal->iter = 150;
	w->fractal->zoom = 1.0;
	w->fractal->c_re = -0.7;
	w->fractal->c_im = 0.27135;
	w->fractal->movex = 0;
	w->fractal->movey = 0;
	w->fractal->b = 0;
	w->fractal->color = fill_color_arr(RED, GREEN, BLUE, 0);
	initialize_hooks(w->fractal);
	if (ac == 3)
		initialize_wincon_next(w, av);
}
