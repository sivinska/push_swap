/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:32 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/14 10:57:48 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_number(t_elemt *stack)
{
	int	max;

	max = stack->number;
	while (stack)
	{
		if (max < stack->number)
			max = stack->number;
		if (stack->end == 1)
			break ;
		stack = stack->next;
	}
	return (max);
}

int	path_right(t_elemt *stack, int number)
{
	t_elemt	*cpy;
	int		path_len;

	cpy = stack;
	path_len = 0;
	while (cpy)
	{
		if (cpy->number == number)
			break ;
		path_len++;
		cpy = cpy->next;
	}
	return (path_len);
}

int	path_left(t_elemt *stack, int number)
{
	t_elemt	*cpy;
	int		path_len;

	cpy = stack;
	path_len = 0;
	while (cpy)
	{
		if (cpy->number == number)
			break ;
		path_len++;
		cpy = cpy->previous;
	}
	return (path_len);
}

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
