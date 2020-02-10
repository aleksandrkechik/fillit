/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:18:07 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 17:28:30 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_in_arr(int num, t_vector *vec)
{
	int i;

	INIT_ARR(arr, VALID_STUFF);
	i = 0;
	while (i < 19)
	{
		if (num == arr[i])
		{
			put_tetrimo(vec, num);
			return (1);
		}
		i++;
	}
	return (-1);
}

static int		shift(int num)
{
	int size;

	size = sizeof(int) * 8;
	while (((num & 0b1111) == 0) && size)
	{
		num >>= 4;
		size -= 4;
	}
	return (num);
}

static int		binary_magic(int bin[4], t_vector *vec)
{
	int i;
	int result;

	result = 0;
	while (((bin[0] % 2 != 1) && (bin[1] % 2 != 1) &&
			(bin[2] % 2 != 1) && (bin[3] % 2 != 1)) &&
			((bin[0] != 0) || (bin[1] != 0) ||
			(bin[2] != 0) || (bin[3] != 0)))
	{
		bin[0] /= 2;
		bin[1] /= 2;
		bin[2] /= 2;
		bin[3] /= 2;
	}
	i = 0;
	while (i < 4)
	{
		result <<= 4;
		result += bin[i];
		i++;
	}
	return (check_in_arr(shift(result), vec));
}

static int		is_valid(char tetr[20], int bin[4], t_vector *vec)
{
	INIT_COUNTER(i);
	INIT_COUNTER(l);
	if (tetr[0] != '.' && tetr[0] != '#')
		return (-1);
	while (i < 20)
	{
		if (tetr[i] == '.')
			bin[l] = bin[l] * 0b10 + 0b0;
		else if (tetr[i] == '#')
			bin[l] = bin[l] * 0b10 + 0b1;
		else if (tetr[i] == '\n')
		{
			if ((i + 1) % 5 != 0)
				return (-1);
			l++;
		}
		else
			return (-1);
		i++;
	}
	if (l != 4)
		return (-1);
	return (binary_magic(bin, vec));
}

int				check_tetr(char tetr[20], t_vector *vec)
{
	int bin[4];

	bin[0] = 0x0;
	bin[1] = 0x0;
	bin[2] = 0x0;
	bin[3] = 0x0;
	return (is_valid(tetr, bin, vec));
}
