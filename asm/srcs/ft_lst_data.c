/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:21:59 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/06 11:24:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_champ	*ft_create_inst(char *line)
{
	t_champ	*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		return (NULL);
	champ->inst = ft_strdup(line);
	champ->next = NULL;
	return (champ);
}

void	ft_list_push_back_inst(t_champ **champ, char *line)
{
	if (*champ)
	{
		if ((*champ)->next)
			ft_list_push_back_inst(&(*champ)->next, line);
		else
			(*champ)->next = ft_create_inst(line);
	}
	else
		*champ = ft_create_inst(line);
}

void	ft_list_remove_if_inst(t_champ **champ)
{
	t_champ	*to_free;

	if (*champ)
	{
		if (!(*champ)->inst)
		{
			to_free = *champ;
			*champ = (*champ)->next;
			free(to_free);
			ft_list_remove_if_inst(champ);
		}
		else
			ft_list_remove_if_inst(&(*champ)->next);
	}
}
