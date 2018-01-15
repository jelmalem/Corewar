/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 11:24:10 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/06 11:32:24 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_list_clear_inst(t_champ **champ)
{
	if (*champ != NULL)
	{
		ft_list_clear_inst(&((*champ)->next));
		free((*champ)->inst);
		free(*champ);
		*champ = NULL;
	}
}

void	ft_free_env(t_asm *env)
{
	ft_list_clear_inst(&env->champ);
	free(env->name);
	free(env->comment);
	free(env);
}
