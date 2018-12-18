/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:38:11 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/18 17:08:05 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"

typedef struct	s_struct
{
	int	*pile_a;
	int size_a;
	int *pile_b;
	int size_b;
	int flag_visu;
}				t_struct;

int				get_next_line(int fd, char **line);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(char *str);
char			*ft_strnew(int size);
int				ft_atoi(const char *str);

void			swap_a(t_struct *node);
void			swap_b(t_struct *node);
void			rotate_a(t_struct *node);
void			rotate_b(t_struct *node);
void			push_on_a(t_struct *node);
void			push_on_b(t_struct *node);
void			rev_rotate_a(t_struct *node);
void			rev_rotate_b(t_struct *node);

int				*new_tab(int size);
int				call_instructions(char *line, t_struct *node);
int				check_duplicates(t_struct *node);
int				check_errors_atoi(int data, char *arg);
int				mk_piles_2args(t_struct *node, char **argv);
int				mk_piles(t_struct *node, int argc, char **argv);
void			print_piles(t_struct *node, FILE *file);

#endif
