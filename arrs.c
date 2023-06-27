/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:12:48 by mrubina           #+#    #+#             */
/*   Updated: 2023/06/27 16:51:30 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

char	**join_arrs(char **arr1, char **arr2)
{
	char	**arr;
	int		i;
	int		size1;
	int		size2;

	size1 = arr_size(arr1);
	size2 = arr_size(arr2);
	i = 0;
	arr = malloc(sizeof(char *) * (size1 + size2 + 1));
	check_arr(arr, arr1, arr2, 0);
	while (arr1[i] != NULL)
	{
		arr[i] = ft_strdup(arr1[i]);
		check_elmnt(arr[i], arr, arr1, arr2);
		i++;
	}
	while (arr2[i - size1] != NULL)
	{
		arr[i] = ft_strdup(arr2[i - size1]);
		check_elmnt(arr[i], arr, arr1, arr2);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
