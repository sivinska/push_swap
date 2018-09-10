/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:53:18 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/10 17:11:19 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_step(t_data *data, int type)
{
	t_steps		*cpy;
	t_steps		*new;

	if (!(new = (t_steps*)malloc(sizeof(t_steps))))
		return ;
	new->type = type;
	new->next = NULL;

	// data->steps   
	// null arba not null
	if (!data->steps)
		data->steps = new;
	else
	{
		cpy = data->steps;
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = new;
	}
}

void	optimize(t_data *data)
{
	t_steps *cpy;
	t_steps	*next;

	cpy = data->steps;
	if (!cpy)
		return ;
	while (cpy->next)
	{
		next = cpy->next;
		if (cpy->type == TYPE_RA && next->type == TYPE_RB)
		{
			cpy->type = TYPE_RR;
			cpy->next = next->next;
			free(next);
		}
		else if (cpy->type == TYPE_RRA && next->type == TYPE_RRB)
		{
			cpy->type = TYPE_RRR;
			cpy->next = next->next;
			free(next);
		}
		cpy = cpy->next;
	}
}

void	print_from_optimizer(t_data *data)
{
	t_steps		*cpy;

	cpy = data->steps;
	while (cpy)
	{
		if (cpy->type == TYPE_SA)
			write(1, "sa\n", 3);
		if (cpy->type == TYPE_PA)
			write(1, "pa\n", 3);
		if (cpy->type == TYPE_RA)
			write(1, "ra\n", 3);
		if (cpy->type == TYPE_SB)
			write(1, "sb\n", 3);
		if (cpy->type == TYPE_PB)
			write(1, "pb\n", 3);
		if (cpy->type == TYPE_RB)
			write(1, "rb\n", 3);
		if (cpy->type == TYPE_RR)
			write(1, "rr\n", 3);
		if (cpy->type == TYPE_RRA)
			write(1, "rra\n", 4);
		if (cpy->type == TYPE_RRB)
			write(1, "rrb\n", 4);
		if (cpy->type == TYPE_RRR)
			write(1, "rrr\n", 4);
		cpy = cpy->next;
	}
}
