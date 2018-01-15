/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:36:53 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/10 13:37:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
# define COREWAR_STRUCT_H

# include "corewar.h"

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
