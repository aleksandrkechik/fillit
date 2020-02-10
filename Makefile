# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hturkatr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 14:24:54 by hturkatr          #+#    #+#              #
#    Updated: 2019/10/03 14:24:57 by hturkatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LNAM = libft.a
LIBF = ./libft
INCL = ./src/
SRCS = ./src/ft_destroy_t_vector.c ./src/main.c ./src/fillit.c ./src/read_input.c ./src/matrix.c ./src/ft_make_t_vector.c ./src/ft_make_t_vector2.c ./src/iterative_placing.c ./src/check_tetr.c ./src/put_tetrimo.c ./src/matrix_reloaded.c ./src/extra.c ./src/min_field_size.c
OBJ =  $(subst .c,.o,$(SRCS))
CCFL = gcc -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJ)
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF) -lft $(SRCS) -I$(LIBF) -I$(INCL) -o $(NAME)
%.o: %.c
	@$(CCFL) -I $(INCL) $< -c -o $@
clean:
	@make -C $(LIBF) clean
	@/bin/rm -f ./src/*.o
fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
