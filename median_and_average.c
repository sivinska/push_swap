/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_and_average.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:14:12 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/18 15:14:24 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_average(t_elemt *stack, int stack_size)
{
	int		average;
	t_elemt *cpy;
	t_elemt *end;

	cpy = stack;
	end = stack;
	average = 0;
	while (cpy)
	{
		average += cpy->number;
		cpy = cpy->next;
		if (cpy == end)
			break ;
	}
	return (average / stack_size);
}

void	dummy_sort(int **list, int stack_size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < stack_size - 1)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if ((*list)[i] > (*list)[j])
			{
				temp = (*list)[i];
				(*list)[i] = (*list)[j];
				(*list)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int		ft_median(t_elemt *stack, int stack_size)
{
	int		median;
	int		*list;
	int		i;

	median = 0;
	if (!(list = (int*)malloc(sizeof(int) * stack_size)))
		return (0);
	i = 0;
	while (stack->next)
	{
		list[i++] = stack->number;
		if (stack->end)
			break ;
		stack = stack->next;
	}
	dummy_sort(&list, stack_size);
	median = list[stack_size / 2];
	free(list);
	return (median);
}
