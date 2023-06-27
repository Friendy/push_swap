/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 10:57:34 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*next;
	t_list	*top;

	if (stack_b != NULL && *stack_b != NULL)
	{
		top = *stack_b;
		next = top->next;
		if (stack_a != NULL && *stack_a != NULL)
			ft_lstadd_front(stack_a, top);
		else if (*stack_a == NULL)
		{	
			*stack_a = top;
			top->next = NULL;
		}
		*stack_b = next;
	}
}

void	swap(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a != NULL)
	{
		first = *stack_a;
		if (first->next != 0)
		{
			second = first->next;
			first->next = second->next;
			second->next = first;
			*stack_a = second;
		}
	}
}

//shift up
void	rotate(t_list **stack_a)
{
	t_list	*top;
	t_list	*bottom;

	if (*stack_a != NULL)
	{
		top = *stack_a;
		bottom = ft_lstlast(top);
		if (bottom != top)
		{
			bottom->next = top;
			*stack_a = top->next;
			top->next = NULL;
		}
	}
}

//shift down
void	r_rotate(t_list **stack_a)
{
	t_list	*top;
	t_list	*new_last;

	if (*stack_a != NULL && ft_lstsize(*stack_a) > 1)
	{
		top = *stack_a;
		new_last = lstpenultimate(top);
		new_last->next->next = top;
		*stack_a = new_last->next;
		new_last->next = NULL;
	}
}

void	operation(char *name, t_list **stack_a, t_list **stack_b)
{
	if (name[0] == 'p' && name[1] == 'a')
		push(stack_a, stack_b);
	else if (name[0] == 'p' && name[1] == 'b')
		push(stack_b, stack_a);
	else if (name[0] == 's')
	{
		if (name[1] == 'a' || name[1] == 's')
			swap(stack_a);
		if (name[1] == 'b' || name[1] == 's')
			swap(stack_b);
	}
	else if (name[0] == 'r')
	{
		if (name[1] == 'a' || (name[1] == 'r' && name[2] == '\0'))
			rotate(stack_a);
		if (name[1] == 'b' || (name[1] == 'r' && name[2] == '\0'))
			rotate(stack_b);
		if (name[1] == 'r' && (name[2] == 'a' || name[2] == 'r'))
			r_rotate(stack_a);
		if (name[1] == 'r' && (name[2] == 'b' || name[2] == 'r'))
			r_rotate(stack_b);
	}
	ft_printf("%s\n", name);
}
