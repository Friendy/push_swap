/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/23 16:11:16 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_top(t_list **st, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*st);
	if ((st_ind(*st, 1) < st_ind(*st, 2) && st_ind(*st, 2) < st_ind(*st, 3)))
		exit(0); //!!!
	if (size >= 3)
	{
		if (st_ind(*st, 2) > st_ind(*st, 1))
			operation("rra", st, stack_b);
		else if (btwn(st_ind(*st, 2), st_ind(*st, 3), st_ind(*st, 1)))
			operation("ra", st, stack_b);
	}	
	if (st_ind(*st, 1) > st_ind(*st, 2))
		operation("sa", st, stack_b);
	if (size >= 3 && st_ind(*st, 2) > st_ind(*st, 3))
		operation("rra", st, stack_b);
}

t_list *create_stack(int argc, char *argv[])
{
	t_list	*stack;
	t_list	*elmnt;
	char	**nums;
	int		i;

	if (argc < 2 || argv[1] == NULL)
		err_handler();
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = argv + 1;
	stack = create_node(ft_atoi(nums[0]));
	i = 1;
	while (nums[i] != NULL)
	{
		elmnt = create_node(ft_atoi(nums[i]));
		ft_lstadd_back(&stack, elmnt);
		i++;
	}
	return (stack);
}

//sets ops and returns total ops, take into account last elements
t_ind getb_rots(t_list *stack_b, t_ind ind, t_ops *ops, t_ind size_a)
{
	//checking if b starts with largest
	t_ind size_b;
	t_ind min_b;
	t_ind max_b;
	t_list  *b_pos;
	t_list  *b_prev;
	t_list  *max_node;
	t_list  *min_node;
	//t_ops temp_ops;
	
	//printf("arots%i\n", ops->a_rots);
	ops->b_rots = 0;
	size_b = ft_lstsize(stack_b);
	b_pos = stack_b;
	b_prev = ft_lstlast(stack_b);
	ops->direction_b = 1;
	ops->direction_a = 1;
	if (lstgetind(b_pos) > lstgetind(b_prev)) //if stack_b starts with max
	{
		while (b_pos != NULL && ind < lstgetind(b_pos))
		{
			b_pos = b_pos->next;
			ops->b_rots++;
		}
	}
	else
	{
		min_node = find_min_node(stack_b, ops); // ops contain min now
		max_node = min_node->next;
		max_b = lstgetind(max_node);
		min_b = lstgetind(min_node);
		if (ind < min_b  || ind > max_b) //we put max_node on top
		{
			ops->b_rots++;//
			
		}
		else if (ind > lstgetind(b_prev))//we start from max
		{
			b_pos = max_node;
			ops->b_rots++;
			while (b_pos != NULL && ind < lstgetind(b_pos))
			{
				b_pos = b_pos->next;
				ops->b_rots++;
			}
		}
		else //we start from start
		{
			ops->b_rots = 0;
			while (lstgetind(b_pos) > min_b && ind < lstgetind(b_pos))
			{
				b_pos = b_pos->next;
				ops->b_rots++;
			}
		}
	}
	//we calculated b_rots
	//ops->b_rrots = size_b - ops->b_rots;
	//now we can set directions and
	//set_directions(ops, size_a, size_b);
	return (set_directions(ops, size_a, size_b));
}

//changes ops and direction for a, ops for a should be initialized

void struct_cpy(t_ops *src, t_ops *dst)
{
	dst->a_rots = src->a_rots;
	dst->b_rots = src->b_rots;
	//dst->a_rrots = src->a_rrots;
	//dst->b_rrots = src->b_rrots;
	dst->direction_a = src->direction_a;
	dst->direction_b = src->direction_b;
}
//we take each number from stack_a and calculate its cost and then get minimum
t_ops *getminops(t_list *stack_a, t_list *stack_b)
{
	t_list  *node;
	t_ind c;
	t_ops *ops;
	t_ops *temp;
	t_ind size_a;
	int total;
	int total_temp;
	
	ops = malloc(sizeof(int) * 4);
	temp = malloc(sizeof(int) * 4);
	size_a = ft_lstsize(stack_a);
	
	//ops->direction_a = 1;
	//ops->direction_b = 1;
	node = stack_a;
	c = 0;
	ops->a_rots = c;
	//ops->a_rrots = size_a;
	//printf("size_a%i\n", size_a);
	total = getb_rots(stack_b,  lstgetind(node), ops, size_a);//direction is set
	//total = total_ops(stack_b, node, size_a, ops); //total for the first number in stack a
	//printf("total1%i\n", total);
	//exit(0);
	while (node != NULL && node->next != NULL)
	{
		c++;
		//printf("node%p\n", node);
		node = node->next;
		
		//finds corrrect ops in b
		//getb_rots(stack_b, lstgetind(node), &ops);
		//sets direction and min ops
		temp->a_rots = c;//rotations till this node is first
		//temp->a_rrots = size_a - c;
		//if (c == 30)
		//	printf("node%i rrotsa%i \n", lstgetind(node), temp->a_rrots);
		total_temp = getb_rots(stack_b,  lstgetind(node), temp, size_a);
		//printf("totaltemp%i\n", total_temp);
		//printf("totalfor cmpson%i\n", total);
		//total_temp = total_ops(stack_b, node, size_a, temp);//total for the next number
		//printf("totalnext%i\n", total_temp);
		if (total_temp < total)
		{		
			total = total_temp;
			struct_cpy(temp, ops);
		}
	}
	//printf("totalops%i\n", total);
	return (ops);
}

int	main(int argc, char *argv[])
{
	t_list  *stack_a;
	t_list  *stack_b;
	t_ops *ops;
	t_ind size;

	stack_b = NULL;
	stack_a = create_stack(argc, argv);
	dupcheck(&stack_a);
	size = ft_lstsize(stack_a);
	indexate(stack_a);
	
	if (check_order(stack_a) == 1)
	//printf("order%i\n", check_order(stack_a));
		exit(0);
	if (size <= 3)
	{
		//printf("size%i\n", size);
		sort_top(&stack_a, &stack_b);
		//print_list(stack_a);
		//printf("count%i\n", count);
			ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
	}
		
	//first division
	operation("pb", &stack_a, &stack_b);
	//if (size >= 5)
		operation("pb", &stack_a, &stack_b);
	while ((stack_a != 0))
	{
		ops = getminops(stack_a, stack_b);//get minimum ops considering both stacks
		//print_list(stack_a);
		//print_list(stack_b);
		//executing operations
		move(&stack_a, &stack_b, ops);
	}
	rot_back(&stack_a, &stack_b);
	//printf("r%i\n", ops->b_rots);
	//printf("s%i\n", size);
	//print_list(stack_a);
	//print_list(stack_b);
//exit(0);
	
	//printf("count%i\n", count);
	//print_list(stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
