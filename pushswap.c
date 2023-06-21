/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/21 18:36:33 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



int	checkorder(t_list **stack)
{
	t_list *node;
	int c;
	int	d;
	c = 0;
	node = *stack;
	while(node->next != NULL)
	{
		d = lstgetind(node->next) - lstgetind(node);
		if (d == 1)
			c++;
		node = node->next;
	}
	return (c);
}

int	checkorder1(t_list **stack)
{
	t_list *node;
	int c;
	int	d;
	c = 0;
	node = *stack;
	while(node->next != NULL)
	{
		d = lstgetind(node) - lstgetind(node->next);
		if (d == 1)
			c++;
		node = node->next;
	}
	return (c);
}

int	dir(t_list **stack, unsigned int size)
{
	t_list *node;
	int c;
	int	d;
	
	c = 0;
	node = *stack;
	while(node->next != NULL)
	{
		if (lstgetind(node) < size / 2)
			//print_content(node->content);
		d = lstgetind(node->next) - lstgetind(node);
		if (d == 1)
			c++;
		node = node->next;
	}
	return (c);
}

/* void sort_top(t_list **stack_a, t_list **stack_b, int *count)
{
	int	size;
	size = ft_lstsize(*stack_a);
	
	if (size >= 2 && lstgetind(*stack_a) == lstgetind((*stack_a)->next) + 1)
		operation("sa", stack_a, stack_b, count);
	if (size == 3 && lstgetind(*stack_a) == lstgetind(ft_lstlast(*stack_a)) + 1)
		operation("ra", stack_a, stack_b, count);
	if (size == 3 && lstgetind(*stack_a) == lstgetind(ft_lstlast(*stack_a)) - 1)
		operation("ra", stack_a, stack_b, count);	
} */



void sort_top(t_list **stack_a, t_list **stack_b, int *count)
{
	int	size;
	//int ind3
	size = ft_lstsize(*stack_a);
	
	
	if (size >= 3 && (stind(*stack_a, 1) == stind(*stack_a, 2) - 2 || stind(*stack_a, 1) == stind(*stack_a, 2) + 2))
		operation("ra", stack_a, stack_b, count);
	if (size >= 2 && stind(*stack_a, 1) == stind(*stack_a, 2) + 1)
		operation("sa", stack_a, stack_b, count);
	if (size == 3 && stind(*stack_a, 2) == stind(*stack_a, 3) + 2)
		operation("rra", stack_a, stack_b, count);	
}

/* void sort1(t_list **stack_a, t_list **stack_b, int *count)
{
	int	size;
	//int ind3
	size = ft_lstsize(*stack_a);
	
	
	if ((stind(*stack_a, 1) > stind(*stack_a, 2) && ))
		operation("sa", stack_a, stack_b, count);
	if (size - stind(*stack_a, 1) < size / 2)
		operation("ra", stack_a, stack_b, count);
	else
		operation("pb", stack_a, stack_b, count);
	
} */

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

t_list *find_min_node(t_list  *stack, t_ops *ops)
{
	t_list *node;
	unsigned int i;
	
	node = stack;
	//printf("b starts with%i\n", lstgetind(node));
	i = 0;
	while (node != NULL && node->next != NULL && lstgetind(node) > lstgetind(node->next))
	{
		i++;	
		node = node->next;	
	}
	//printf("pos%i\n", lstgetind(node->next));
	ops->b_rots = i;
	return (node);
}

