# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 15:18:33 by nghaddar          #+#    #+#              #
#    Updated: 2017/02/03 17:11:44 by nghaddar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = fdf.c
SRCDIR = ./srcs/
LIBS = -framework OpenGL -framework AppKit -L ./libs -l ft -l mlx
FLAGS = -Wall- Wextra -Werror

SRCS = $(addprefix $(SRCDIR), $(SRC))

all: $(NAME)

$(NAME): 
	gcc $(LIBS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: $(NAME) clean re
