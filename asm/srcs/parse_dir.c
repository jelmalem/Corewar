/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:00:01 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/09 20:00:01 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

// static int		parse_dir_ter(char **tab2, int pos, char *label)
// {
// 	char **temp;

// 	temp = ft_strsplit(tab2[pos], ':');
// 	if (ft_strcmp(temp[1], label) != 0)
// 	{	
// 		ft_free(temp);
// 		return (1);
// 	}
// 	ft_free(temp);
// 	return (0);
// }

static int		parse_dir_bis(char **tab2, int pos, char *label)
{
	int i;
	int flag;
	int	x;

	x = 0;
	i = 2;
	flag = 0;
	while (tab2[pos][i])
	{
		while (LABEL_CHARS[x])
		{
			if (tab2[pos][i] == LABEL_CHARS[x])
				flag = 1;
			x++;
		}
		if (flag != 1)
			return (1);
		i++;
		x = 0;
		flag = 0;
	}
	// if (parse_dir_ter(tab2, pos, label) == 1)
	// 	return (1);
	return (0);
}

int		parse_dir(char **tab2, int pos, char *label)
{
	int i;

	if ((tab2[pos][0] != '%') || (((tab2[pos][1] != ':') && (ft_isdigit(tab2[pos][1]) != 1)) && ((tab2[pos][1] != '-'))))
		return (1);
	if ((tab2[pos][0] == '%') && ((tab2[pos][1] == ':')))
	{
		// if (parse_dir_bis(tab2, pos, label) == 1)
			// return (1);
	}
	i = 1;
	if ((tab2[pos][0] == '%') && ((ft_isdigit(tab2[pos][1]) == 1) || ((tab2[pos][1] == '-'))))
	{
		if (tab2[pos][1] == '-' && ft_isdigit(tab2[pos][2]) == 1)
			i++;
		else if (tab2[pos][1] == '-' && ft_isdigit(tab2[pos][2]) != 1)
			return (1);
		while(tab2[pos][i])
		{
			if (ft_isdigit(tab2[pos][i]) != 1)
				return (1);
			i++;
		}
	}
	return(0);
}