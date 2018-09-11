/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:38:29 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 14:39:08 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_data *data)
{
	if (!(data->a))
		return ;
	data->a->previous->previous->end = 1;
	data->a->previous->end = 0;
	data->a = data->a->previous;
}

void	reverse_rotate_b(t_data *data)
{
	if (!(data->b))
		return ;
	data->b->previous->previous->end = 1;
	data->b->previous->end = 0;
	data->b = data->b->previous;
}

void	reverse_rotate_both(t_data *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
}
