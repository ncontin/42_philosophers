# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:56:44 by ncontin           #+#    #+#              #
#    Updated: 2025/02/18 15:55:25 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c\
		$(SRC_PARSING)\
		$(SRC_UTILS)\
		$(SRC_MEMORY)\

SRC_PARSING = src/parsing/checks/check_args.c src/parsing/checks/check_empty.c src/parsing/checks/check_overflow.c src/parsing/checks/check_syntax.c src/parsing/parser.c
SRC_UTILS = src/utils/ft_atol.c src/utils/ft_bzero.c src/utils/ft_calloc.c src/utils/ft_isdigit.c src/utils/ft_putstr_fd.c src/utils/ft_split.c src/utils/ft_strdup.c src/utils/ft_strjoin.c src/utils/ft_strlen.c src/utils/ft_strtrim.c
SRC_MEMORY = src/memory/free_array.c

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
