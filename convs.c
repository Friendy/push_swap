/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 15:53:30 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if a string is number(has only digits and a sign)
int	isnumber(char *str)
{
	char	*start;

	if (*str == '-' || *str == '+')
		start = str + 1;
	else
		start = str;
	while (ft_isdigit(*start))
		start++;
	if (*start != '\0')
		return (0);
	else
		return (1);
}

//converts string to integer and checks it		
int	strtoi(char *str, char **nums, t_list **stack)
{
	int		n;
	char	*check_str;

	if (str == NULL)
		exit_handler(nums, stack);
	n = ft_atoi(str);
	check_str = ft_itoa(n);
	if (!isnumber(str) || ft_strncmp(str, check_str, ft_strlen(str)) != 0)
		exit_handler(nums, stack);
	if (check_str != NULL)
		free(check_str);
	return (n);
}
