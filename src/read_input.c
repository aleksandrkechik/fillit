/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:23:07 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 17:36:08 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	increment(int *i, int *c)
{
	(*i)++;
	(*c)++;
}

static int	assert(int c)
{
	if (c != 0)
		return (-1);
	return (1);
}

int			read_input(int fd, t_vector *vec)
{
	char	buf[1000];
	char	tetr[20];
	int		ret;

	INIT_COUNTER(i);
	INIT_COUNTER(c);
	if (fd < 0 || fd == 1)
		return (-1);
	ret = read(fd, buf, 1000);
	if (ret <= 18)
		return (-1);
	while (i <= ret)
	{
		tetr[c] = buf[i];
		if (c == 19)
		{
			c = -1;
			i++;
			if ((i + 1 == ret && (buf[i] != '\n')) ||
				(buf[i] == '\n' && i == ret - 1) || check_tetr(tetr, vec) == -1)
				return (-1);
		}
		increment(&c, &i);
	}
	return (assert(c));
}
