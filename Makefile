# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 19:01:02 by oidrissi          #+#    #+#              #
#    Updated: 2021/09/24 17:47:57 by oidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = philo

SRC = main.c\
	  parse_init.c\
	  threads.c\
	  time.c

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) $(FLAGS) -o $(NAME)
	
debug:
	@$(CC) -g $(SRC) $(FLAGS) -o $(NAME) -fsanitize=address

fclean:
	@rm -rf $(NAME) $(NAMEB)

re: fclean all