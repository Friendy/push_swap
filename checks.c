/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 15:15:23 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if a node has a duplicate among next nodes and breaks
void	find_dup(t_list *node, t_list **stack)
{
	t_list	*next;
	int		d;

	next = node->next;
	d = getnum(node->content);
	while (next != NULL)
	{
		dupbreak(next, d, stack);
		next = next->next;
	}
}

//checks if each node in the stack has duplicates
void	dupcheck(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node->next != NULL)
	{
		find_dup(node, stack);
		node = node->next;
	}
}

int	check_order(t_list **stack, int flag)
{
	t_list	*nd;

	nd = *stack;
	while (nd != NULL && nd->next != NULL && l_ind(nd) < l_ind(nd->next))
	{
		nd = nd->next;
	}
	if (nd->next == NULL && flag == EXIT)
	{
		ft_lstclear(stack, free);
		exit(0);
	}	
	else if (nd->next == NULL && flag != EXIT)
		return (1);
	else
		return (0);
}

//breaks program if there is a duplicate
void	dupbreak(t_list *l, int d, t_list **stack)
{
	if (getnum(l->content) == d)
	{
		ft_lstclear(stack, free);
		err_handler();
	}
}
