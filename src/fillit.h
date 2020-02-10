/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:19:23 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/02 17:37:51 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_MK2_FILLIT_H
# define FILLIT_MK2_FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define INIT_COUNTER(X) int X = 0;
# define INIT_ARR(X, Y) int X[] = Y;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_tetr
{
	t_coord		loc[4];
}				t_tetr;

typedef struct	s_square_matrix
{
	int		*field;
	int		dimentions;

	void	(*apply_tetr)(struct s_square_matrix *this, t_tetr tetr, int num);
	void	(*unapply_tetr)(struct s_square_matrix *this, t_tetr tetr);
	void	(*set)(struct s_square_matrix *this, t_coord coord, int num);
	void	(*clear)(struct s_square_matrix *this);
	void	(*print)(struct s_square_matrix *this);
	int		(*is_cross)(struct s_square_matrix *this, t_tetr tetr);
}				t_square_matrix;

t_square_matrix	*make_t_square_matrix(int dimentions);
void			make_t_square_matrix2(t_square_matrix *matrix_revolution);
void			destroy_t_square_matrix(t_square_matrix *object);

/*
** vector stuff.
*/
typedef struct	s_vector
{
	size_t		capacity;
	size_t		last_item_index;
	size_t		data_sizeof;
	void		*data;

	void		(*push)(struct s_vector *this, void *data);
	void		(*pop)(struct s_vector *this);
	void		(*erase)(struct s_vector *this);
	void		*(*at)(struct s_vector *this, size_t index);
	size_t		(*size)(struct s_vector *this);
}				t_vector;

void			ft_make_t_vector2(t_vector *object);
t_vector		*ft_make_t_vector(size_t capacity, size_t data_sizeof);
void			ft_destroy_t_vector(t_vector *object);
# define VALID_STUFF2 ,114,39,562,305,51,561,306,99,54
# define VALID_STUFF {15,4369,547,275,802,785,23,71,113,116 VALID_STUFF2};

int				figure_at_x_end(t_tetr *tetr, int dimensions);
int				move_tetr_right(t_tetr *tetr, int dimensions);
void			move_tetr_begin(t_tetr *tetr);
int				iterative_placing(t_vector *vec, t_square_matrix *matrix,
		int dimensions);
int				get_min_field_size(int tet_nb);
void			fillit(t_vector *vec);
int				read_input(int fd, t_vector *vec);
void			put_tetrimo(t_vector *vec, int num);
int				check_tetr(char tetr[20], t_vector *vec);
#endif
