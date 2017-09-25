# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 16:35:40 by ybitton           #+#    #+#              #
#    Updated: 2017/01/16 16:40:32 by ybitton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

SRC = main.o read.o tetris_part.o map_part.o resolution.o ft_putstr.o ft_lstadd.o ft_lstdel.o ft_lstnew.o ft_memalloc.o ft_memdel.o ft_putchar.o ft_strnew.o ft_memcpy.o ft_strncpy.o

INC = fillit.h

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -I $(INC) -o $(NAME)
	@echo "Compilation success"
clean:
	@rm -rf *.o
	@echo "Delete .o"
fclean: clean
	@rm -rf $(NAME)
	@echo "Delete fillit"
re: fclean all