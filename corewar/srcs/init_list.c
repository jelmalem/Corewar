#include "../includes/corewar.h"

int	add_element_or_init(t_getcmd **lst, int cmd)
{
	t_getcmd *ptr;
	t_getcmd *tmp;

	if (!(ptr = malloc(sizeof(t_getcmd))))
		return (ERROR);
	ptr->cmd = cmd;
	ptr->next = NULL;
	if (*lst == NULL)
		*lst = ptr;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ptr;
	}
	return (1);
}
