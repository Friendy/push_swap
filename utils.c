/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 13:37:58 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//gets number from num structure
int	getnum(t_num *n)
{
	return (n->num);
}

/* finds a node in the stack with a certain position starting from 1
and returns its num index*/
t_ind	st_ind(t_list *stack, int ind)
{
	int		i;
	t_list	*node;

	node = stack;
	i = 1;
	while (node->next != NULL && i <= ind)
	{
		if (i == ind)
			return (l_ind(node));
		node = node->next;
		i++;
	}
	return (l_ind(node));
}

void	struct_cpy(t_ops *src, t_ops *dst)
{
	dst->a_rots = src->a_rots;
	dst->b_rots = src->b_rots;
	dst->direction_a = src->direction_a;
	dst->direction_b = src->direction_b;
}

//setting directions in strucure
void	set_directions(t_ops *ops, int dir_a, int dir_b)
{
	ops->direction_a = dir_a;
	ops->direction_b = dir_b;
}

//sorts 2 or 3 nodes on top of stack a
void	sort_top(t_list **st, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*st);
	if (check_order(st, 0) == 0)
	{
		if (size >= 3)
		{
			if (st_ind(*st, 2) > st_ind(*st, 1))
				operation("rra", st, stack_b);
			else if (btwn(st_ind(*st, 2), st_ind(*st, 3), st_ind(*st, 1)))
				operation("ra", st, stack_b);
		}	
		if (st_ind(*st, 1) > st_ind(*st, 2))
			operation("sa", st, stack_b);
		if (size >= 3 && st_ind(*st, 2) > st_ind(*st, 3))
			operation("rra", st, stack_b);
	}
}
