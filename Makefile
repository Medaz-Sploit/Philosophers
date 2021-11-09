# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 09:42:51 by mazoukni          #+#    #+#              #
#    Updated: 2021/11/09 15:23:11 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = philo.c tools.c init.c display.c error.c utils.c
OBJ = philo.o tools.o init.o display.o error.o utils.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(NAME)

re: fclean all