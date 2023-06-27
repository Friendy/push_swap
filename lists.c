/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 15:50:46 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creates node with a number
//creates num structure and uses it as content
t_list	*create_node(int n, char **nums, t_list **stack)
{
	t_num	*num;
	t_list	*node;

	num = malloc(2 * sizeof(int));
	if (num == NULL)
		exit_handler(nums, stack);
	num->num = n;
	node = ft_lstnew(num);
	return (node);
}

//returns node from the stack with the smallest index
t_list	*find_min_node(t_list *stack, t_ops *ops)
{
	t_list	*nd;
	t_ind	i;

	nd = stack;
	i = 0;
	while (nd != NULL && nd->next != NULL && l_ind(nd) > l_ind(nd->next))
	{
		i++;
		nd = nd->next;
	}
	ops->b_rots = i;
	return (nd);
}

t_list	*find_max_node(t_list *stack, t_ops *ops)
{
	t_list	*nd;
	t_ind	i;

	nd = stack;
	i = 0;
	while (nd != NULL && nd->next != NULL && l_ind(nd) < l_ind(nd->next))
	{
		i++;
		nd = nd->next;
	}
	ops->a_rots = i;
	return (nd);
}

//returns pointer to penultimate element in the list
t_list	*lstpenultimate(t_list *lst)
{
	if (lst != 0 && lst->next != 0)
	{
		while (lst->next->next != 0)
			lst = lst->next;
	}
	return (lst);
}

//returns index from content
t_ind	l_ind(t_list *node)
{
	return (getind(node->content));
}
