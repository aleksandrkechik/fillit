/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetrimo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:18:42 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 17:50:03 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr			put_coord(t_coord first, t_coord second, t_coord third,
							t_coord fourth)
{
	t_tetr new;

	new.loc[0] = first;
	new.loc[1] = second;
	new.loc[2] = third;
	new.loc[3] = fourth;
	return (new);
}

static void		put_tetrimo2(int num, t_tetr *tetr)
{
	if (num == 15)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){2, 0},
						(t_coord){3, 0});
	if (num == 4369)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){0, 1}, (t_coord){0, 2},
						(t_coord){0, 3});
	if (num == 547)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){0, 1}, (t_coord){0, 2},
						(t_coord){1, 2});
	if (num == 275)
		*tetr = put_coord((t_coord){1, 0}, (t_coord){1, 1}, (t_coord){1, 2},
						(t_coord){0, 2});
	if (num == 802)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){0, 1},
						(t_coord){0, 2});
	if (num == 785)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){1, 1},
						(t_coord){1, 2});
	if (num == 23)
		*tetr = put_coord((t_coord){0, 1}, (t_coord){1, 1}, (t_coord){2, 1},
						(t_coord){2, 0});
	if (num == 71)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){0, 1}, (t_coord){1, 1},
						(t_coord){2, 1});
}

static void		put_tetrimo3(int num, t_tetr *tetr)
{
	if (num == 113)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){2, 0},
						(t_coord){2, 1});
	if (num == 116)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){2, 0},
						(t_coord){0, 1});
	if (num == 114)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){2, 0},
						(t_coord){1, 1});
	if (num == 39)
		*tetr = put_coord((t_coord){1, 0}, (t_coord){0, 1}, (t_coord){1, 1},
						(t_coord){2, 1});
	if (num == 562)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){0, 1}, (t_coord){1, 1},
						(t_coord){0, 2});
	if (num == 305)
		*tetr = put_coord((t_coord){1, 0}, (t_coord){0, 1}, (t_coord){1, 1},
						(t_coord){1, 2});
	if (num == 51)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){0, 1},
						(t_coord){1, 1});
	if (num == 561)
		*tetr = put_coord((t_coord){0, 0}, (t_coord){0, 1}, (t_coord){1, 1},
						(t_coord){1, 2});
}

void			put_tetrimo(t_vector *vec, int num)
{
	t_tetr tetr;

	put_tetrimo2(num, &tetr);
	put_tetrimo3(num, &tetr);
	if (num == 306)
		tetr = put_coord((t_coord){1, 0}, (t_coord){0, 1}, (t_coord){1, 1},
				(t_coord){0, 2});
	if (num == 99)
		tetr = put_coord((t_coord){0, 0}, (t_coord){1, 0}, (t_coord){1, 1},
				(t_coord){2, 1});
	if (num == 54)
		tetr = put_coord((t_coord){1, 0}, (t_coord){2, 0}, (t_coord){0, 1},
				(t_coord){1, 1});
	vec->push(vec, &tetr);
}
