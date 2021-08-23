/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:20:52 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:20:55 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(int *a, int *b);

static void	sieve(int *array, size_t size, size_t n);

void	heap_sort(int *array, size_t size)
{
	size_t	k;

	k = size / 2;
	while (k > 0)
	{
		--k;
		sieve(array, size, k);
	}
	k = size;
	while (k > 1)
	{
		--k;
		swap(array, array + k);
		sieve(array, k, 0);
	}
}

static void	sieve(int *array, size_t size, size_t n)
{
	size_t	left;
	size_t	right;
	size_t	high;

	while (1)
	{
		left = 2 * n + 1;
		if (left >= size)
			break ;
		right = left + 1;
		high = left;
		if (right < size && array[right] > array[left])
			high = right;
		if (array[n] >= array[high])
			break ;
		swap(array + n, array + high);
		n = high;
	}
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
