/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:40:59 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/14 09:56:28 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_helper(t_elemt **data, t_elemt *first, t_elemt *last, \
						t_elemt *current)
{
	if (!(*data))
	{
		*data = current;
		(*data)->next = current;
		(*data)->previous = current;
		(*data)->end = 1;
	}
	else
	{
		first = *data;
		last = (*data)->previous;
		first->previous = current;
		last->next = current;
		*data = current;
		current->next = first;
		current->previous = last;
		current->end = 0;
	}
}

void	push_to_a(t_data *data)
{
	t_elemt	*first;
	t_elemt	*last;
	t_elemt	*current;

	if (!(data->b))
		return ;
	current = data->b;
	last = NULL;
	first = NULL;
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
	push_to_helper(&(data->a), first, last, current);
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
	last = NULL;
	first = NULL;
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
	push_to_helper(&(data->b), first, last, current);
	data->size_b++;
	data->size_a--;
}
