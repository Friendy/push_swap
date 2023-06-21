/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/18 22:51:36 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	mult(char *name, t_list **stack_a, t_list **stack_b, int *count, int m)
{
	int i;
	
	i = 0;
	while (i <= m - 1)
	{
		operation(name, stack_a, stack_b, count);
		i++;
	}
}
