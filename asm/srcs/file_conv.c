/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 09:27:54 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/05/11 15:54:24 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	print_char(int *addr, size_t size, int fd, t_ctrl *ctrl)
{
	t_mem mem;
	int	i;
	ft_memset(&mem, 0, sizeof(t_mem));
	i = 0;
	while (mem.a < (int)size)
	{
		if (i + ctrl->octet < 128)
		{
			ft_print_hex_fd2(addr[i], fd);
			mem.cpt = mem.cpt + ft_nbrlen_hexa(addr[i]);
			if (addr[i] <= 15)
				mem.cpt++;
			if (mem.cpt == 4)
			{
				write(fd, " ", 1);
				mem.cpt = 0;
			}
		}
		else
		{
			ctrl->octet = 128;
			break ;
		}
		i++;
		mem.a += 1;
	}
	return (8);
}

int		*ft_generate_tab(int first_line, int *tab, t_asml *elem, t_ctrl *ctrl)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.j = ctrl->use;
	if (first_line == 0)
	{
		tab[pos.j++] = 0;
		tab[pos.j++] = 234;
		tab[pos.j++] = 131;
		tab[pos.j++] = 243;
	}
	while (elem->content[pos.i])
	{
		tab[pos.j] = elem->content[pos.i];
		pos.i++;
		pos.j++;
		ctrl->octet++;
	}
	if (first_line < 2)
	{
		tab[pos.j] = -1;
		pos.j++;
	}
	ctrl->use = pos.j;
	return (tab);
}

int		conv_comment(t_cpt *cpt, t_ctrl *ctrl, t_asml *elem)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	if ((pos.tab = (int*)malloc(sizeof(int) * (16 + 1))) == NULL)
		return (-1);
	while (pos.i < (COMMENT_LENGTH / 16) + 1)
	{
		print_zero(cpt->num, cpt->fd);
		ft_print_hex_fd(cpt->num, cpt->fd);
		ft_putstr_fd(": ", cpt->fd);
		pos.tab = ft_generate_tab(1, pos.tab, elem, ctrl);
 		print_char(pos.tab, 16, cpt->fd ,ctrl);
		sp_putchar(pos.tab, cpt->fd);
		ft_putchar_fd('\n', cpt->fd);
		cpt->num = cpt->num + 16;
		pos.i++;
	}
	free (pos.tab);
	if (pos.i == 129)
		return (1);
	return (0);
}
/*
int		conv_exec(t_cpt *cpt, t_asml *elem, char *line)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	if ((pos.tab = (int*)malloc(sizeof(int) * (16 + 1))) == NULL)
		return (-1);
	while (pos.i < (line != NULL))
	{
		if (cpt->oct >= COREWAR_EXEC_MAGIC)
			return (1);
		print_zero(cpt->num, cpt->fd);
		ft_print_hex_fd(cpt->num, cpt->fd);
		ft_putstr_fd(": ", cpt->fd);
		pos.tab = ft_generate_tab(pos.i, pos.tab, elem);
 		print_char(pos.tab, 16, cpt->fd);
		sp_putchar(pos.tab, cpt->fd);
		ft_putchar_fd('\n', cpt->fd);
		cpt->num = cpt->num + 16;
		pos.i++;
	}
	free (pos.tab);
	return (1);
}
*/
int		conv_name(t_cpt *cpt, t_ctrl *ctrl, t_asml *elem)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	if ((pos.tab = (int*)malloc(sizeof(int) * (16 + 1))) == NULL)
		return (-1);
	while (pos.i < (PROG_NAME_LENGTH / 16))
	{
		print_zero(cpt->num, cpt->fd);
		ft_print_hex_fd(cpt->num, cpt->fd);
		ft_putstr_fd(": ", cpt->fd);
		pos.tab = ft_generate_tab(pos.i, pos.tab, elem, ctrl);
 		print_char(pos.tab, 16, cpt->fd, ctrl);
		if (ctrl->octet == 128)
			return (1);
		sp_putchar(pos.tab, cpt->fd);
		ft_putchar_fd('\n', cpt->fd);
		cpt->num = cpt->num + 16;
		pos.i++;
	}
	free (pos.tab);
	if (pos.i == 8)
		return (1);
	return (0);
}
/*
int		file_conv(t_vsml *dup)
{
	t_cpt	cpt;
	t_ctrl	ctrl;
	t_asml	*tmp;

	ft_memset(&cpt, 0, sizeof(t_cpt));
	ft_memset(&ctrl, 0, sizeof(t_ctrl));
	cpt.fd = open("ex.cor", O_WRONLY|O_CREAT|O_APPEND, 0777);
	cpt.flag_name = 1;
	tmp = dup->fin;
	while (cpt.auth != 1)
	{
		if (cpt.flag_name == 1)
		{
			if (conv_name(&cpt, &ctrl, tmp))
			{
				cpt.flag_name = 0;
				cpt.flag_comm = 1;
				tmp = tmp->prev;
			}
		}
		if (cpt.flag_comm == 1)
		{
			ctrl.octet = 0;
			if (conv_comment(&cpt, &ctrl, tmp))
			{
				cpt.flag_comm = 0;
				cpt.flag_exec = 1;
				tmp = tmp->prev;
				printf("%d\n", ctrl.octet);
				break ;
			}
		}

		if (cpt.flag_exec == 1)
		{
			if (conv_exec(&cpt, tmp, tmp->content) == 1)
				cpt.auth = 1;
		}

		tmp = tmp->prev;
	}
	close(cpt.fd);
	return (0);
}
*/

int		generate_nc(int *tab, t_cpt *cpt)
{
	t_pos pos;
	t_mem mem;

	ft_memset(&mem, 0, sizeof(t_mem));
	ft_memset(&pos, 0, sizeof(t_pos));
	while (pos.i < 2)
	{
		pos.j = 0;
		while (pos.j < 16)
		{
			ft_print_hex_fd2(tab[pos.j], cpt->fd);
			mem.cpt = mem.cpt + ft_nbrlen_hexa(tab[pos.j]);
			if (tab[pos.j] <= 15)
				mem.cpt++;
			if (mem.cpt == 4)
			{
				write(cpt->fd, " ", 1);
				mem.cpt = 0;
			}
			pos.j++;
		}
		pos.i++;
	}
	return (0);
}

int		file_conv(t_vsml *dup)
{
	t_cpt	cpt;
	t_pos	pos;
	t_ctrl	ctrl;
	t_asml	*tmp;

	ft_memset(&cpt, 0, sizeof(t_cpt));
	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&ctrl, 0, sizeof(t_ctrl));
	cpt.fd = open("ex.cor", O_WRONLY|O_CREAT|O_APPEND, 0777);
	if ((pos.tab = (int*)malloc(sizeof(int) * (0xea83f3))) == NULL)
		return (-1);
	ft_raz(pos.tab, 0xea83f3, 0);
	tmp = dup->fin;
	while (tmp != NULL)
	{
		pos.tab = ft_generate_tab(pos.i, pos.tab, tmp, &ctrl);
		pos.i++;
		tmp = tmp->prev;
	}
	generate_nc(pos.tab, &cpt);
	return (0);
}
