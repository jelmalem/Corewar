/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:42:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/08 10:20:43 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(size_t nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex(nb / 16);
	ft_putchar(str[nb % 16]);
}

void	ft_print_hex_fd(size_t nb, int fd)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex_fd(nb / 16, fd);
	ft_putchar_fd(str[nb % 16], fd);
}

void	ft_print_hex_fd2(size_t nb, int fd)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex_fd(nb / 16, fd);
	if (nb <= 15)
	{
		ft_putchar_fd('0', fd);
		ft_putchar_fd(str[nb % 16], fd);
	}
	else
		ft_putchar_fd(str[nb % 16], fd);
}
