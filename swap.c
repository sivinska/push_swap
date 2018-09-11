/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:56:38 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 14:35:26 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	int	tmp;

	if (!(data->a) || data->a->end)
		return ;
	tmp = data->a->number;
	data->a->number = data->a->next->number;
	data->a->next->number = tmp;
}

void	swap_b(t_data *data)
{
	int	tmp;

	if (!(data->b) || data->b->end)
		return ;
	tmp = data->b->number;
	data->b->number = data->b->next->number;
	data->b->next->number = tmp;
}

void	swap_both(t_data *data)
{
	swap_a(data);
	swap_b(data);
}
