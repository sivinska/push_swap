/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:17:55 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/25 14:15:08 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_infour(t_data *data)
{
	while (data->size_a == 4)
	{
		if (data->a->number == smallest_number(data->a))
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

int		exist_below(t_data *data, int nbr)
{
	t_elemt	*a;

	a = data->a;
	while (a)
	{
		if (a->number < nbr)
			return (1);
		a = a->next;
		if (a == data->a)
			break ;
	}
	return (0);
}
