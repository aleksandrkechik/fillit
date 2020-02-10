/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:36:01 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 16:39:35 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				figure_at_x_end(t_tetr *tetr, int dimensions)
{
	int f;

	f = 0;
	while (f < 4)
	{
		if (tetr->loc[f].x >= dimensions - 1)
			return (1);
		f++;
	}
	return (0);
}

static void		move_tetr_to_x_begin(t_tetr *tetr)
{
	int smallest;
	int i;

	i = 1;
	smallest = tetr->loc[0].x;
	while (i < 4)
	{
		if (smallest > tetr->loc[i].x)
			smallest = tetr->loc[i].x;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetr->loc[i].x -= smallest;
		i++;
	}
}

static void		move_tetr_to_y_begin(t_tetr *tetr)
{
	int smallest;
	int i;

	i = 1;
	smallest = tetr->loc[0].y;
	while (i < 4)
	{
		if (smallest > tetr->loc[i].y)
			smallest = tetr->loc[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetr->loc[i].y -= smallest;
		i++;
	}
}

int				move_tetr_right(t_tetr *tetr, int dimensions)
{
	int f;

	f = 0;
	if (figure_at_x_end(tetr, dimensions))
	{
		while (f < 4)
		{
			tetr->loc[f].y++;
			f++;
		}
		move_tetr_to_x_begin(tetr);
	}
	else
	{
		f = 0;
		while (f < 4)
		{
			tetr->loc[f].x++;
			f++;
		}
	}
	return (0);
}

void			move_tetr_begin(t_tetr *tetr)
{
	move_tetr_to_x_begin(tetr);
	move_tetr_to_y_begin(tetr);
}
