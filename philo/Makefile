# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:56:44 by ncontin           #+#    #+#              #
#    Updated: 2025/02/18 12:54:13 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c\
		src/utils.c\

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
