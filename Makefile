#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/05/02 11:54:30 by cfatrane          #+#    #+#             *#
#*   Updated: 2017/05/03 10:17:53 by cfatrane         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Rules

all:
	@make -C ./libft/
	@make -C ./asm/
	@make -C ./corewar/

clean:
	@make clean -C ./libft/
	@make clean -C ./asm/
	@make clean -C ./corewar/

fclean: clean fcleanlib

fcleanlib:
	@make fclean -C ./libft/
	@make fclean -C ./asm/
	@make fclean -C ./corewar/

re : fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re
