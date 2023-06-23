/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:44 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/20 19:44:36 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define INPUTERR 100
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define NO_THR 12
# define THR 13

typedef unsigned int t_ind;

typedef struct s_num {
	int 			num;
	t_ind	ind;
}	t_num;

typedef struct s_ops {
	t_ind a_rots;
	t_ind b_rots;
	t_ind a_rrots;
	t_ind b_rrots;
	int direction_a;
	int direction_b;
}	t_ops;



/* typedef struct s_run {
	int smallest1;
	int smallest2;
	int largest1;
	int largest2;
}	t_run */
void	print_list(t_list *name);
void	print_content(void *content);
//void	print_num(t_num *n);
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
t_ind	lstgetind(t_list *lst);
int		gthan(t_list *node1, t_list *node2);
void	contequal(t_list *l, int d);
int		isequal(t_list *node1, t_list *node2);
t_list	*find_min(t_list *node);
t_list	*find_limmin(t_list *node, int threshold);
int		lstgetnum(t_list *node);
int		ind_gthan(t_list *node1, t_list *node2);
t_ind st_ind(t_list *stack, int ind);
void	dupcheck(t_list **stack);
void find_dup(t_list *node);
t_list	*create_node(int n);
int swapcond(t_list *st, t_ind size);
//int pbcond(t_list *st_a, t_list *st_b, t_ind size);
int pbcond(t_list *st_a, t_ind size);
int swbcond(t_list *st, t_ind size);
void	mult(char *name, t_list **stack_a, t_list **stack_b, int m);
int getmin(int a, int b);
int diff(int a, int b);
int getmax(int a, int b);
t_list *find_min_node(t_list  *stack, t_ops *ops);
int btwn(t_ind a, t_ind b, t_ind c);
int check_order(t_list  *stack);
void move(t_list **stack_a, t_list **stack_b, t_ops *ops);
void rot_back(t_list **stack_a, t_list **stack_b);
void sort_top(t_list **st, t_list **stack_b);
t_ops *getminops(t_list *stack_a, t_list *stack_b);
#endif