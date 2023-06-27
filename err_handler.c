/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:37:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 16:51:59 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	check_elmnt(char *p, char **arr1, char **arr2, char **arr3)
{
	if (p == NULL)
	{
		free_arr(arr1);
		free_arr(arr2);
		free_arr(arr3);
		err_handler();
	}
}

void	check_arr(char **arr1, char **arr2, char **arr3, int flag)
{
	if (arr1 == NULL)
	{
		free_arr(arr2);
		free_arr(arr3);
		err_handler();
	}
	else if (*arr1 == NULL && flag == ALL)
	{
		free_arr(arr1);
		free_arr(arr2);
		free_arr(arr3);
		err_handler();
	}
}

void	exit_handler(char **arr, t_list **stack)
{
	free_arr(arr);
	ft_lstclear(stack, free);
	err_handler();
}

//separates numbers and puts them to a single array
char	**argstoarr(int argc, char *argv[])
{
	int		i;
	char	**nums;
	char	**next;
	char	**temp;

	if (argv[1][0] == '\0')
		err_handler();
	nums = ft_split(argv[1], ' ');
	check_arr(nums, NULL, NULL, ALL);
	i = 2;
	while (i <= argc - 1)
	{
		next = ft_split(argv[i], ' ');
		check_arr(next, nums, NULL, ALL);
		temp = nums;
		nums = join_arrs(nums, next);
		free_arr(temp);
		free_arr(next);
		i++;
	}
	return (nums);
}
