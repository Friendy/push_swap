/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/23 02:05:52 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mult(char *name, t_list **stack_a, t_list **stack_b, int m)
{
	int i;
	
	i = 0;
	while (i <= m - 1)
	{
		operation(name, stack_a, stack_b);
		i++;
	}
}

void	move(t_list **stack_a, t_list **stack_b, t_ops *ops)
{
	if (ops->direction_a == 1 && ops->direction_b == 1)
	{
		mult("rr", stack_a, stack_b, getmin(ops->a_rots, ops->b_rots));
		if (ops->a_rots > ops->b_rots)
			mult("ra", stack_a, stack_b, diff(ops->a_rots, ops->b_rots));
		else if (ops->b_rots > ops->a_rots)
			mult("rb", stack_a, stack_b, diff(ops->a_rots, ops->b_rots));
	}
	else if (ops->direction_a == 0 && ops->direction_b == 0)
	{
		mult("rrr", stack_a, stack_b, getmin(ops->a_rrots, ops->b_rrots));
		if (ops->a_rrots > ops->b_rrots)
			mult("rra", stack_a, stack_b, diff(ops->a_rrots, ops->b_rrots));
		else if (ops->b_rrots > ops->a_rrots)
			mult("rrb", stack_a, stack_b, diff(ops->a_rrots, ops->b_rrots));
	}
	else if (ops->direction_a == 1 && ops->direction_b == 0)
	{
		mult("ra", stack_a, stack_b, ops->a_rots);
		mult("rrb", stack_a, stack_b, ops->b_rrots);
	}
	else if (ops->direction_a == 0 && ops->direction_b == 1)
	{
		mult("rra", stack_a, stack_b, ops->a_rrots);
		mult("rb", stack_a, stack_b, ops->b_rots);
	}
	operation("pb", stack_a, stack_b);
}

void rot_back(t_list **stack_a, t_list **stack_b)
{
	t_ind size;
	t_ops ops;
	t_list *node_a;
	t_list *node_b;

	node_b = *stack_b;
	node_a = *stack_a;
	//sorting 3 in a_stack
	//sort_top(stack_a, stack_b);
	//pushing b back and rotatin a accordingly
/* 	while (*stack_b != 0)
	{
		if (getlstind(node_b) < getlstind(node_a) && getlstind(node_b) > getlstind(ft_lstlast(node_a))
			mult("pa", stack_a, stack_b, size);
		else
		{
			if (getlstind(node_b) < getlstind(node_a->next) && getlstind(node_b) > getlstind(ft_lstlast(node_a))
			ops = getminops(stack_b, stack_a);
			move(&stack_a, &stack_b, ops);
			
		}
			
	} */
	//rotate b and push to a
	//lstgetind(find_min(&stack_b));
	// finding min and counting distance
	find_min_node(*stack_b, &ops);
	size = ft_lstsize(*stack_b);
	ops.b_rrots = size - ops.b_rots;
	//rotaion
	if (ops.b_rrots < ops.b_rots)
		mult("rrb", stack_a, stack_b, ops.b_rrots - 1);
	else
		mult("rb", stack_a, stack_b, ops.b_rots + 1);
	mult("pa", stack_a, stack_b, size);
}
