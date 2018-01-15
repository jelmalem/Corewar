# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 12:01:22 by cfatrane          #+#    #+#              #
#    Updated: 2017/05/10 17:58:23 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary

NAME = asm

# Path

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

INC_PATH = ./includes/

# Name

SRC_NAME =	asm.c					\
			ft_lst_data.c			\
			print_error.c			\
			parse_inst.c			\
			parse_cmd_string.c		\
			parse_label_chars.c		\
			parse_conv.c			\
			parse_add.c				\
			parse_aff.c				\
			parse_and.c				\
			parse_fork.c			\
			parse_ld.c				\
			parse_ldi.c				\
			parse_live.c			\
			parse_lld.c				\
			parse_lldi.c			\
			parse_or.c				\
			parse_st.c				\
			parse_sti.c				\
			parse_sub.c				\
			parse_xor.c				\
			parse_zjmp.c			\
			conv_tools.c 			\
			file_conv.c				\
			file_conv2.c			\
			file_conv3.c			\
			free_env.c				\
			parse_reg.c				\
			parse_ind.c				\
			parse_dir.c				\
			countchar.c				\
			ft_free.c				\
			parse_lfork.c			\
			find_label.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

LDFLAGS = -L../libft/

LFT = -lft

CC = gcc -g

# CFLAGS = -g -Wall -Wextra -Werror

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
