/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:05:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/24 15:56:01 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void		load_offsets(t_data *data)
{
	t_elemt	*cpy;

	cpy = data->a;
	while (cpy)
	{
		if (ft_get_nbr_len_push(cpy->number) > data->offsets)
			data->offsets = ft_get_nbr_len_push(cpy->number);
		cpy = cpy->next;
		if (cpy == data->a)
			break ;
	}
}

static void	print_header(t_data *data)
{
	ft_putstr("A");
	fill_with_char(data->offsets - 1, ' ');
	ft_putstr("|");
	fill_with_char(data->offsets - 1, ' ');
	ft_putendl("B");
	fill_with_char((data->offsets) * 2 + 1, '-');
	ft_putchar('\n');
}

static void	print_elemt(t_elemt **stack, t_elemt *target)
{
	if (*stack)
	{
		ft_putnbr((*stack)->number);
		*stack = (*stack)->next;
		if (*stack == target)
			*stack = NULL;
	}
	else
		ft_putchar(' ');
}

static void	print_stacks(t_data *data)
{
	t_elemt		*a;
	t_elemt		*b;
	int			len;

	a = data->a;
	b = data->b;
	while (a || b)
	{
		if (a)
			len = ft_get_nbr_len_push(a->number);
		else
			len = 0;
		if (len)
			fill_with_char(data->offsets - len, ' ');
		else
			fill_with_char(data->offsets - len - 1, ' ');
		print_elemt(&a, data->a);
		ft_putstr("|");
		if (b)
			fill_with_char(data->offsets - ft_get_nbr_len_push(b->number), ' ');
		else
			fill_with_char(data->offsets, ' ');
		print_elemt(&b, data->b);
		ft_putstr("\n");
	}
}

void		visual(t_data *data, char *command)
{
	static int total;

	if (data->visual == 0)
		return ;
	ft_putstr("\e[1;1H\e[2J");
	print_header(data);
	print_stacks(data);
	ft_putstr("\nCurrent command: ");
	if (command)
	{
		ft_putendl(command);
		total++;
	}
	else
		ft_putchar('\n');
	ft_putstr("Total: ");
	ft_putnbr(total);
	ft_putchar('\n');
	usleep(200000);
}
