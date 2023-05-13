# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptungbun <ptungbun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 11:19:31 by ptungbun          #+#    #+#              #
#    Updated: 2023/05/13 14:33:53 by ptungbun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
HEADER		= philo.h

# Variable declaration of directory
INCS_DIR	= ./includes
BUILD_DIR	= ./build
SRC_DIR		= ./srcs

# Variable declaration of file

SRCS		=	main.c
OBJS		=	$(SRCS:%.c=$(BUILD_DIR)/%.o)
MAIN		=	main.c

# Variable declaration of linking lib

all: $(NAME)

# Build step for C source

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXLINK) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(INCS_IMLX) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
