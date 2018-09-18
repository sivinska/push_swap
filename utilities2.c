/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:05 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/18 15:53:28 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		path_finder(t_elemt *cpy, int biggest, int smallest, int *path_len_r)
{
	int		bpr;
	int		bpl;
	int		spr;
	int		spl;

	bpr = path_right(cpy, biggest);
	bpl = path_left(cpy, biggest);
	spr = path_right(cpy, smallest);
	spl = path_left(cpy, smallest);
	*path_len_r = (bpr > spr) ? spr : bpr;
	if (bpl > spl)
		return (spl);
	return (bpl);
}

void	shortest_path_b(t_data *data, int biggest, int smallest)
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
		{
			rotate_b(data);
			ft_add_step(data, TYPE_RB);
		}
	}
	else
	{
		using = (len_left == spl) ? 1 : using;
		while (len_left--)
		{
			reverse_rotate_b(data);
			ft_add_step(data, TYPE_RRB);
		}
	}
	push_to_a(data);
	ft_add_step(data, TYPE_PA);
	if (using)
	{
		if (data->size_b == 0 && is_sorted(data->a))
			return ;
		rotate_a(data);
		ft_add_step(data, TYPE_RA);
	}
}
