/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 12:25:53 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//comparisons

//compares numbers of nodes
int	gthan(t_list *node1, t_list *node2)
{
	return (getnum(node1->content) > getnum(node2->content));
}

//checks that the second arg is greater than the first
// and less than the third
int	btwn(t_ind a, t_ind b, t_ind c)
{
	return (b > a && b < c);
}

int	getmin(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	getmax(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	diff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}
