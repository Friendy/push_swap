/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batch_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 11:57:17 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//batch operations
void	batch_o(char *name, t_list **stack_a, t_list **stack_b, int m)
{
	int	i;

	i = 0;
	while (i <= m - 1)
	{
		operation(name, stack_a, stack_b);
		i++;
	}
}

//executing operations involving sync rotations
static void	sync_rots(t_list **stack_a, t_list **stack_b, t_ops *ops)
{
	t_ind	sync_rots;
	t_ind	rots;
	char	*name;

	sync_rots = getmin(ops->a_rots, ops->b_rots);
	rots = diff(ops->a_rots, ops->b_rots);
	if (ops->a_rots > ops->b_rots)
		name = "rra";
	else
		name = "rrb";
	if (ops->direction_a == UP)
	{
		batch_o("rr", stack_a, stack_b, sync_rots);
		batch_o((name + 1), stack_a, stack_b, rots);
	}
	else
	{
		batch_o("rrr", stack_a, stack_b, sync_rots);
		batch_o(name, stack_a, stack_b, rots);
	}
}

//executing a step of sorting
void	move(t_list **stack_a, t_list **stack_b, t_ops *ops)
{
	if (ops->direction_a == ops->direction_b)
		sync_rots(stack_a, stack_b, ops);
	else if (ops->direction_a == UP && ops->direction_b == DOWN)
	{
		batch_o("ra", stack_a, stack_b, ops->a_rots);
		batch_o("rrb", stack_a, stack_b, ops->b_rots);
	}
	else if (ops->direction_a == DOWN && ops->direction_b == UP)
	{
		batch_o("rra", stack_a, stack_b, ops->a_rots);
		batch_o("rb", stack_a, stack_b, ops->b_rots);
	}
	operation("pb", stack_a, stack_b);
}

//updating rotations
static void	update_rots(t_ops *ops, t_ind a_rots, t_ind b_rots)
{
	if (ops->direction_a == DOWN)
		ops->a_rots = a_rots;
	if (ops->direction_b == DOWN)
		ops->b_rots = b_rots;
}

//comparing rotations for 4 direction combinations
t_ind	set_ops(t_ops *ops, t_ind size_a, t_ind size_b)
{
	t_ind	total;
	t_ind	a_rrots;
	t_ind	b_rrots;

	b_rrots = size_b - ops->b_rots;
	a_rrots = size_a - ops->a_rots;
	if (getmax(ops->a_rots, ops->b_rots) < getmax(a_rrots, b_rrots))
		total = getmax(ops->a_rots, ops->b_rots);
	else
	{
		total = getmax(a_rrots, b_rrots);
		set_directions(ops, DOWN, DOWN);
	}
	if ((ops->a_rots + b_rrots) < total)
	{
		total = ops->a_rots + b_rrots;
		set_directions(ops, UP, DOWN);
	}
	if ((a_rrots + ops->b_rots) < total)
	{
		total = a_rrots + ops->b_rots;
		set_directions(ops, DOWN, UP);
	}
	update_rots(ops, a_rrots, b_rrots);
	return (total);
}
