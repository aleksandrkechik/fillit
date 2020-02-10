/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:18:31 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 16:38:29 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_vector	*vec;

	if (argc != 2)
		ft_putendl("usage: fillit input_file");
	else
	{
		fd = open(argv[1], O_RDONLY);
		vec = ft_make_t_vector(11, sizeof(t_tetr));
		if ((read_input(fd, vec)) == -1 || vec->last_item_index > 26)
			ft_putendl("error");
		else
			fillit(vec);
		ft_destroy_t_vector(vec);
	}
	return (0);
}
