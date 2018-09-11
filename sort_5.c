/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:11:55 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 15:15:27 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		smallest_number(t_elemt *stack)
{
	int		min;

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

void	find_shortest_and_go(t_data *data, int number)
{
	t_elemt	*cpy;
	int		path_len_right;
	int		path_len_left;

	cpy = data->a;
	path_len_right = path_right(cpy, number);
	path_len_left = path_left(cpy, number);
	if (path_len_right < path_len_left)
	{
		while (path_len_right--)
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}
	else
	{
		while (path_len_left--)
		{
			reverse_rotate_a(data);
			ft_add_step(data, TYPE_RRA);
		}
	}
	push_to_b(data);
	ft_add_step(data, TYPE_PB);
}

void	sort_5(t_data *data)
{
	if (data->a->number > data->a->next->number)
	{
		swap_a(data);
		ft_add_step(data, TYPE_SA);
	}
	while (data->size_a > 3)
		find_shortest_and_go(data, smallest_number(data->a));
	while (!(is_sorted(data->a)))
	{
		if (data->a->number > data->a->next->number)
		{
			swap_a(data);
			ft_add_step(data, TYPE_SA);
		}
		else if (data->a->number < data->a->previous->number)
		{
			reverse_rotate_a(data);
			ft_add_step(data, TYPE_RRA);
		}
		else
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}
	if (is_sorted(data->b) && data->b)
	{
		swap_b(data);
		ft_add_step(data, TYPE_SB);
	}
	while (data->size_b)
	{
		push_to_a(data);
		ft_add_step(data, TYPE_PA);
	}
}
