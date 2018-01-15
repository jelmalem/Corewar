/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageslabel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:34:57 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/11 19:34:57 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_seclist		*insertion(t_seclist *list, char *nvlabel)
{
	t_seclist	*tmp;
	t_seclist	*elem;

	if (!(elem = (t_seclist*)malloc(sizeof(t_seclist))))
		error();
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

void			printfile(t_seclist *list)
{
	while (list)
	{
		ft_printf("%s\n", list->label);
		list = list->next;
	}
}

void			error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}
