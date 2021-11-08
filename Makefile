# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 09:42:51 by mazoukni          #+#    #+#              #
#    Updated: 2021/11/08 20:27:21 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = philo.c tools.c init.c display.c error.c utils.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all