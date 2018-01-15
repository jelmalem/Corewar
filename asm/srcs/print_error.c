/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:46:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/04 15:56:29 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		print_error(char *str)
{
	ft_printf("Error \"%s\"\n", str);
	return (-1);
}

int		parse_error(char *str, char *label)
{
	str = NULL;
	label = NULL;
	return (-1);
}
