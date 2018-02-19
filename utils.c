/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:27:01 by aderby            #+#    #+#             */
/*   Updated: 2017/08/03 16:37:40 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"

double		get_movex(int x)
{
	double nx;

	nx = 0.0;
	if (x > (WIN_L / 2))
		nx = 0.0004 * (x - (WIN_L / 2));
	else
		nx = 0.0004 * ((WIN_L / 2) - x) * -1;
	return (nx);
}

double		get_movey(int y)
{
	double ny;

	ny = 0.0;
	if (y > (WIN_H / 2))
		ny = 0.0004 * (y - (WIN_H / 2));
	else
		ny = 0.0004 * ((WIN_H / 2) - y) * -1;
	return (ny);
}
