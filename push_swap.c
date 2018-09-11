/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 15:07:15 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int			i;
	t_elemt	*list;
	t_data		*data;

	list = 0;
	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
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
	}
	if (duplicate(list) == 0)
		return (0);
	data = create_table(list);
	data->count = argc - 1;
	data->size_a = argc - 1;
	if (data->count < 6)
		sort_5(data);
	else
		smart_sort(data);
	optimize(data);
	print_from_optimizer(data);
	return (0);
}
