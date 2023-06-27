/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 11:50:10 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_apos(t_list *pos, t_ind ind, t_ops *ops, t_ind max_a)
{
	while ((l_ind(pos) < max_a) && ind > l_ind(pos))
	{
		pos = pos->next;
		ops->a_rots++;
	}
}

void	get_apos1(t_list *pos, t_ind ind, t_ops *ops)
{
	while (pos != NULL && ind > l_ind(pos))
	{
		pos = pos->next;
		ops->a_rots++;
	}
}

void	geta_rots(t_list *stack_a, t_ind ind, t_ops *ops, t_ind size_a)
{
	t_ind	min_a;
	t_list	*max_node;
	t_list	*last_node;

	ops->a_rots = 0;
	last_node = ft_lstlast(stack_a);
	set_directions(ops, UP, UP);
	if (l_ind(stack_a) < l_ind(last_node))
		get_apos1(stack_a, ind, ops);
	else
	{
		max_node = find_max_node(stack_a, ops);
		min_a = l_ind(max_node);
		ops->a_rots++;
		if (ind < l_ind(last_node) && ind > l_ind(max_node->next))
			get_apos(max_node->next, ind, ops, min_a);
		else if (ind < l_ind(max_node) && ind > l_ind(last_node))
		{
			ops->a_rots = 0;
			get_apos(stack_a, ind, ops, min_a);
		}
	}
	set_opsa(ops, size_a);
}

void	rot_back(t_list **stack_a, t_list **stack_b, t_ind size)
{
	t_ops	ops;
	t_list	*node_a;
	t_ind	i;

	node_a = *stack_a;
	i = 0;
	while (*stack_b != 0)
	{
		geta_rots(*stack_a, l_ind(*stack_b), &ops, ft_lstsize(*stack_a));
		if (ops.direction_a == UP)
			batch_o("ra", stack_a, stack_b, ops.a_rots);
		else if (ops.direction_a == DOWN)
			batch_o("rra", stack_a, stack_b, ops.a_rots);
		operation("pa", stack_a, stack_b);
	}
	node_a = *stack_a;
	while (node_a != NULL && l_ind(node_a) != 0)
	{
		node_a = node_a->next;
		i++;
	}
	if (size - i < i)
		batch_o("rra", stack_a, stack_b, size - i);
	else
		batch_o("ra", stack_a, stack_b, i);
}

void	set_opsa(t_ops *ops, t_ind size_a)
{
	t_ind	a_rrots;

	a_rrots = size_a - ops->a_rots;
	if (a_rrots < ops->a_rots)
	{
		ops->direction_a = 0;
		ops->a_rots = a_rrots;
	}
}