//sets ops and direction for b, take into account last elements
/* void getb_rots(t_list *stack_b, unsigned int ind, t_ops *ops)
{
	//checking if b starts with largest
	unsigned int size_b;
	t_list  *b_pos;
	t_list  *b_prev;
	
	ops->b_rots = 0;
	size_b = ft_lstsize(stack_b);
	b_pos = stack_b;
	b_prev = ft_lstlast(stack_b);
	ops->direction_b = 1;
	ops->direction_a = 1;
	if (lstgetind(b_pos) > lstgetind(b_prev))
	{
		while (b_pos != NULL && ind < lstgetind(b_pos))
		{
			b_pos = b_pos->next;
			ops->b_rots++;
		}
	}
	else
	{
		while (b_pos != NULL && !(ind > lstgetind(b_pos) && ind < lstgetind(b_prev)))
		{
			b_prev = b_pos;
			b_pos = b_pos->next;
			//printf("bpos%p\n", b_pos);
			ops->b_rots++;
		}
		if (ind == 0)
		{
			printf("bpos%p\n", b_pos);
			printf("0pos%i\n", lstgetind(b_prev));
			printf("rots%i\n", ops->b_rots);
		}
		if (b_pos == NULL && ind > lstgetind(b_prev))
		{
			//printf("bpos%p\n", b_pos);
			//printf("i%i\n", ind);
			b_pos = find_mid(stack_b, ops);
			//ops->b_rots++;
			//printf("pos%i\n", lstgetind(b_pos));
		}
		else if (b_pos == NULL && ind < lstgetind(b_prev))
		{
			//printf("bpos%p\n", b_pos);
			//printf("i%i\n", ind);
			b_pos = find_mid(stack_b, ops);
			//ops->b_rots++;
			//printf("pos%i\n", lstgetind(b_pos));
		}
		
	}	

	//printf("tt%u\n", size_b);
 	if (size_b - ops->b_rots < ops->b_rots)
	{
		ops->b_rrots = size_b - ops->b_rots;
		ops->direction_b = 0;
	} 
	ops->b_rrots = size_b - ops->b_rots;
	if (ind == 11)
	{
		//printf("pos%i\n", lstgetind(b_pos));
		//printf("ops%i\n", ops->b_rots);
		//printf("ops%i\n", ops->b_rrots);
	}
} */

void getb_rots(t_list *stack_b, unsigned int ind, t_ops *ops)
{
	//checking if b starts with largest
	unsigned int size_b;
	unsigned int min_b;
	unsigned int max_b;
	t_list  *b_pos;
	t_list  *b_prev;
	t_list  *max_node;
	t_list  *min_node;
	//t_ops temp_ops;
	
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
	/* 	if (ind == 32)
		{
			printf("32minb%i\n", min_b);
			printf("32minb%i\n", max_b);
			printf("32firstb%i\n", lstgetind(b_pos));
			printf("32prevb%i\n", lstgetind(b_prev));
		} */
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
			/* 	if (ind == 32)
				{
					printf("32min%i\n", min_b);
					//printf("32min%i\n", min_b);
					printf("32br%i\n", ops->b_rots);
					printf("32ar%i\n", ops->a_rots);
					printf("32bpos%i\n", lstgetind(b_pos));
				} */
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

	//printf("tt%u\n", size_b);
/* 	if (size_b - ops->b_rots < ops->b_rots)
	{
		ops->b_rrots = size_b - ops->b_rots;
		ops->direction_b = 0;
	} */
	ops->b_rrots = size_b - ops->b_rots;
/* 	if (ind == 32)
	{
		//printf("pos%i\n", lstgetind(b_pos));
		printf("ops%i\n", ops->b_rots);
		printf("ops%i\n", ops->b_rrots);
	} */
}

//changes ops and direction for a, ops for a should be initialized
int total_ops(t_list *stack_b, t_list *node, unsigned int size_a, t_ops *ops)
{
	unsigned int total;

	
	//int a_rrots;
	//checking initialization for rotations
	ops->a_rrots = size_a - ops->a_rots;
	getb_rots(stack_b, lstgetind(node), ops);
	
		if (lstgetind(node) == 32)
		{
		//printf("32a_rots %i\n", ops->a_rots);
		//printf("0a_rrots %i\n", ops->a_rrots);
		//printf("0b_rots %i\n", ops->b_rots);
		//printf("32b_rrots %i\n", ops->b_rrots);
		//printf("total%i\n", total);
		
		}
	//printf("next%u\n", size_a);
	/* if (size_a - ops->a_rots < ops->a_rots)
	{
		ops->a_rots = size_a - ops->a_rots;
		ops->direction_a = 0;
	} */
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
}

