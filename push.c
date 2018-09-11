/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:40:59 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 15:06:53 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_data *data)
{
	t_elemt	*first;
	t_elemt	*last;
	t_elemt	*current;

	if (!(data->b))
		return ;
	current = data->b;
	if (current->end == 1)
		data->b = NULL;
	else
	{
		first = current->next;
		last = current->previous;
		first->previous = last;
		last->next = first;
		data->b = first;
	}
	if (!(data->a))
	{
		data->a = current;
		data->a->next = current;
		data->a->previous = current;
		data->a->end = 1;
	}
	else
	{
		first = data->a;
		last = data->a->previous;
		first->previous = current;
		last->next = current;
		data->a = current;
		current->next = first;
		current->previous = last;
		current->end = 0;
	}
	data->size_a++;
	data->size_b--;
}

void	push_to_b(t_data *data)
{
	t_elemt	*first;
	t_elemt	*last;
	t_elemt	*current;

	if (!(data->a))
		return ;
	current = data->a;
	if (current->end == 1)
		data->a = NULL;
	else
	{
		first = current->next;
		last = current->previous;
		first->previous = last;
		last->next = first;
		data->a = first;
	}
	if (!(data->b))
	{
		data->b = current;
		data->b->next = current;
		data->b->previous = current;
		data->b->end = 1;
	}
	else
	{
		first = data->b;
		last = data->b->previous;
		first->previous = current;
		last->next = current;
		data->b = current;
		current->next = first;
		current->previous = last;
		current->end = 0;
	}
	data->size_b++;
	data->size_a--;
}
