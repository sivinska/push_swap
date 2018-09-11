/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:36:19 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 14:37:34 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	if (!(data->a))
		return ;
	data->a->previous->end = 0;
	data->a->end = 1;
	data->a = data->a->next;
}

void	rotate_b(t_data *data)
{
	if (!(data->b))
		return ;
	data->b->previous->end = 0;
	data->b->end = 1;
	data->b = data->b->next;
}

void	rotate_both(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}
