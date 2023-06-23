/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/22 22:48:13 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstpenultimate(t_list *lst)
{
	if (lst != 0 && lst->next != 0)
	{
		while (lst->next->next != 0)
			lst = lst->next;
	}
	return (lst);
}

int	getnum(t_num *n)
{
	return (n->num);
}

t_ind	getind(t_num *n)
{
	return (n->ind);
}

t_ind	lstgetind(t_list *lst)
{
	return (getind(lst->content));
}

int	lstgetnum(t_list *node)
{
	return (getnum(node->content));
}

void	setind(t_num *n, t_ind ind)
{
	n->ind = ind;
}

void	contsetind(t_list *node, t_ind ind)
{
	setind(node->content, ind);
}

t_list	*find_min(t_list *node)
{
	t_list *next;
	t_list *cand;
	
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

t_list	*find_limmin(t_list *node, int threshold)
{
	t_list *next;
	t_list *cand;
	
	cand = NULL;
	next = node;
	while (next != NULL)
	{
		if (lstgetnum(next) > threshold)
		{
			if (cand == NULL || gthan(cand, next))
				cand = next;
		}
		next = next->next;
	}
	return (cand);
}

void	indexate(t_list *stack)
{
	t_list			*next;
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

t_ind st_ind(t_list *stack, int ind)
{
	int i;
	t_list *node;
	
	node = stack;
	i = 1;
	while (node->next != NULL && i <= ind)
	{
		if (i == ind)
			return (lstgetind(node));
		node = node->next;
		i++;
	}
	return (lstgetind(node));
}

int getmin(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int getmax(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int diff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}
