/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:53:13 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/20 16:24:14 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_part(t_elemt *stack, int stack_size, int part[])
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

void	sort_quarter(t_data *data, int part[])
{
	while (exist_below(data, part[0]))
	{
		if (data->a->number < part[0])
		{
			push_to_b(data);
			ft_add_step(data, TYPE_PB);
			presort_b(data);
		}
		else
		{
			rotate_a(data);
			ft_add_step(data, TYPE_RA);
		}
	}
}

void	sort_half(t_data *data, int part[])
{
	while (exist_below(data, part[1]))
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
}

void	sort_push_b(t_data *data)
{
	while (data->size_a > 4)
	{
		if (data->a->number < ft_median(data->a, data->size_a))
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
	smallest_infour(data);
}

void	sort_big(t_data *data)
{
	int		part[3];
	int		size;
	int		target;

	get_part(data->a, data->size_a, part);
	size = data->size_a / 4;
	target = data->size_a - size;
	sort_quarter(data, &part[0]);
	sort_half(data, &part[1]);
	while (exist_below(data, part[2]))
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
	sort_push_b(data);
	sort_a(data);
	push_rotate_a(data);
}
