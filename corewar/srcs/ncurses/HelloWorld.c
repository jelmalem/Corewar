/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:45:00 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/03 17:45:22 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int main(void)
{
	initscr();              // Initialise la structure WINDOW et autres paramètres 
	printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
	refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
	getch();                // On attend que l'utilisateur appui sur une touche pour quitter
	endwin();               // Restaure les paramètres par défaut du terminal

	return 0;
}
