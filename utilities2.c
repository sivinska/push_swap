/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:05 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 15:19:11 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	shortest_path_b(t_data *data, int biggest, int smallest)
{
	t_elemt	*cpy;
	int		biggest_path_len_right;
	int		biggest_path_len_left;
	int		smallest_path_len_right;
	int		smallest_path_len_left;

	cpy = data->b;
	biggest_path_len_right = path_right(cpy, biggest);
	biggest_path_len_left = path_left(cpy, biggest);
	smallest_path_len_right = path_right(cpy, smallest);
	smallest_path_len_left = path_left(cpy, smallest);
	
	// TEMP
	int path_len_right = 0;
	int path_len_left = 0;
	if (biggest_path_len_right > smallest_path_len_right)
		path_len_right = smallest_path_len_right;
	else
		path_len_right = biggest_path_len_right;
	if (biggest_path_len_left > smallest_path_len_left)
		path_len_left = smallest_path_len_left;
	else
		path_len_left = biggest_path_len_left;
	// /TEMP

	int using = 0;

	if (path_len_right < path_len_left)
	{
		if (path_len_right == smallest_path_len_right)
			using = 1;
		while (path_len_right--)
		{
			rotate_b(data);
			ft_add_step(data, TYPE_RB);
		}
	}
	else
	{
		if (path_len_left == smallest_path_len_left)
			using = 1;
		while (path_len_left--)
		{
			reverse_rotate_b(data);
			ft_add_step(data, TYPE_RRB);
		}
	}
	push_to_a(data);
	ft_add_step(data, TYPE_PA);
	if (using)
	{
		rotate_a(data);
		ft_add_step(data, TYPE_RA);
	}
}

int	second_biggest(t_elemt *stack)
{
	int		max;
	int		second_max;

	max = stack->number;
	second_max = max;
	while (stack)
	{
		if (max < stack->number)
		{
			second_max = max;
			max = stack->number;
		}
		else if (stack->number > second_max && stack->number != max)
			second_max = stack->number;
		if (stack->end == 1)
			break ;
			stack = stack->next;
	}
	return (second_max);
}
