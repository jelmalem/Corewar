/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:35:10 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/05 18:35:39 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		first_char(char *line, int on)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (line[pos.i])
	{
		pos.j = 0;
		pos.flag = 0;
		while (LABEL_CHARS[pos.j])
	 	{
			if (LABEL_CHARS[pos.j] == line[pos.i])
				pos.flag = 1;
			pos.j++;
		}
		if (on)
		{
			if (pos.flag == 0)
				break ;
		}
		else
			if (pos.flag == 1)
				break ;
		pos.i++;
	}
	return (pos.i);
}

char	*check_label_line(char *line)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = first_char(line, 1);
	while (line[pos.i])
	{
		pos.j = 0;
		pos.flag = 0;
		while (LABEL_CHARS[pos.j])
	 	{
			if (LABEL_CHARS[pos.j] == line[pos.i])
				pos.flag = 1;
			pos.j++;
		}
		if (pos.flag == 0)
			break ;
		pos.i++;
	}
	if (line[pos.i] != ':')
		return (line + ((first_char(line + pos.i, 0)) + pos.i));
	return (line + ((first_char(line + pos.i, 0)) + pos.i));
}

int	check_command2(char *str)
{
	if (ft_strcmp(str, "xor") == 0)
		return (13);
	else if (ft_strcmp(str, "lldi") == 0)
		return (14);
	else if (ft_strcmp(str, "and") == 0)
		return (15);
	else if (ft_strcmp(str, "lfork") == 0)
		return (16);
	return (0);
}

int	check_command(char *str)
{
	// ft_putstr("HELLO");
	if (ft_strcmp(str, "sti") == 0)
		return (1);
	else if (ft_strcmp(str, "fork") == 0)
		return (2);
	else if (ft_strcmp(str, "lld") == 0)
		return (3);
	else if (ft_strcmp(str, "ld") == 0)
		return (4);
	else if (ft_strcmp(str, "add") == 0)
		return (5);
	else if (ft_strcmp(str, "zjmp") == 0)
		return (6);
	else if (ft_strcmp(str, "sub") == 0)
		return (7);
	else if (ft_strcmp(str, "ldi") == 0)
		return (8);
	else if (ft_strcmp(str, "or") == 0)
		return (9);
	else if (ft_strcmp(str, "st") == 0)
		return (10);
	else if (ft_strcmp(str, "aff") == 0)
		return (11);
	else if (ft_strcmp(str, "live") == 0)
		return (12);
	else if (check_command2(str))
		return (check_command2(str));
	return (0);
}
