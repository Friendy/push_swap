/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/18 22:12:26 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
//&& stind(st, 1) - stind(st, 2) < size / 10)
int swapcond(t_list *st, unsigned int size)
{

	if (st->next != NULL && stind(st, 1) > stind(st, 2) && stind(st, 1) - stind(st, 2) != size / 2 - 1)
	{
			//if (stind(st, 3) > stind(st, 4) && stind(st, 4) > stind(st, 1))
			//	return (2);
			//else 
		return (1);
	}
	else 
		return (0);
}

int swbcond(t_list *st, unsigned int size)
{

	if (st != NULL && st->next != NULL && stind(st, 2) > stind(st, 1) && stind(st, 2) - stind(st, 1) != size / 2 - 1)
	{
		return (1);
	}
	else 
		return (0);
}


/* int pbcond(t_list *st_a, t_list *st_b, unsigned int size)
{
	if (stind(st_a, 1) < size / 2)
	{
		if (st_b != NULL && st_b->next != NULL && stind(st_a, 1) < stind(st_b, 1))
			return (2);// swap needed after pushing
		else
			return (1);//push needed
	}
	else
		return (0);
} */

int pbcond(t_list *st_a, unsigned int size)
{
	if (stind(st_a, 1) < size / 2)
		return (1);//push needed
	else
		return (0);
}




/* int rocond(t_list *st, int size)
{
	if ((stind(st, 1) > stind(st, 2) && stind(st, 1) - stind(st, 2) < size / 10))
		return (1);
} */