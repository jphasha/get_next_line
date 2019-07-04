# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jphasha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 15:04:37 by jphasha           #+#    #+#              #
#    Updated: 2019/07/04 16:06:33 by jphasha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = gcc

SOURCES = get_next_line.c

OBJECTS = get_next_line.o

LFT = libft/libft.a

flags = -Wall -Wextra -Werror

$(NAME): $(OBJECTS) $(LFT)
	clang $(flags) -I libft/ -c $(SOURCES)
	clang -o $(NAME) $(OBJECTS) -I libft/ -L libft/ -lft

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(flags)

$(LFT):
	make -C libft/ re -C libft/

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
	make -C libft/ clean

fclean:
	rm -rf $(NAME) a.out run_gnl
	make -C libft/ fclean

c:
	$(CC) -o run_gnl main.c $(NAME) $(flags)

n:
	norminette
