/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4darraynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:28:38 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/21 17:01:38 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_4darraynew(int width, int height, int depth)
{
	char	***array;
	int		i;

	if (!(array = malloc(sizeof(char **) * (depth + 1))))
		return (NULL);
	i = 0;
	while (i < depth)
	{
		if (!(array[i] = ft_arraynew(width, height)))
			return (NULL);
	}
	if (!(array[i] = ft_arraynew(0, 0)))
		return (NULL);
	array[i][0][0] = '\0';
	return (array);
}
