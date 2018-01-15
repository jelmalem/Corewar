/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:00:06 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/09 20:00:06 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

// static int		parse_ind_ter(char **tab2, int pos, char *label)
// {
// 	char **temp;

// 	temp = ft_strsplit(tab2[pos], ':');
// 	if (ft_strcmp(temp[0], label) != 0)
// 	{	
// 		ft_free(temp);
// 		return (1);
// 	}
// 	ft_free(temp);
// 	return (0);
// }

static int		parse_ind_bis(char **tab2, int pos, char *label)
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
	// if (parse_ind_ter(tab2, pos, label) == 1)
	// 	return (1);
	return (0);
}

int		parse_ind(char **tab2, int pos, char *label)
{
	int i;

	if (label == NULL)
		return (1);
	i = 0;
	if ((ft_isdigit(tab2[pos][0]) != 1) && (((tab2[pos][0]) != ':')))
		return (1);
	if (ft_isdigit(tab2[pos][0]) == 1)
	{
		while(tab2[pos][i])
		{
			if (ft_isdigit(tab2[pos][i]) != 1)
				return (1);
			i++;
		}
	}
	if (tab2[pos][0] == ':')
	{
		// if (parse_ind_bis(tab2, pos,label) == 1)
		// 	return (1);
	}

	return (0);
}