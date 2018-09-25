/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:57:31 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/25 13:42:46 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		wipe_element(t_elemt *list)
{
	t_elemt *tmp;

	if (list)
	{
		while (list->end != 1)
		{
			tmp = list;
			list = list->next;
			free(tmp);
		}
	}
	free(list);
}

static void	wipe_stacks(t_elemt *a, t_elemt *b, t_elemt *tmp)
{
	t_elemt *cpy;

	cpy = b;
	if (a)
	{
		while (a->end != 1)
		{
			tmp = a;
			a = a->next;
			free(tmp);
		}
		free(a);
	}
	if (b)
	{
		while (b)
		{
			tmp = b;
			b = b->next;
			free(tmp);
			if (b == cpy)
				break ;
		}
	}
}

void		wipe_data(t_data **data)
{
	t_elemt		*a;
	t_elemt		*b;
	t_steps		*steps;
	t_elemt		*tmp;
	t_steps		*tmp2;

	a = (*data)->a;
	b = (*data)->b;
	steps = (*data)->steps;
	tmp2 = NULL;
	tmp = NULL;
	wipe_stacks(a, b, tmp);
	while (steps)
	{
		tmp2 = steps;
		steps = steps->next;
		free(tmp2);
	}
	free(*data);
}
