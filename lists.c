/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/16 20:44:47 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*create_node(int n)
{
	t_num	*num;
	t_list	*node;
	
	num = malloc(2*sizeof(int));
	num->num = n;
	node = ft_lstnew(num);
	return (node);	
}

/* void del_num(t_num *n)
{
	
} */

void find_dup(t_list *node)
{
	t_list *next;
	int d;

	next = node->next;
	d = getnum(node->content);
	while (next != NULL)
	{
		contequal(next, d);
		next = next->next;
	}
}

void	dupcheck(t_list **stack)
{
	t_list *node;

	node = *stack;
	while(node->next != NULL)
	{
		find_dup(node);
		node = node->next;
	}
}

