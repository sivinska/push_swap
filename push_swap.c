/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/05 17:01:15 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

int		main(int argc, char **argv)
{
	int			i;
	t_element	*list;
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
//	if (data->count < 6)
//		sort_5(data);
	if (data->count > 0)
		smart_sort(data);
	/*else if (data->count < 51)
		sort_50(data);*/
	return (0);
}

int		duplicate(t_element *list)
{
	t_element	*temp;
	
	temp = list;
	while (list)
	{
		while (temp)
		{
			if (temp->number == list->number && temp != list)
			{
				ft_putendl_fd("Error", 2);
				return (0);
			}
			if (temp->end)
				break;
			temp = temp->next;
	}
		temp = temp->next;
		if (list->end)
			break;
		list = list->next;
	}
	return (1);
}


