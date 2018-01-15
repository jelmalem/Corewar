/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:30:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/06 12:08:21 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	parse_inst_name_count(t_asm *env)
{
	char **tab;
	int i;

	tab = ft_strsplit(env->name, '"');
	i = 0;
	while(tab[1][i])
	{
		ft_printf("Name = %c ", tab[1][i]);
		i++;
	}
	if (i > 128)
		return(-1);
	// ft_printf("Comment = %s\n", env->comment);
	// ft_printf("Name = %s\n", env->name);
	return (0);
}

int	parse_inst_comment_count(t_asm *env)
{
	char **tab;
	int i;

	tab = ft_strsplit(env->comment, '"');
	i = 0;
	if (tab[1] == NULL)
		return (-1);
	while(tab[1][i])
	{
		ft_printf("Comment = %c ", tab[1][i]);
		i++;
	}
	if (i > 2048)
		return (-1);
	// ft_printf("Comment = %s\n", env->comment);
	// ft_printf("Name = %s\n", env->name);
	return (0);
}

int	parse_inst(t_asm *env)
{
	if (parse_inst_name(env) == -1 || parse_inst_name_count(env) == -1)
		return (-1);
	if (parse_inst_comment(env) == -1 || parse_inst_comment_count(env) == -1)
		return (-1);
	// if (parse_inst_label_chars(env) == -1)
	// 	return (-1);
	parse_inst_name_count(env);
	ft_printf("Comment = %s\n", env->comment);
	ft_printf("Name = %s\n", env->name);
	return (0);
}
