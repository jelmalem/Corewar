#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/05/02 11:59:16 by cfatrane          #+#    #+#             *#
#*   Updated: 2017/05/03 17:35:02 by cfatrane         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Binary

NAME = corewar

# Path

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

INC_PATH = ./includes/

# Name

SRC_NAME =	corewar.c			\
			init_list.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

LDFLAGS = -L../libft/

LFT = -lft

CC = gcc $(CFLAGS)

CFLAGS =  -Wall -Wextra -Werror

# Rules

all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	@make -C../libft/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean:
	@make clean -C ../libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean fcleanlib
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

fcleanlib:
	@make fclean -C ../libft/

re : fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re
