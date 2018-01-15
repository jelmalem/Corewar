/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:14:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/06 17:22:56 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		parse_lldi_check(char **tab2, char *label)
{
	if ((parse_ind(tab2, 1, label) == 1) && (parse_reg(tab2, 1) == 1) && (parse_dir(tab2, 1, label) == 1))
		return (1);
	if ((parse_reg(tab2, 2) == 1) && (parse_dir(tab2, 3, label) == 1))
		return (1);
	if (parse_reg(tab2, 3) == 1)
		return (1);
	return (0);
}

int		parse_lldi(char *str, char *label)
{
	char	**tab;
	int		i;

	i = 0;	
	ft_printf("\033[31mLLDI DETECT\033[0m\n");
	printf("[%s]\n", str);
	tab = ft_split_spaces(str);
	// printf("[Tab de 1 : %s]\n", tab[1]);
	// while (tab[i])
	// {
	// 	printf("[%s]\n", tab[i]);
	// 	i++;
	// }
	if (ft_strcmp(tab[0], "lldi") != 0 || tab[3] != NULL)
	{
		printf("ERROR - NAME OR OPCODE\n");
		return (-1);
	}
	if (countchar(str, ',') != 2)
	{
		printf("ERROR - OPCODE\n");
		return (-1);
	}
	if (parse_lldi_check(tab, label) == 1)
	{
		printf("ERROR - SIGN\n");
		return (-1);
	}
	ft_free(tab);
	printf("OK\n");
	return (0);
}
