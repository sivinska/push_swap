/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/19 17:26:17 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_elemt	*list;
	t_data	*data;

	list = 0;
	if (argc == 1)
		return (1);
	if (parser(argc, argv, &list) == 0)
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
	if (data->count <= 100)
		smart_sort(data);
	else
		sort_big(data);
	optimize(data);
	print_from_optimizer(data);
	wipe_data(&data);
	return (0);
}
