/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:47:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/06 18:20:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		parse_ld_check(char **tab2, char *label)
{
	if ((parse_ind(tab2, 1, label) == 1) && (parse_dir(tab2, 1, label) == 1))
		return (1);
	if (parse_reg(tab2, 2) == 1)
		return (1);
	return (0);
}

int		parse_ld(char *str, char *label)
{
	char	**tab;
	int		i;

	ft_printf("\033[31mLD DETECT\033[0m\n");
	i = 0;	
	printf("[%s]\n", str);
	tab = ft_split_spaces(str);
	// printf("[Tab de 1 : %s]\n", label);
	// while (tab[i])
	// {
	// 	printf("[%s]\n", tab[i]);
	// 	i++;
	// }
	if (ft_strcmp(tab[0], "ld") != 0 || tab[3] != NULL)
	{
		printf("ERROR - NAME OR OPCODE\n");
		return (-1);
	}
	if (countchar(str, ',') != 1)
	{
		printf("ERROR - OPCODE\n");
		return (-1);
	}
	if (parse_ld_check(tab, label) == 1)
	{
		printf("ERROR - SIGN\n");
		return (-1);
	}
	ft_free(tab);
	printf("OK\n");
	return (0);
}
