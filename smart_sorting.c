/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:01:52 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/06 16:11:54 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_stacka(t_data *data)
{
	int	average;

	if (is_sorted(data->a))
		return ;
	// pushing
	while (!is_sorted(data->a))
	{
		average = ft_average(data->a, data->size_a);
		if (data->a->number < average)
		{
			if (data->a->number > data->a->next->number)
			{
				swap_a(data);
				write(1, "sa\n", 3);
			}
			push_to_b(data);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate_a(data);
			write(1, "ra\n", 3);
		}
	}

}


void		smart_sort(t_data *data)
{
	int	median_a;
	// pushing
	while (data->size_a > 3)
	{
		median_a = ft_median(data->a, data->size_a);
		if (data->a->number < median_a)
		{
/*			if (data->a->number > data->a->next->number)
			{
				swap_a(data);
				write(1, "sa\n", 3);
			}
			if (data->a->number > data->a->previous->number)
			{
				reverse_rotate_a(data);
				write(1, "rra\n", 4);
			}*/
			push_to_b(data);
			write(1, "pb\n", 3);
			if (data->b->number < ft_median(data->b, data->size_b))
			{
				if (data->b->number > data->b->next->number ||\
						data->b->next->number < ft_average(data->b, data->size_b))
				{
					swap_b(data);
					write(1, "sb\n", 3);
				}
				else if (data->b->number < data->b->next->number && \
						data->b->next->number < ft_average(data->b, data->size_b))
				{
					rotate_b(data);
					write(1, "rb\n", 3);
				}

				else
				{
					rotate_b(data);
					write(1, "rb\n", 3);
				}
			}
		}
		else
		{
			rotate_a(data);
			write(1, "ra\n", 3);
		}
	}
	// sort stack a (3 elements)
	while (!(is_sorted(data->a)))
	{
		if (data->a->number > data->a->next->number)
		{
			swap_a(data);
			write(1, "sa\n", 3);
		}
		else if (data->a->number < data->a->previous->number)
		{
			reverse_rotate_a(data);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate_a(data);
			write(1, "ra\n", 3);
		}
	}
	// pushing to a
	int	average;
	int biggest;
//	int	smallest;
	while (data->b)
	{
		average = ft_average(data->b, data->size_b);
//		biggest = biggest_number(data->b);
//		smallest = smallest_number(data->b);
		if (data->b->number > ft_median(data->b, data->size_b))
		{
			biggest = biggest_number(data->b);
			shortest_path_b(data, biggest);
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
		}

		sorting_stacka(data);
		if (data->size_b <= 3)
		{
			push_to_a(data);
			write(1, "pa\n", 3);
		}
		//biggest = biggest_number(data->b);
		//shortest_path_b(data, biggest);
	}
}
