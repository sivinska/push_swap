/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:23:07 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/24 16:03:06 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest(t_data *data, int smallest)
{
	t_elemt		*cpy;
	int			path_len_right;
	int			path_len_left;

	cpy = data->a;
	path_len_right = path_right(cpy, smallest);
	path_len_left = path_left(cpy, smallest);
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
