/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:16:04 by aderby            #+#    #+#             */
/*   Updated: 2017/08/06 16:19:10 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

int		additional_hooks(int k, t_frac *f)
{
	if (k == 13 || k == 0 || k == 1 || k == 2)
	{
		if (k == 13 || k == 1)
			f->movey -= (k == 13) ? 0.5 : -0.5;
		if (k == 0 || k == 2)
			f->movex -= (k == 0) ? -0.5 : 0.5;
		draw_stuff(f, 0, 0);
	}
	return (0);
}
