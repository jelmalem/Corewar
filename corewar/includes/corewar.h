/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:00:29 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/10 13:39:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../libft/libft.h"
# include <ncurses.h>
# include "op.h"
# include "corewar_struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define USAGE "Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth]\
[-a] <champion1.cor> <...>\n"

# define ERROR -1

typedef struct	s_getcmd
{
	int			cmd;
	struct		s_getcmd *next;

}				t_getcmd;

typedef struct	s_proc
{
	int			player_nb;
	int			r[16];
	char		*name;
	char		*comment;
	struct		s_getcmd *ptr;
	struct		 s_proc *next;
}				t_proc;

int add_element_or_init(t_getcmd **lst, int cmd);

#endif
