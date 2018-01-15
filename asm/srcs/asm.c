/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:19:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/11 11:25:57 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_asm	*env;
	t_vsml	dup;
	t_asml	*elem;


	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	if (!(env = ft_memalloc(sizeof(t_asm))))
		return (-1);
	if (argc == 2)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_list_push_back_inst(&env->champ, line);
			free (line);
		}
	}
	ft_list_remove_if_inst(&env->champ);
 	t_champ	*tmp;
	tmp = env->champ;
	while (tmp)
	{
		ft_printf("%s\n", tmp->inst);
		tmp = tmp->next;
	}
	tmp = env->champ;
	if (parse_inst(env) == -1)
		return (-1);
	ft_init_lst(&dup);
	while (tmp)
	{
		if (parse_conv(tmp->inst, &dup) == -1)
		{
			ft_printf("ERROR\n");
			return (-1);
		}
		tmp = tmp->next;
	}
	file_conv(&dup);
	elem = dup.fin;
	while (elem != NULL)
	{
		//printf("%s\n", elem->content);
		elem = elem->prev;
	}
	ft_free_env(env);
	return (0);
}
