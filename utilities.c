/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:32 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/20 16:16:26 by sivinska         ###   ########.fr       */
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

int	smallest_number(t_elemt *stack)
{
	int	min;

	min = stack->number;
	while (stack)
	{
		if (min > stack->number)
			min = stack->number;
		if (stack->end == 1)
			break ;
		stack = stack->next;
	}
	return (min);
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

int	path_finder(t_elemt *cpy, int biggest, int smallest, int *path_len_r)
{
	int	bpr;
	int	bpl;
	int	spr;
	int	spl;

	bpr = path_right(cpy, biggest);
	bpl = path_left(cpy, biggest);
	spr = path_right(cpy, smallest);
	spl = path_left(cpy, smallest);
	*path_len_r = (bpr > spr) ? spr : bpr;
	if (bpl > spl)
		return (spl);
	return (bpl);
}
