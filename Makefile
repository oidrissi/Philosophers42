# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 19:01:02 by oidrissi          #+#    #+#              #
#    Updated: 2021/09/19 19:02:31 by oidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = philo
NAMEB = philo_bonus

SRC = main.c\

SRCB = bonus_main.c\

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) $(FLAGS) -o $(NAME)
	
debug:
	@$(CC) -g $(SRC) $(FLAGS) -o $(NAME) -fsanitize=address
	
bonus: $(NAMEB)

$(NAMEB): $(SRCB)
	@$(CC) $(SRCB) $(FLAGS) -o $(NAMEB)

fclean:
	@rm -rf $(NAME) $(NAMEB)

re: fclean all