/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:53:19 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/03 10:23:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	take_name(t_getcmd **cmd)
{
	t_getcmd *ptr;
	int i;

	i = 0;
	ptr = *cmd;
	while (i < 4)
	{
		i++;
		ptr = ptr->next;
	}
	while (ptr->cmd != 0) 
	{
		printf("%c", ptr->cmd);
		ptr = ptr->next;
	}
	printf("\n");

	return (1);
}

int take_comment(t_getcmd **cmd)
{
	t_getcmd *ptr;
	int i;

	i = 0;
	ptr = *cmd;
	//140
	while (i < 2192)
	{
		i++;
		ptr = ptr->next;
	}
	while (ptr != NULL)
	{
		printf("%d\n", ptr->cmd);
		ptr = ptr->next;
	}
	return (1);
}

int	get_cmd_name_and_comment(t_getcmd **cmd, t_proc **lst, char *file)
{
	int fd;
	int rd;
	char *c;

	c = ft_strnew(1);
	fd = open(file, O_RDONLY);
	while ((rd = read(fd, c, 1)))
		add_element_or_init(cmd, (int)c[0]);
	take_name(cmd);
	take_comment(cmd);
	free(c);
	*lst += 0;
	return (1);
}

int	main(int argc, char **argv)
{
	int i;
	(void)argv;
	(void)argc;
	t_getcmd *lst;
	t_proc *proc;
	proc = malloc(sizeof(t_proc));
	proc->name = NULL;
	proc->comment = NULL;
	lst = NULL;
	i = 1;
	get_cmd_name_and_comment(&lst, &proc, argv[1]);
	/*t_getcmd *tmp = lst;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->cmd);
		tmp = tmp->next;
	}*/
	return (0);
}
