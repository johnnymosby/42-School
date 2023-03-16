/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_longest_subsequence.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:57:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/16 14:14:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**allocate_square_matrix(int n_elems)
{
	int	**matrix;
	int	i;


	i = 0;
	matrix = ft_calloc(sizeof(int *) * (n_elems));
	while (i <= n_elems)
	{
		matrix[i] = calloc(sizeof(int) * (n_elems + 1));
		if (matrix[i] == NULL)
			exit ;
		i++;
	}
	return (matrix);
}

int	find_the_longest_subsequence(int *arr, int n_elems)
{
	int	**matrix;
	int	i;
	int	j;
	int	n;
	int	m;

	i = 0;
	j = 1;
	n = 1;
	matrix = allocate_square_matrix(n_elems);
	matrix[0][arr[0]] = -1;
	matrix[n_elems][0] = arr[0];

	while (n != n_elems)
	{
		if (arr[n] < arr[n - 1])
		{
			m = 0;
			while (m != n_elems)
			{
				if (matrix[m][n_elems] > arr[n])
				{
					matrix[m][n_elems] = arr[n];
					if (m == 0)
						matrix[m][arr[n]] = -1;
					else
						matrix[m][arr[n]] = matrix[m - 1][n_elems];
					break ;
				}
			}
		}
	}
}
