/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:38:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/06/18 19:16:51 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

int		main(int argc, char **argv)
{
	int			i;
	t_element	*list;
	t_data		*data;
	char		*command;

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
	while (get_next_line(0, &command) == 1)
	{
		if (commander(data, command) == 0)
		{
			ft_putendl_fd("Error", 2);
			free(command);
			return (1);
		}
		free(command);
	}
	(is_sorted(data->a) == 1 && data->b == NULL ? ft_putendl("OK") : ft_putendl("KO"));
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


