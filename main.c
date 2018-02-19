/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 10:32:58 by aderby            #+#    #+#             */
/*   Updated: 2017/08/07 03:44:40 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

void	pixel_to_image(t_image *img, int x, int y, int color)
{
	int i;

	if (x < 0 || x > WIN_L || y < 0 || y > WIN_H)
		return ;
	i = (x * 4) + (y * img->line);
	img->data[i++] = color;
	img->data[i++] = (color >> 8);
	img->data[i++] = (color >> 16);
}

int		err_handling(void)
{
	ft_putendl("Usage: fractol takes up to two arguments");
	ft_putendl("Proper arguments for fractal are: [Julia]");
	ft_putendl("                                  [Mandelbrot]");
	ft_putendl("                                  [Circles]");
	ft_putendl("                                  [Ship]");
	ft_putendl("                                  [Peaks]");
	ft_putendl("                                  [Right]");
	ft_putendl("                                  [Julia v2.0001]");
	ft_putendl("                                  [Julia v2.0002]");
	ft_putendl("                                  [Web]");
	ft_putendl("Enjoy responsibly");
	return (0);
}

int		name_compare(char *s)
{
	if (ft_strequ(s, "Julia"))
		return (1);
	else if (ft_strequ(s, "Mandelbrot"))
		return (1);
	else if (ft_strequ(s, "Circles"))
		return (1);
	else if (ft_strequ(s, "Ship"))
		return (1);
	else if (ft_strequ(s, "Web"))
		return (1);
	else if (ft_strequ(s, "Peaks"))
		return (1);
	else if (ft_strequ(s, "Julia v2.0001"))
		return (1);
	else if (ft_strequ(s, "Julia v2.0002"))
		return (1);
	else if (ft_strequ(s, "Right"))
		return (1);
	return (0);
}

int		err_checking(int ac, char **av)
{
	if (ac == 1)
		return (-1);
	if (ac > 3)
		return (-1);
	if (ac == 2)
	{
		if (name_compare(av[1]))
			return (1);
		return (-1);
	}
	if (ac == 3)
	{
		if (name_compare(av[1]))
			return (name_compare(av[2]) ? 1 : -1);
		if (name_compare(av[2]))
			return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_wincon	w;
	int			err;

	err = err_checking(ac, av);
	if (err == -1)
		return (err_handling());
	initialize_wincon(&w, ac, av);
	mlx_loop(w.mlx);
	return (0);
}
