/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:02:30 by cfatrane          #+#    #+#             */
/*   Updated: 2017/05/10 18:41:51 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/libft.h"
# include "asm_struct.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_listlabel	t_listlabel;

struct						s_listlabel
{
	char					*label;
	t_listlabel				*next;
};

void	ft_list_push_back_inst(t_champ **champ, char *inst);
void	ft_list_remove_if_inst(t_champ **champ);
void	ft_list_clear_inst(t_champ **champ);

int		parse_inst(t_asm *env);
int		parse_inst_comment(t_asm *env);
int		parse_inst_name(t_asm *env);
int		parse_inst_label_chars(t_asm *env);

void	ft_free_env(t_asm *env);

int		print_error(char *str);

/*
** Parse_Conv
*/

int		parse_conv(char *str, t_vsml *dup);
int		parse_add(char *str, char *label);
int		parse_aff(char *str, char *label);
int		parse_and(char *str, char *label);
int		parse_fork(char *str, char *label);
int		parse_ld(char *str, char *label);
int		parse_ldi(char *str, char *label);
int		parse_live(char *str, char *label);
int		parse_lld(char *str, char *label);
int		parse_lldi(char *str, char *label);
int		parse_or(char *str, char *label);
int		parse_st(char *str, char *label);
int		parse_sti(char *str, char *label);
int		parse_sub(char *str, char *label);
int		parse_xor(char *str, char *label);
int		parse_zjmp(char *str, char *label);
int		parse_lfork(char *str, char *label);
char	*check_label_line(char *line);
int		first_char(char *line, int on);
int		empty_line(char *str);
int		check_command(char *str);
int		parse_reg(char **tab2, int pos);
int		parse_ind(char **tab2, int pos, char *label);
int		parse_dir(char **tab2, int pos, char *label);
int		countchar(char *tab, char c);
void	ft_free(char **tab);
char	*find_label(char *line);


// conversion
int		file_conv(t_vsml *dup);
int		ft_add_elm(t_vsml *lst, char *content, size_t content_size);
void	ft_init_lst(t_vsml *list);
void	sp_putchar(int *addr, int fd);
void	print_zero(int num, int fd);
int		ft_raz(int *tab, int size, int letter);
int		parse_error(char *str, char *label);

#endif
