/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/23 16:02:13 by mrubina          ###   ########.fr       */
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
		mult("rrr", stack_a, stack_b, getmin(ops->a_rots, ops->b_rots));
		if (ops->a_rots > ops->b_rots)
			mult("rra", stack_a, stack_b, diff(ops->a_rots, ops->b_rots));
		else if (ops->b_rots > ops->a_rots)
			mult("rrb", stack_a, stack_b, diff(ops->a_rots, ops->b_rots));
	}
	else if (ops->direction_a == 1 && ops->direction_b == 0)
	{
		mult("ra", stack_a, stack_b, ops->a_rots);
		mult("rrb", stack_a, stack_b, ops->b_rots);
	}
	else if (ops->direction_a == 0 && ops->direction_b == 1)
	{
		mult("rra", stack_a, stack_b, ops->a_rots);
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
	t_ind b_rrots;

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
	b_rrots = size - ops.b_rots;
	//rotaion
	if (b_rrots < ops.b_rots)
		mult("rrb", stack_a, stack_b, b_rrots - 1);
	else
		mult("rb", stack_a, stack_b, ops.b_rots + 1);
	mult("pa", stack_a, stack_b, size);
}

t_ind set_directions(t_ops *ops, t_ind size_a, t_ind size_b)
{
	t_ind total;
	t_ind a_rrots;
	t_ind b_rrots;
	
	// at first we calculate oposite rotations
	b_rrots = size_b - ops->b_rots;
	a_rrots = size_a - ops->a_rots;
	//first we compare 2 sync variants
	if (getmax(ops->a_rots, ops->b_rots) < getmax(a_rrots, b_rrots))
		total = getmax(ops->a_rots, ops->b_rots);
	else
	{
		total = getmax(a_rrots, b_rrots);
		ops->direction_a = 0;
		ops->direction_b = 0;
	}
	//printf("cand1%i\n", total);
	//compare prev variant with first non snc

	if ((ops->a_rots + b_rrots) < total)
	{
		total = ops->a_rots + b_rrots;
		ops->direction_a = 1;
		ops->direction_b = 0;
	}
	//printf("cand2%i\n", total);
	if ((a_rrots + ops->b_rots) < total)
	{
		total = a_rrots + ops->b_rots;
		ops->direction_a = 0;
		ops->direction_b = 1;
	}
	//printf("last choice from set dir%i\n", total);
	//directions are set now setting rotations
	if (ops->direction_a == 0)
		ops->a_rots = a_rrots;
	if (ops->direction_b == 0)
		ops->b_rots = b_rrots;
	return (total);
}

/* int total_ops(t_list *stack_b, t_list *node, t_ind size_a, t_ops *ops)
{
	t_ind total;
	t_ind a_rrots;
	//t_ind b_rrots;
	//for ops containing only 4 members
	//for now it contains only for a
	//int a_rrots;
	//checking initialization for rotations
	a_rrots = size_a - ops->a_rots;
	//getb_rots(stack_b, lstgetind(node), ops, );
	if (getmax(ops->a_rots, ops->b_rots) < getmax(ops->a_rrots, ops->b_rrots))
	{
		total = getmax(ops->a_rots, ops->b_rots);
	}
	else
	{
		total = getmax(ops->a_rrots, ops->b_rrots);
		ops->direction_a = 0;
		ops->direction_b = 0;
	}
	if ((ops->a_rots + ops->b_rrots) < total)
	{
		total = ops->a_rots + ops->b_rrots;
		ops->direction_a = 1;
		ops->direction_b = 0;
	}
	if ((ops->a_rrots + ops->b_rots) < total)
	{
		total = ops->a_rrots + ops->b_rots;
		ops->direction_a = 0;
		ops->direction_b = 1;
	} 
	//total = ops->a_rots + ops->b_rots;
	return(total);
} */