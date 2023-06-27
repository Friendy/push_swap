/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 11:08:09 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//gets index from num structure
t_ind	getind(t_num *n)
{
	return (n->ind);
}

//sets index for num structure
void	setind(t_num *n, t_ind ind)
{
	n->ind = ind;
}

//returns node with the smallest number
t_list	*find_min(t_list *node)
{
	t_list	*next;
	t_list	*cand;

	cand = node;
	next = node->next;
	while (next != NULL)
	{
		if (gthan(cand, next))
			cand = next;
		next = next->next;
	}
	return (cand);
}

//returns node with the smallest number above the threshold
t_list	*find_limmin(t_list *node, int threshold)
{
	t_list	*next;
	t_list	*cand;

	cand = NULL;
	next = node;
	while (next != NULL)
	{
		if (getnum(next->content) > threshold)
		{
			if (cand == NULL || gthan(cand, next))
				cand = next;
		}
		next = next->next;
	}
	return (cand);
}

//indexates stack
void	indexate(t_list *stack)
{
	t_list	*next;
	t_ind	ind;
	t_ind	size;

	ind = 0;
	size = ft_lstsize(stack);
	next = find_min(stack);
	setind(next->content, ind);
	while (ind < size - 1)
	{
		next = find_limmin(stack, getnum(next->content));
		ind++;
		setind(next->content, ind);
	}
}
