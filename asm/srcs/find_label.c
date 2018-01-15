/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:28:37 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/10 14:28:37 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_listlabel		*insertion(t_listlabel *list, char *nvlabel)
{
	t_listlabel	*tmp;
	t_listlabel	*elem;

	if (!(elem = (t_listlabel*)malloc(sizeof(t_listlabel))))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	elem->label = ft_strdup(nvlabel);
	elem->next = NULL;
	if (list == NULL)
		return (elem);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

static void			printfile(t_listlabel *list)
{
	while (list)
	{
		ft_printf("%s\n", list->label);
		list = list->next;
	}
}

static int find_label_bis(char **tab2, int pos)
{
	int i;
	int flag;
	int	x;

	x = 0;
	i = 0;
	flag = 0;
	while (tab2[pos][i])
	{
		while (LABEL_CHARS[x])
		{
			if (tab2[pos][i] == LABEL_CHARS[x] || (tab2[pos][i] == ':'))
				flag = 1;
			x++;
		}
		if (flag != 1)
			return (1);
		i++;
		x = 0;
		flag = 0;
	}
	return (0);
}

char	*find_label(char *line)
{
	char **tab;
	int i;
	t_listlabel		*list;

	i = 0;
	tab = ft_split_spaces(line);
	if (((tab[0][ft_strlen(tab[0])-1] == ':')) && (find_label_bis(tab, 0) == 0))
	{
		tab[0][ft_strlen(tab[0])-1] = 0;
		list = insertion(list, tab[0]);
	}
	printfile(list);
	return(0);
}
