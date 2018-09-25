/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:01:52 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/25 14:21:16 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_b(t_data *data)
{
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

void	push_presort_b(t_data *data)
{
	while (data->size_a > 4)
	{
		if (data->a->number < ft_median(data->a, data->size_a))
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
	smallest_infour(data);
}

void	sort_a(t_data *data)
{
	while (!(is_sorted(data->a)))
	{
		if (data->a->number > data->a->next->number && data->a->number < \
				data->a->previous->number)
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
}

void	push_rotate_a(t_data *data)
{
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

void	smart_sort(t_data *data)
{
	push_presort_b(data);
	sort_a(data);
	push_rotate_a(data);
}
