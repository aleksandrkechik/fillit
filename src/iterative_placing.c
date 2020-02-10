/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_placing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:42:06 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 17:42:06 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		at_endpoint(t_tetr figure, int dimensions)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (figure.loc[i].y >= (dimensions - 1) &&
			figure_at_x_end(&figure, dimensions))
			return (1);
		i++;
	}
	return (0);
}

int		iterative_placing(t_vector *vec,
		t_square_matrix *matrix, int dim)
{
	INIT_COUNTER(current);
	while ((size_t)current < vec->last_item_index)
	{
		while (matrix->is_cross(matrix, ((t_tetr *)vec->data)[current]) != 0)
		{
			if (at_endpoint(((t_tetr *)vec->data)[current], dim))
			{
				move_tetr_begin(&((t_tetr *)vec->data)[current]);
				current--;
				if (current >= 0)
				{
					matrix->unapply_tetr(matrix,
							((t_tetr *)vec->data)[current]);
					move_tetr_right(&((t_tetr *)vec->data)[current], dim);
				}
				else
					return (0);
				continue;
			}
			move_tetr_right(&((t_tetr *)vec->data)[current], dim);
		}
		matrix->apply_tetr(matrix, ((t_tetr *)vec->data)[current], current + 1);
		current++;
	}
	return (1);
}
