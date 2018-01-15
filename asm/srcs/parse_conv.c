/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:21:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/11 11:26:41 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*find_text(char *str, char *cut)
{
	int i;
	int	flag1;
	int	flag2;

	i = 0;
	flag1 = 0;
	flag2 = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 34 && flag1)
		{
			flag2 = i;
			break;
		}
		if (str[i] == 34 && !flag1)
			flag1 = i;
		i++;
	}
	cut = ft_strsub((str + flag1 + 1), 0, (flag2 - flag1 - 1));
	return (cut);
}

int		empty_line(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ')
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

void	ft_attribute_ptr(int (*ptr_func[])(char *s, char *label))
{
	ptr_func[0] = &parse_error;
	ptr_func[1] = &parse_sti;
	ptr_func[2] = &parse_fork;
	ptr_func[3] = &parse_lld;
	ptr_func[4] = &parse_ld;
	ptr_func[5] = &parse_add;
	ptr_func[6] = &parse_zjmp;
	ptr_func[7] = &parse_sub;
	ptr_func[8] = &parse_ldi;
	ptr_func[9] = &parse_or;
	ptr_func[10] = &parse_st;
	ptr_func[11] = &parse_aff;
	ptr_func[12] = &parse_live;
	ptr_func[13] = &parse_xor;
	ptr_func[14] = &parse_lldi;
	ptr_func[15] = &parse_and;
	ptr_func[16] = &parse_lfork;
}

int	ft_check_conv(char *str, int (*ptr_func[])(char *s, char *label), t_vsml *dup)
{
	t_pos pos;
	static char *lab;

	ft_memset(&pos, 0, sizeof(t_pos));
	// find_label(str);
	pos.dup = check_label_line(str);
	ft_add_elm(dup, pos.dup, ft_strlen(pos.dup));
	pos.line = ft_strsub((const char*)pos.dup, 0, first_char(pos.dup, 1));
	ft_printf("DUP = [%s]\n", pos.dup);
	ft_printf("LINE = [%s]\n", pos.line);
	if (ptr_func[check_command(pos.line)](pos.dup, lab) == (-1))
	{
		ft_printf("POV MERDE\n");
		return (-1);
	}
	if (ptr_func)
		pos.i = 0;
	free (pos.line);
	return (0);
}

int	parse_conv(char *str, t_vsml *dup)
{
	t_pos	pos;
	int		(*ptr_func[16])(char*, char*);

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_attribute_ptr(ptr_func);
	if (str[0] == '.' || str[0] == '#' || empty_line(str) == 1)
	{
		if (str[0] == '.' || str[0] == '#')
		{
			pos.cut = find_text(str, pos.cut);
			ft_add_elm(dup, pos.cut, ft_strlen(str));
			free (pos.cut);
		}
		return (0);
	}
	if (ft_check_conv(str, ptr_func, dup) == -1)
		return (-1);
	return (0);
}
