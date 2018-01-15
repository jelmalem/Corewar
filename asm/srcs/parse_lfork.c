/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 22:21:13 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/09 22:21:13 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		parse_lfork_check(char **tab2, char *label)
{
	if (parse_dir(tab2, 1, label) == 1)
		return (1);
	return (0);
}

int		parse_lfork(char *str, char *label)
{
	char	**tab;
	int		i;

	ft_printf("\033[31mlfork DETECT\033[0m\n");
	i = 0;	
	printf("[%s]\n", str);
	tab = ft_split_spaces(str);
	// printf("[Tab de 1 : %s]\n", tab[1]);
	// while (tab[i])
	// {
	// 	printf("[%s]\n", tab[i]);
	// 	i++;
	// }
	if (ft_strcmp(tab[0], "lfork") != 0 || tab[2] != NULL)
	{
		printf("ERROR - NAME OR OPCODE\n");
		return (-1);
	}
	if (countchar(str, ',') != 0)
	{
		printf("ERROR - OPCODE\n");
		return (-1);
	}
	if (parse_lfork_check(tab, label) == 1)
	{
		printf("ERROR - SIGN\n");
		return (-1);
	}
	ft_free(tab);
	printf("OK\n");
	return (0);
}