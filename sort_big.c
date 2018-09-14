/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:53:13 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/14 15:28:31 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void		get_part(t_elemt *stack, int stack_size, int part[])
{
	int		*list;
	int		i;

	if (!(list = (int*)malloc(sizeof(int) * stack_size)))
		return ;
	i = 0;
	while (stack->next)
	{
		list[i++] = stack->number;
		if (stack->end)
			break ;
		stack = stack->next;
	}
	dummy_sort(&list, stack_size);
	part[0] = list[stack_size / 4];
	part[1] = list[stack_size / 2];
	part[2] = list[stack_size / 4 * 3];
	free(list);
}

void	sort_big(t_data *data)
{
	int		part[3];
	int		size;
	int target;

	get_part(data->a, data->size_a, part);
	size = data->size_a / 4;
	target = data->size_a - size;
	while (data->size_a > target)
	{	
		if (data->a->number < part[0])
		{
			push_to_b(data);
			ft_add_step(data, TYPE_PB);
			if (data->b->number < ft_median(data->b, data->size_b))
			{
				if (data->b->number > data->b->next->number)
				{
					swap_b(data);
					ft_add_step(data, TYPE_SB);
				}
				else
				{
					rotate_b(data);
					ft_add_step(data, TYPE_RB);
				}
			}
		}
		else
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}

	while (data->size_a > 2 * size)
	{	
		if (data->a->number < part[1])
		{
			push_to_b(data);
			ft_add_step(data, TYPE_PB);
		}
		else
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}
	
	while (data->size_a >  size)
	{	
		if (data->a->number < part[2])
		{
			push_to_b(data);
			ft_add_step(data, TYPE_PB);
		}
		else
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}

	int		median_a;
	while (data->size_a > 2)
	{		
		median_a  = ft_average(data->a, data->size_a);
		if (data->a->number < median_a)
		{
			push_to_b(data);
			ft_add_step(data, TYPE_PB);
		}
		else
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}
	if (!(is_sorted(data->a)))
	{
		swap_a(data);
		ft_add_step(data, TYPE_SA);
	}
	while (data->b)
	{	
		shortest_path_b(data, biggest_number(data->b), \
				smallest_number(data->b));
	}
	while (!(is_sorted(data->a)))
	{	
		reverse_rotate_a(data);
		ft_add_step(data, TYPE_RRA);
	}
}
