/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/22 22:48:13 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gthan(t_list *node1, t_list *node2)
{
	return (getnum(node1->content) > getnum(node2->content));
}

int	ind_gthan(t_list *node1, t_list *node2)
{
	return (getind(node1->content) > getind(node2->content));
}

void contequal(t_list *l, int d)
{
	if (getnum(l->content) == d)
		err_handler();
}

int isequal(t_list *node1, t_list *node2)
{
	return (getnum(node1->content) == getnum(node2->content));
}

//when we swap single swap and double swap
//&& st_ind(st, 1) - st_ind(st, 2) < size / 10)
int swapcond(t_list *st, t_ind size)
{

	if (st->next != NULL && st_ind(st, 1) > st_ind(st, 2) && st_ind(st, 1) - st_ind(st, 2) != size / 2 - 1)
	{
			//if (st_ind(st, 3) > st_ind(st, 4) && st_ind(st, 4) > st_ind(st, 1))
			//	return (2);
			//else 
		return (1);
	}
	else 
		return (0);
}

int swbcond(t_list *st, t_ind size)
{

	if (st != NULL && st->next != NULL && st_ind(st, 2) > st_ind(st, 1) && st_ind(st, 2) - st_ind(st, 1) != size / 2 - 1)
	{
		return (1);
	}
	else 
		return (0);
}


/* int pbcond(t_list *st_a, t_list *st_b, t_ind size)
{
	if (st_ind(st_a, 1) < size / 2)
	{
		if (st_b != NULL && st_b->next != NULL && st_ind(st_a, 1) < st_ind(st_b, 1))
			return (2);// swap needed after pushing
		else
			return (1);//push needed
	}
	else
		return (0);
} */

int pbcond(t_list *st_a, t_ind size)
{
	if (st_ind(st_a, 1) < size / 2)
		return (1);//push needed
	else
		return (0);
}

int btwn(t_ind a, t_ind b, t_ind c)
{
	return (b > a && b < c);
}


/* int rocond(t_list *st, int size)
{
	if ((st_ind(st, 1) > st_ind(st, 2) && st_ind(st, 1) - st_ind(st, 2) < size / 10))
		return (1);
} */