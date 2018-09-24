/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/24 16:29:06 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		do_sorting(t_data *data)
{
	if (data->count < 6)
		sorting_five(data);
	else if (data->count <= 100)
		smart_sort(data);
	else
		sort_big(data);
	optimize(data);
	print_from_optimizer(data);
}

int				main(int argc, char **argv)
{
	t_elemt	*list;
	t_data	*data;
	int		visual;

	list = 0;
	visual = 0;
	if (argc == 1)
		return (1);
	if (parser(argc, argv, &list, &visual) == 0 || visual)
	{
		wipe_element(list);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	data = create_table(list);
	if (duplicate(list, data) == 0)
	{
		wipe_data(&data);
		return (0);
	}
	data->size_a = data->count;
	do_sorting(data);
	wipe_data(&data);
	return (0);
}
