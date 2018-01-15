/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:00:10 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/09 20:00:10 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		parse_reg(char **tab2, int pos)
{
	int x;

	x = 1;
	if (tab2[pos][0] != 'r' || (ft_isdigit(tab2[pos][1]) != 1))
		return (1);
	while(tab2[pos][x])
	{
		if (ft_isdigit(tab2[pos][x]) != 1)
			return (1);
		x++;
	}
	if (x == 4)
	{
		ft_printf("REG TROP GRAND\n");
		return (1);
	}
	return (0);
}