/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:15:01 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/06 17:23:53 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		parse_zjmp_check(char **tab2, char *label)
{
	if (parse_dir(tab2, 1, label) == 1)
		return (1);
	return (0);
}

int		parse_zjmp(char *str, char *label)
{
	char	**tab;
	int		i;

	ft_printf("\033[31mZJMP DETECT\033[0m\n");
	i = 0;	
	printf("[%s]\n", str);
	// tab = ft_split_spaces(str);
	// printf("[Tab de 1 : %s]\n", tab[1]);
	// while (tab[i])
	// {
	// 	printf("[%s]\n", tab[i]);
	// 	i++;
	// }
	if (ft_strcmp(tab[0], "zjmp") != 0 || tab[2] != NULL)
	{
		printf("ERROR - NAME OR OPCODE\n");
		return (-1);
	}
	if (countchar(str, ',') != 0)
	{
		printf("ERROR - OPCODE\n");
		return (-1);
	}
	if (parse_zjmp_check(tab, label) == 1)
	{
		printf("ERROR - SIGN\n");
		return (-1);
	}
	ft_free(tab);
	printf("OK\n");
	return (0);
}
