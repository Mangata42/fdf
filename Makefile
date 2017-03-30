# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 15:18:33 by nghaddar          #+#    #+#              #
#    Updated: 2017/03/30 17:59:50 by nghaddar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
		ft_struct.c \
		ft_errors.c \
		ft_hooks.c \
		ft_hooks_bis.c \
		ft_maps.c \
		ft_draw.c \
		ft_bres.c 

SRCDIR = ./srcs/
LIBS = -framework OpenGL -framework AppKit -L ./libs -l mlx -L ./libs/libft -l ft
FLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(SRCDIR), $(SRC))

all: $(NAME)

$(NAME):
	make -C ./libs/libft
	gcc $(FLAGS) $(LIBS) $(SRCS) -o $(NAME)

clean:
	make -C./libs/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libs/libft fclean

re: fclean all

.PHONY: $(NAME) clean fclean re
