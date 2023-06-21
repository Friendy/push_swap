/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/21 19:06:25 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_num(t_num *n, int use_ind)
{
	if (use_ind == 0)
		ft_printf("number: %i\n", n->num);
	if (use_ind == 1)
		ft_printf("%i ", n->ind);	
	else
		ft_printf("|%i: %i|", n->ind, n->num);
}

void	print_content(void *content)
{
	print_num(content, 1);
}

void	print_list(t_list *name)
{
	ft_lstiter(name, print_content);
	ft_printf("\n");
}
