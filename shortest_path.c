/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:17:18 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/20 16:17:24 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_helper(t_data *data)
{
	rotate_b(data);
	ft_add_step(data, TYPE_RB);
}

static void	rr_b_helper(t_data *data)
{
	reverse_rotate_b(data);
	ft_add_step(data, TYPE_RRB);
}

static void	push_a_helper(t_data *data)
{
	push_to_a(data);
	ft_add_step(data, TYPE_PA);
}

static void	using_helper(t_data *data, int using)
{
	if (using)
	{
		if (data->size_b == 0 && is_sorted(data->a))
			return ;
		rotate_a(data);
		ft_add_step(data, TYPE_RA);
	}
}

void		shortest_path_b(t_data *data, int biggest, int smallest)
{
	int		spr;
	int		spl;
	int		len_right;
	int		len_left;
	int		using;

	spr = path_right(data->b, smallest);
	spl = path_left(data->b, smallest);
	len_left = path_finder(data->b, biggest, smallest, &len_right);
	using = 0;
	if (len_right < len_left)
	{
		using = (len_right == spr) ? 1 : using;
		while (len_right--)
			rotate_b_helper(data);
	}
	else
	{
		using = (len_left == spl) ? 1 : using;
		while (len_left--)
			rr_b_helper(data);
	}
	push_a_helper(data);
	using_helper(data, using);
}
