# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/08/07 03:50:02 by aderby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

C_FIL = hooks.c fractals.c fractals2.c main.c loops.c initialize.c \
		color.c utils.c normsucks.c additional_hooks.c more.c

O_FIL = *.o
O_LOC = obj

GCC_FLAGS = gcc -Wall -Wextra -Werror -L miniLibx -lmlx -framework OpenGL \
			-framework AppKit

LIB = libft/libft.a

all: $(NAME)

$(NAME):
		cd libft && make re
		cd miniLibx && make re
			$(GCC_FLAGS) $(LIB) $(C_SRC) $(C_FIL) -o $(NAME)

clean:
		cd libft && make clean

fclean: clean
		cd libft && make fclean
			/bin/rm -f $(NAME)

re: fclean all
