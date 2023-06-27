/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:44 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 14:34:30 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define UP 1
# define DOWN 0
# define EXIT 2

typedef unsigned int	t_ind;

typedef struct s_num {
	int		num;
	t_ind	ind;
}	t_num;

typedef struct s_ops {
	t_ind	a_rots;
	t_ind	b_rots;
	int		direction_a;
	int		direction_b;
}	t_ops;

void	print_list(t_list *name);
void	print_content(void *content);
void	err_handler(void);
void	push(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack_a);
void	rotate(t_list **stack_a);
void	r_rotate(t_list **stack_a);
t_list	*lstpenultimate(t_list *lst);
void	operation(char *name, t_list **stack_a, t_list **stack_b);
void	indexate(t_list *stack);
int		getnum(t_num *n);
t_ind	getind(t_num *n);
t_ind	l_ind(t_list *lst);
int		gthan(t_list *node1, t_list *node2);
void	dupbreak(t_list *l, int d);
t_list	*find_min(t_list *node);
t_list	*find_limmin(t_list *node, int threshold);
int		lstgetnum(t_list *node);
t_ind	st_ind(t_list *stack, int ind);
void	dupcheck(t_list **stack);
void	find_dup(t_list *node);
t_list	*create_node(int n);
void	batch_o(char *name, t_list **stack_a, t_list **stack_b, int m);
int		getmin(int a, int b);
int		diff(int a, int b);
int		getmax(int a, int b);
t_list	*find_min_node(t_list *stack, t_ops *ops);
int		btwn(t_ind a, t_ind b, t_ind c);
int		check_order(t_list **stack, int flag);
void	move(t_list **stack_a, t_list **stack_b, t_ops *ops);
void	rot_back(t_list **stack_a, t_list **stack_b, t_ind size);
void	sort_top(t_list **st, t_list **stack_b);
void	getminops(t_list *stack_a, t_list *stack_b, t_ops *ops, t_ind size_a);
t_ind	set_ops(t_ops *ops, t_ind size_a, t_ind size_b);
t_ind	getb_rots(t_list *stack_b, t_ind ind, t_ops *ops, t_ind size_a);
void	struct_cpy(t_ops *src, t_ops *dst);
char	**join_arrs(char **arr1, char **arr2);
void	free_arr(char **arr);
int		strtoi(char *str, int *err_flag);
void	set_directions(t_ops *ops, int dir_a, int dir_b);
char	**argstoarr(int argc, char *argv[]);
void	set_opsa(t_ops *ops, t_ind size_a);
t_list	*find_max_node(t_list *stack, t_ops *ops);
void	get_apos1(t_list *pos, t_ind ind, t_ops *ops);
void	check_elmnt(char *p, char **arr1, char **arr2, char **arr3);
void	check_arr(char **arr1, char **arr2, char **arr3);
#endif