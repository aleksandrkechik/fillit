/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:40:33 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 16:42:08 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			square_matrix_unapply_tetr(t_square_matrix *this,
												t_tetr tetr)
{
	this->apply_tetr(this, tetr, 0);
}

static int			square_matrix_is_cross(t_square_matrix *this, t_tetr tetr)
{
	int	i;
	int	nbr;

	i = 0;
	while (i < 4)
	{
		nbr = tetr.loc[i].y * this->dimentions + tetr.loc[i].x;
		if (this->field[nbr] != 0 || tetr.loc[i].x == this->dimentions ||
			tetr.loc[i].y == this->dimentions)
			return (1);
		i++;
	}
	return (0);
}

t_square_matrix		*make_t_square_matrix(int dimentions)
{
	t_square_matrix	*object;

	object = (t_square_matrix *)malloc(sizeof(t_square_matrix));
	if (!object)
		return (NULL);
	make_t_square_matrix2(object);
	object->is_cross = &square_matrix_is_cross;
	object->unapply_tetr = &square_matrix_unapply_tetr;
	object->dimentions = dimentions;
	object->field = (int *)malloc(dimentions * dimentions * sizeof(int));
	if (!object->field)
	{
		free(object);
		return (NULL);
	}
	object->clear(object);
	return (object);
}

void				destroy_t_square_matrix(t_square_matrix *object)
{
	free(object->field);
	free(object);
}
