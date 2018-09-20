/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:57:31 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/20 14:34:59 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wipe_element(t_elemt *list)
{
	t_elemt *tmp;

	while (list->end != 1)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}

/*static void	wipe_steps(t_steps *steps, t_steps *tmp2)
{
	while (steps)
	{
		tmp2 = steps;
		steps = steps->next;
		free(tmp2);
	}
}*/

void	wipe_data(t_data **data)
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
		while (b->end != 1)
		{
			tmp = b;
			b = b->next;
			free(tmp);
		}
		free(b);
	}
	while (steps)
	{
		tmp2 = steps;
		steps = steps->next;
		free(tmp2);
	}
	free(*data);
}
