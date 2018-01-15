/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:33:37 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/08 13:31:33 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	parse_inst_line(char *inst, int nbr_line)
{
//	ft_printf("Line = '%s'\n", inst);
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (inst[i] != '\0')
	{
		j = 0;
		ft_printf("CHAR = '%c'\n", inst[i]);
		while (VALID_CHARS[j])
		{
			ft_printf("VALID_CHARS = '%c'\n", VALID_CHARS[j]);
			if (inst[i] == VALID_CHARS[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		ft_printf("\033[34mFLAG = %d\n\33[0m", flag);
		ft_printf("CHAR = '%c'\n", inst[i]);
		if (flag == 0)
		{
			ft_printf("Error Lexical at [%d:%d]\n", nbr_line + 1, i + 1);
			return (-1);
		}
		flag = 0;
		i++;
	}
	return (0);
}

int	parse_inst_label_chars(t_asm *env)
{
	int		i;
	int		nbr_line;
	t_champ	*tmp;

	i = 0;
	nbr_line = 0;
	tmp = env->champ;
	while (tmp)
	{
		if (!ft_strstr(tmp->inst, NAME_CMD_STRING) &&
				!ft_strstr(tmp->inst, COMMENT_CMD_STRING))
			if (parse_inst_line(tmp->inst, nbr_line) == -1)
				return (-1);
		nbr_line++;
		tmp = tmp->next;
	}
	return (0);
}
