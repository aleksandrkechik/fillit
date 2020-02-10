/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_field_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:36:59 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 16:37:52 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	float lim_max;
	float lim_min;
	float n;

	n = (float)nb;
	if (n < 1)
		return (0);
	if (n == 1)
		return (1);
	lim_max = n;
	lim_min = 1;
	while (lim_max > lim_min)
	{
		lim_max = (lim_max + lim_min) / 2;
		lim_min = n / lim_max;
		if ((int)lim_max == (int)lim_min)
			return ((int)lim_max);
	}
	return (0);
}

int		get_min_field_size(int tet_nb)
{
	int	n;

	n = ft_sqrt(tet_nb * 4);
	return (n);
}
