/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:18:40 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/11 15:39:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCT_H
# define ASM_STRUCT_H

# include "asm.h"

typedef struct		s_champ
{
	char			*inst; // Stock des ligne en liste chaine
	struct s_champ	*next;
}					t_champ;

typedef struct		s_asm
{
	struct s_champ	*champ;
	char			*name; // Stock du nom du champ
	char			*comment;// Stock du comment
	int				flag_inst;
}					t_asm;

typedef struct		s_pos
{
	int				i;
	int				j;
	int				fd;
	int				num;
	int				flag;
	int				*tab;
	char			*dup;
	char			*line;
	char			*cut;
	char			*label;
}					t_pos;
//mes listes  je supprimerais apres

typedef struct		s_asml
{
	char			*content;
	size_t			content_size;
	struct s_asml	*prev;
	struct s_asml	*next;
}					t_asml;

typedef struct		s_vsml
{
	t_asml			*debut;
	t_asml			*fin;
	size_t			taille;
}					t_vsml;

typedef struct		s_cpt
{
	int				nb;
	int				tmp;
	int				fd;
	int				num;
	int				i;
	int				oct;
	int				auth;
	int				flag_name;
	int				flag_comm;
	int				flag_exec;

}					t_cpt;

typedef struct		s_ctrl
{
	int				octet;
	int				use;

}					t_ctrl;

typedef struct				s_mem
{
	int						i;
	int						a;
	int						fd;
	int						cpt;
	int						auth;
	char 					c;
	unsigned char const 	*ptr;
}							t_mem;

typedef struct		s_op
{
	char			*name;
	int				nbr_param;
	int				param[3];
	int				opcode;
	int				nbr_cycle;
	char			*descr;
	int				to_def_1;
	int				to_def_2;
}					t_op;

extern				t_op	g_op_tab[];

#endif
