/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 16:01:51 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* #!/bin/zsh
ARG=$(jot -r -s " " 100 10000000 99999999)
echo $ARG;
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l */
//-2147483648

t_list	*create_stack(int argc, char *argv[])
{
	t_list	*stack;
	t_list	*elmnt;
	char	**nums;
	int		i;

	if (argc < 2)
		exit(0);
	nums = argstoarr(argc, argv);
	stack = create_node(strtoi(nums[0], nums, NULL), nums, NULL);
	i = 1;
	while (nums[i] != NULL)
	{
		elmnt = create_node(strtoi(nums[i], nums, &stack), nums, &stack);
		ft_lstadd_back(&stack, elmnt);
		i++;
	}
	free_arr(nums);
	dupcheck(&stack);
	indexate(stack);
	return (stack);
}

//we find the node which we have to put on top
void	get_bpos(t_list *b_pos, t_ind ind, t_ops *ops, t_ind min_b)
{
	if (l_ind(b_pos) > min_b)
	{
		while (b_pos != NULL && ind < l_ind(b_pos))
		{
			b_pos = b_pos->next;
			ops->b_rots++;
		}
	}
	else
	{
		while ((l_ind(b_pos) > min_b) && ind < l_ind(b_pos))
		{
			b_pos = b_pos->next;
			ops->b_rots++;
		}
	}
}

/* we have a number from stack a 
we need to put it in stack b in correct position
this function calculates necessary rotations of b
*/
t_ind	getb_rots(t_list *stack_b, t_ind ind, t_ops *ops, t_ind size_a)
{
	t_ind	min_b;
	t_list	*min_node;
	t_list	*last_node;

	ops->b_rots = 0;
	last_node = ft_lstlast(stack_b);
	set_directions(ops, UP, UP);
	if (l_ind(stack_b) > l_ind(last_node))
		get_bpos(stack_b, ind, ops, l_ind(last_node));
	else
	{
		min_node = find_min_node(stack_b, ops);
		min_b = l_ind(min_node);
		ops->b_rots++;
		if (ind > l_ind(last_node) && ind < l_ind(min_node->next))
			get_bpos(min_node->next, ind, ops, l_ind(last_node));
		else if (ind < l_ind(last_node) && ind > min_b)
		{
			ops->b_rots = 0;
			get_bpos(stack_b, ind, ops, min_b);
		}
	}
	return (set_ops(ops, size_a, ft_lstsize(stack_b)));
}

/* calculates rotations for a step of sorting from a to b
and puts it into structure
we take each number from stack_a and calculate its cost 
and then get minimum 
that minimum will be used to make rotations accordingly
*/
void	getminops(t_list *stack_a, t_list *stack_b, t_ops *ops, t_ind size_a)
{
	t_list	*node;
	t_ind	depth;
	t_ops	*temp;
	int		total;
	int		total_temp;

	temp = malloc(sizeof(int) * 4);
	size_a = ft_lstsize(stack_a);
	node = stack_a;
	depth = 0;
	ops->a_rots = 0;
	total = getb_rots(stack_b, l_ind(stack_a), ops, size_a);
	while (node != NULL && node->next != NULL)
	{
		depth++;
		node = node->next;
		temp->a_rots = depth;
		total_temp = getb_rots(stack_b, l_ind(node), temp, size_a);
		if (total_temp < total)
		{		
			total = total_temp;
			struct_cpy(temp, ops);
		}
	}
	free(temp);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ops	ops;
	t_ind	size;

	stack_b = NULL;
	stack_a = create_stack(argc, argv);
	check_order(&stack_a, EXIT);
	size = ft_lstsize(stack_a);
	if (size > 3)
		operation("pb", &stack_a, &stack_b);
	if (size > 4)
		operation("pb", &stack_a, &stack_b);
	if (ft_lstsize(stack_a) <= 3)
		sort_top(&stack_a, &stack_b);
	while ((size > 5 && stack_a->next->next->next != 0))
	{
		getminops(stack_a, stack_b, &ops, ft_lstsize(stack_a));
		move(&stack_a, &stack_b, &ops);
	}
	sort_top(&stack_a, &stack_b);
	rot_back(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a, free);
	return (0);
}
