/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:01:52 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/10 16:58:54 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_stacka(t_data *data)
{
	int	average;

	if (is_sorted(data->a))
		return ;
	while (!is_sorted(data->a))
	{
		average = ft_average(data->a, data->size_a);
		if (data->a->number < average)
		{
			if (data->a->number > data->a->next->number)
			{
				swap_a(data);
				ft_add_step(data, TYPE_SA);
			}
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

void		smart_sort(t_data *data)
{
	int	median_a;

	while (data->size_a > 3)
	{
		median_a = ft_average(data->a, data->size_a);
		if (data->a->number < median_a)
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
	while (data->b)
	{

		shortest_path_b(data, biggest_number(data->b), smallest_number(data->b));
		/*if (data->b->number > ft_(data->b, data->size_b))
		{

			if (data->b->number < data->b->next->number)
			{
				swap_b(data);
				write(1, "sb\n", 3);
			}
			else if (data->b->number < data->b->previous->number)
			{
				reverse_rotate_b(data);
				write(1, "rrb\n", 4);
			}
			else
			{
				push_to_a(data);
				write(1, "pa\n", 3);
			}
		}
		else
		{
			rotate_b(data);
			write(1, "rb\n", 3);
		}*/
//		sorting_stacka(data);
/*		if (data->size_b <= 3)
		{
			push_to_a(data);
			write(1, "pa\n", 3);
		}*/
	}
	while (!is_sorted(data->a))
	{
		reverse_rotate_a(data);
		ft_add_step(data, TYPE_RRA);
	}
}
