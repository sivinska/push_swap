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

	list = 0;
	i = 1;
	while (i < argc)
	{
		if (check_digits(argv[i]))
		{
			fill_elements(&list, ft_atoi(argv[i]));
			i++;
		}
		else
		{
			ft_putendl("Error");
			break;
		}
	}
	if (duplicate(list) == 0)
		return (0);
	while (list)
	{
		printf("%d\n", list->number);
		if (list->end)
			break;
		list = list->next;
	}
	list = list->next;
	if (is_sorted(list) == 1)
		ft_putendl("Sorted!");
	else
		ft_putendl("Sad.");
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
				ft_putendl("Error");
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
