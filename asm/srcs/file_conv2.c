/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_conv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:24:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/11 11:53:58 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_add_elm(t_vsml *lst, char *content, size_t content_size)
{
	t_asml *elem;

	if ((elem = (t_asml*)malloc(sizeof(*elem))) == NULL)
		return (-1);
	ft_memset(elem, 0, sizeof(t_asml));
	elem->content = NULL;
	elem->content_size = content_size;
	elem->content = ft_strdup((char*)content);
	elem->next = lst->debut;
	elem->prev = NULL;
	if (lst->debut)
		lst->debut->prev = elem;
	else
		lst->fin = elem;
	lst->debut = elem;
	lst->taille++;
	return (0);
}

void		sp_putchar(int *addr, int fd)
{
	t_mem	mem;
	int		i;

	ft_memset(&mem, 0, sizeof(t_mem));
	i = 0;
	while (mem.a < 16)
	{
		if (' ' <= addr[i] && addr[i] <= '~')
			ft_putchar_fd(addr[i], fd);
		else
			write(fd, ".", 1);
		i++;
		mem.a++;
	}
}

void	print_zero(int num, int fd)
{
	int chk;
	int i;

	chk = ft_nbrlen_hexa(num);
	i = 0;
	while (i < (8 - chk))
	{
		ft_putchar_fd('0', fd);
		i++;
	}
}
void	ft_init_lst(t_vsml *list)
{
	list->debut = NULL;
	list->fin = NULL;
	list->taille = 0;
}

int		ft_raz(int *tab, int size, int letter)
{
	int i;

	i = 0;
	while (i < size)
	{
		tab[i] = letter;
		i++;
	}
	return (0);
}
