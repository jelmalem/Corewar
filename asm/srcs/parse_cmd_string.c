/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:29:50 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/06 11:31:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	parse_inst_comment(t_asm *env)
{
	int		flag;
	t_champ	*tmp;

	flag = 0;
	tmp = env->champ;
	while (tmp)
	{
		if (ft_strstr(tmp->inst, COMMENT_CMD_STRING))
		{
			env->comment = ft_strdup(tmp->inst);
			flag++;
		}
		tmp = tmp->next;
	}
	if (flag == 0 || flag > 1)
		return (print_error("Comment"));
	return (0);
}

int	parse_inst_name(t_asm *env)
{
	int		flag;
	t_champ	*tmp;

	flag = 0;
	tmp = env->champ;
	while (tmp)
	{
		if (ft_strstr(tmp->inst, NAME_CMD_STRING))
		{
			env->name = ft_strdup(tmp->inst);
			flag++;
		}
		tmp = tmp->next;
	}
	if (flag == 0 || flag > 1)
		return (print_error("Name"));
	return (0);
}
