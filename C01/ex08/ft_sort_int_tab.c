/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:10:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/06 13:10:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

void	ft_swap(int *a, int *b);
void	ft_quick_sort(int *tab, int a, int b);
void	ft_sort_int_tab(int *tab, int size);

void	ft_swap(int *a, int *b)
{
	int	point;

	point = *a;
	*a = *b;
	*b = point;
}

void	ft_quick_sort(int *tab, int first, int last)
{
	int	center;
	int	a;
	int	b;

	if (first < last)
	{
		center = last;
		a = first;
		b = last;
		while (a < b)
		{
			while(tab[a]<center && a < last)
			{
				a++;
			}
			while(tab[b]>center)
			{
				b--;
			}
			if (a < b)
			{
				ft_swap(&tab[a], &tab[b - 1]);
			}
		}
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_quick_sort(tab, 0, size);
}

int main()
{
	int arr[] = {100, 32, 20, 43, 15, 56};
	int size = 6;
	for (int i=0; i < size; i++)
	{
		printf("%d", arr[i]);
	}
	int * tab;
	tab = &arr[0];
	ft_sort_int_tab(tab, size);
	for (int i=0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}

	return 0;
}
