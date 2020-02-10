/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:18:26 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 16:24:26 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_vector *vec)
{
	int				field_size;
	t_square_matrix	*matrix;

	field_size = get_min_field_size(vec->last_item_index);
	matrix = make_t_square_matrix(field_size);
	while (iterative_placing(vec, matrix, field_size) == 0)
	{
		destroy_t_square_matrix(matrix);
		field_size++;
		matrix = make_t_square_matrix(field_size);
	}
	matrix->print(matrix);
	destroy_t_square_matrix(matrix);
}
