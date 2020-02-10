/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_reloaded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:42:46 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 16:46:45 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			square_matrix_print(t_square_matrix *this)
{
	int i;

	i = 0;
	while (i < this->dimentions * this->dimentions)
	{
		if (this->field[i] == 0)
			ft_putchar('.');
		else
			ft_putchar(this->field[i] + 64);
		if ((i + 1) % this->dimentions == 0)
			ft_putchar('\n');
		i++;
	}
}

static void			square_matrix_set(t_square_matrix *this, t_coord coord,
										int num)
{
	int		nbr;

	if (coord.x >= this->dimentions || coord.y >= this->dimentions)
		return ;
	nbr = coord.y * this->dimentions + coord.x;
	this->field[nbr] = num;
}

static void			square_matrix_clear(t_square_matrix *this)
{
	int i;

	i = 0;
	while (i < this->dimentions * this->dimentions)
	{
		this->field[i] = 0;
		i++;
	}
}

static void			square_matrix_apply_tetr(t_square_matrix *this,
												t_tetr tetr, int num)
{
	this->set(this, tetr.loc[0], num);
	this->set(this, tetr.loc[1], num);
	this->set(this, tetr.loc[2], num);
	this->set(this, tetr.loc[3], num);
}

void				make_t_square_matrix2(t_square_matrix *matrix_revolution)
{
	matrix_revolution->apply_tetr = &square_matrix_apply_tetr;
	matrix_revolution->set = &square_matrix_set;
	matrix_revolution->clear = &square_matrix_clear;
	matrix_revolution->print = &square_matrix_print;
}
