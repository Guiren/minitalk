# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 15:23:02 by cnathana          #+#    #+#              #
#    Updated: 2014/02/08 15:43:52 by cnathana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror -g -I./libft/includes/
LIB= -L./libft/ -lft

NAME1= serveur
NAME2= client

FILES1= server s_init straddchar s_free
FILES2= client c_usage

SRC1= $(addsuffix .c, $(FILES1))
SRC2= $(addsuffix .c, $(FILES2))

OBJ1= $(SRC1:.c=.o)
OBJ2= $(SRC2:.c=.o)

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	make -C libft
	@$(CC) -o $(NAME1) $(OBJ1) $(LIB)

$(NAME2): $(OBJ2)
	@$(CC) -o $(NAME2) $(OBJ2) $(LIB)

serv_make: $(NAME1)

clie_make: $(NAME2)

clean:
	@/bin/rm -f $(OBJ1)
	@/bin/rm -f $(OBJ2)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME1) $(NAME2)
	@make -C libft/ fclean

re: fclean all
