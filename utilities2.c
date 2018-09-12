/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:05 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/12 15:18:07 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	path_finder(t_elemt *cpy, int biggest, int smallest, int *path_len_right)
{
	int		biggest_path_len_right;
	int		biggest_path_len_left;
	int		smallest_path_len_right;
	int		smallest_path_len_left;

	biggest_path_len_right = path_right(cpy, biggest);
	biggest_path_len_left = path_left(cpy, biggest);
	smallest_path_len_right = path_right(cpy, smallest);
	smallest_path_len_left = path_left(cpy, smallest);

	*path_len_right = (biggest_path_len_right > smallest_path_len_right) ? \
				  smallest_path_len_right : biggest_path_len_right;
	if (biggest_path_len_left > smallest_path_len_left)
		return (smallest_path_len_left);
	return (biggest_path_len_left);

}

void	shortest_path_b(t_data *data, int biggest, int smallest)
{
	int		smallest_path_len_right;
	int		smallest_path_len_left;
	int		path_len_right;
	int		path_len_left;
	int		using;

	smallest_path_len_right = path_right(data->b, smallest);
	smallest_path_len_left = path_left(data->b, smallest);
	path_len_left = path_finder(data->b, biggest, smallest, &path_len_right);
	using = 0;
	if (path_len_right < path_len_left)
	{
		using = (path_len_right == smallest_path_len_right) ? 1 : using;
		while (path_len_right--)
		{
			rotate_b(data);
			ft_add_step(data, TYPE_RB);
		}
	}
	else
	{
		using = (path_len_left == smallest_path_len_left) ? 1 : using;
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

int	ft_isnumeric(const char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	free_tab(char ***str)
{
	char**cpy;

	cpy = *str;
	while (*cpy)
	{
		free(*cpy);
		cpy++;
	}
	free(*str);
	str = NULL;
}
