/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/17 15:58:29 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int			i;
	t_elemt	*list;
	t_data		*data;

	list = 0;
	i = 1;
	if (argc == 1)
		return (1);

	if (parser(argc, argv, &list) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
/*	while (i < argc)
	{
		if (check_digits(argv[i]))
		{
			fill_elements(&list, ft_atoi(argv[i]));
			i++;
		}
		else
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
	}*/
	data = create_table(list);
	if (duplicate(list, data) == 0)
		return (0);
//	free(list->next);
//	data = create_table(list);
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
