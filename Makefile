# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 11:19:31 by ptungbun          #+#    #+#              #
#    Updated: 2023/07/08 17:01:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -pthread
HEADER		= philo.h

# Variable declaration of directory
INCS_DIR	= ./includes
BUILD_DIR	= ./build
SRC_DIR		= ./srcs

# Variable declaration of file

SRCS		=	arg_consideration.c main.c mini_lib.c var_init.c \
				check_end_loop.c thread_init.c philo_print.c
OBJS		=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# Variable declaration of linking lib

all: $(NAME)

# Build step for C source

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
