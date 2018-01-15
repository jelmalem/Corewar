/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:17:21 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/09 20:17:21 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		countchar(char *tab, char c)
{
	int x;
	int count;

	x = 0;
	count = 0;
	while (tab[x])
	{
		if (tab[x] == c)
			count++;
		x++;
	}
	return (count);
}