void struct_cpy(t_ops *src, t_ops *dst)
{
	dst->a_rots = src->a_rots;
	
	//printf("b_rrots %i\n", ops->b_rrots);
	dst->b_rots = src->b_rots;
	//printf("checksb_rots %i\n", src->b_rots);
	//printf("checkdb_rots %i\n", dst->b_rots);
	dst->a_rrots = src->a_rrots;
	dst->b_rrots = src->b_rrots;
	dst->direction_a = src->direction_a;
	dst->direction_b = src->direction_b;
}
//we take each number from stack_a and calculate its cost and then get minimum
t_ops *getminops(t_list *stack_a, t_list *stack_b)
{
	t_list  *node;
	t_list  *b_pos;
	unsigned int c;
	t_ops *ops;
	t_ops *temp;
	unsigned int size_a;
	int total;
	int total_temp;
	//unsigned int size_b;
	ops = malloc(sizeof(int) * 6);
	temp = malloc(sizeof(int) * 6);
	size_a = ft_lstsize(stack_a);
	//size_b = ft_lstsize(stack_b);
	
	ops->direction_a = 1;
	ops->direction_b = 1;
	node = stack_a;
	b_pos = stack_b;
	c = 0;
	ops->a_rots = c;
	ops->a_rrots = size_a;
	//printf("size_a%i\n", size_a);
	total = total_ops(stack_b, node, size_a, ops); //total for the first number in stack a
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
		temp->a_rrots = size_a - c;
		//if (c == 30)
		//	printf("node%i rrotsa%i \n", lstgetind(node), temp->a_rrots);
		total_temp = total_ops(stack_b, node, size_a, temp);//total for the next number
		if (lstgetind(stack_a) == 47)
		{
			//printf("fromgm0a_rrots %i\n", temp->a_rrots);
			//printf("0b_rrots %i\n", temp->b_rrots);	
			//printf("ind %i\n", lstgetind(node));
			//printf("total %i\n", total_temp);
			//printf("prev total %i\n", total);	
			
		}
		//printf("totalnext%i\n", total_temp);
		if (total_temp < total)
		{
			//printf("looptotalnext%i\n", total_temp);
			
			total = total_temp;
			//printf("looptotal%i\n", total);
			struct_cpy(temp, ops);
		}
	}
	//printf("top%i\n", ops->direction_a);
	//printf("top%i\n", ops->direction_b);
	//printf("top%i\n", ops->a_rots);
	//printf("top%i\n", ops->a_rots);
	//free(temp);
	//printf("lasttotal %i\n", total);
	return (ops);
}

int	main(int argc, char *argv[])
{
	t_list  *stack_a;
	t_list  *stack_b;
	t_ops *ops;
	int i;
	int count;
	unsigned int size;

	count = 0;
	stack_b = NULL;
	i = 0;
	stack_a = create_stack(argc, argv);
	dupcheck(&stack_a);
	size = ft_lstsize(stack_a);

	indexate(stack_a);
	//first division
	operation("pb", &stack_a, &stack_b, &count);
	operation("pb", &stack_a, &stack_b, &count);
	while ((stack_a->next->next != 0))
	{
		ops = getminops(stack_a, stack_b);//get minimum ops considering both stacks

		//executing operations
		if (ops->direction_a == 1 && ops->direction_b == 1)
		{
			mult("rr", &stack_a, &stack_b, &count, getmin(ops->a_rots, ops->b_rots));
			if (ops->a_rots > ops->b_rots)
				mult("ra", &stack_a, &stack_b, &count, diff(ops->a_rots, ops->b_rots));
			else if (ops->b_rots > ops->a_rots)
				mult("rb", &stack_a, &stack_b, &count, diff(ops->a_rots, ops->b_rots));
		}
		else if (ops->direction_a == 0 && ops->direction_b == 0)
		{
			mult("rrr", &stack_a, &stack_b, &count, getmin(ops->a_rrots, ops->b_rrots));
			if (ops->a_rrots > ops->b_rrots)
				mult("rra", &stack_a, &stack_b, &count, diff(ops->a_rrots, ops->b_rrots));
			else if (ops->b_rrots > ops->a_rrots)
				mult("rrb", &stack_a, &stack_b, &count, diff(ops->a_rrots, ops->b_rrots));
		}
		else if (ops->direction_a == 1 && ops->direction_b == 0)
		{
			mult("ra", &stack_a, &stack_b, &count, ops->a_rots);
			mult("rrb", &stack_a, &stack_b, &count, ops->b_rrots);
		}
		else if (ops->direction_a == 0 && ops->direction_b == 1)
		{
			mult("rra", &stack_a, &stack_b, &count, ops->a_rrots);
			mult("rb", &stack_a, &stack_b, &count, ops->b_rots);
		}
		//print_list(stack_a);
		//print_list(stack_b);
		operation("pb", &stack_a, &stack_b, &count);
		//print_list(stack_a);
		//print_list(stack_b);
	}
	print_list(stack_a);
	print_list(stack_b);
//exit(0);
	
	//printf("count%i|\n", count);
	//print_list(stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
