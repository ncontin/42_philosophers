# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:56:44 by ncontin           #+#    #+#              #
#    Updated: 2025/05/06 11:57:32 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c\
		$(SRC_PARSING)\
		$(SRC_UTILS)\
		$(SRC_MEMORY)\
		$(SRC_ROUTINE)\
		src/time.c\
		src/init.c\
		src/monitor.c\


SRC_PARSING =	src/parsing/parser.c\
				$(SRC_CHECKS)\

SRC_CHECKS =	src/parsing/checks/check_args.c\
				src/parsing/checks/check_empty.c\
				src/parsing/checks/check_overflow.c\
				src/parsing/checks/check_syntax.c\

SRC_UTILS =	src/utils/ft_atol.c\
			src/utils/ft_bzero.c\
			src/utils/ft_calloc.c\
			src/utils/ft_isdigit.c\
			src/utils/ft_putstr_fd.c\
			src/utils/ft_split.c\
			src/utils/ft_strdup.c\
			src/utils/ft_strjoin.c\
			src/utils/ft_strlen.c\
			src/utils/ft_strtrim.c\

SRC_MEMORY =	src/memory/destroy.c\
				src/memory/free.c\
				src/memory/cleanup.c\

SRC_ROUTINE = 	src/routine/eat.c\
				src/routine/forks.c\
				src/routine/full.c\
				src/routine/routine.c\
				src/routine/sleep.c\
				src/routine/think.c\
				src/routine/death.c\

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CC = cc
CCFLAGS = -Wall -Wextra -Werror -pthread -g
RM = rm -f
NAME = philo
INCLUDES = -Iincludes

# Define colors for terminal output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CCFLAGS) $(INCLUDES) $^ -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully built!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
