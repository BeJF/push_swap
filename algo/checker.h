/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:38:11 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/20 17:32:39 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"

typedef struct	s_struct
{
	int		*pile_a;
	int		size_a;

	int		*pile_b;
	int		size_b;

	int		rotated;
	int		pushed;
	int		rest2sort;
	int		call;
	int		pivot_rotated;
}				t_struct;

void			algo_smalltab(t_struct *node, int data2sort);
void			algo3(t_struct *node);
void			algo4(t_struct *node);
void			algo5data(t_struct *node, int max, int data2sort);
void			cond_firstcall(t_struct *node, int max, int data2sort);
void			sort_on_a(t_struct *node, int data2sort);
void			sort_on_b(t_struct *node, int data2sort, int pivot_top);
void			first_sort(t_struct *node, int data2sort);
int				mk_piles(t_struct *node, int argc, char **argv);
int				mk_piles_2args(t_struct *node, char **argv);
int				check_duplicates(t_struct *node);
int				check_errors_atoi(int data, char *arg);

int				get_next_line(int fd, char **line);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				ft_strlen(const char *s);

void			swap_a(t_struct *node);
void			swap_b(t_struct *node);
void			rotate_a(t_struct *node);
void			rotate_b(t_struct *node);
void			push_on_a(t_struct *node);
void			push_on_b(t_struct *node);
void			rev_rotate_a(t_struct *node);
void			rev_rotate_b(t_struct *node);

int				pivot_selector(int *tab, int size, int top);
int				pivot_selector2(int *tab, int size, int top);
int				checkif_b_sorted(t_struct *node, int data2sort);
int				checkif_a_sorted(t_struct *node, int data2sort);

void			print_piles(t_struct *node);
int				*new_tab(int size);
int				get_max(int *tab, int data2sort);
int				get_max2(int *tab, int data2sort, int max);
int				get_min(int *tab, int data2sort);
void			set_nul(t_struct *node);

#endif
