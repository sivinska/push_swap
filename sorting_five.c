/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:07:02 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/25 14:22:40 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *data)
{
	if (data->a->number > data->a->next->number)
	{
		swap_a(data);
		ft_add_step(data, TYPE_SA);
	}
}

static void	sort_three(t_data *data)
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

static void	sort_four(t_data *data)
{
	smallest_infour(data);
	sort_three(data);
	push_to_a(data);
	ft_add_step(data, TYPE_PA);
}

static void	push_presort_five(t_data *data)
{
	while (data->size_a > 3)
		push_smallest(data, smallest_number(data->a));
}

void		sorting_five(t_data *data)
{
	if (data->count == 2)
		sort_two(data);
	if (data->count == 3)
		sort_three(data);
	if (data->count == 4)
		sort_four(data);
	push_presort_five(data);
	sort_a(data);
	push_rotate_a(data);
}
