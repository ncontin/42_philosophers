# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:56:44 by ncontin           #+#    #+#              #
#    Updated: 2025/03/03 16:31:30 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c\
		$(SRC_PARSING)\
		$(SRC_UTILS)\
		$(SRC_MEMORY)\
		$(SRC_ROUTINE)\
		src/time.c\
		src/init.c\


SRC_PARSING =	src/parsing/parser.c\
				$(SRC_CHECKS)\
				$(SRC_UTILS)\

SRC_CHECKS =	src/parsing/checks/check_args.c\
				src/parsing/checks/check_empty.c\
				src/parsing/checks/check_overflow.c\
				src/parsing/checks/check_syntax.c\

SRC_UTILS =	src/parsing/utils/ft_atol.c\
			src/parsing/utils/ft_bzero.c\
			src/parsing/utils/ft_calloc.c\
			src/parsing/utils/ft_isdigit.c\
			src/parsing/utils/ft_putstr_fd.c\
			src/parsing/utils/ft_split.c\
			src/parsing/utils/ft_strdup.c\
			src/parsing/utils/ft_strjoin.c\
			src/parsing/utils/ft_strlen.c\
			src/parsing/utils/ft_strtrim.c\

SRC_MEMORY =	src/memory/destroy.c\
				src/memory/free.c\
				src/memory/cleanup.c\

SRC_ROUTINE = 	src/routine/death.c\
				src/routine/eat.c\
				src/routine/forks.c\
				src/routine/full.c\
				src/routine/routine.c\
				src/routine/sleep.c\
				src/routine/think.c\

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -pthread -g
RM = rm -f
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
