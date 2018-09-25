/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:07:12 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/25 15:41:14 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		duplicate(t_elemt *list, t_data *data)
{
	t_elemt	*temp;

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
			if (temp->end == 1)
				break ;
			temp = temp->next;
		}
		temp = temp->next;
		data->count++;
		if (list->end)
			break ;
		list = list->next;
	}
	return (1);
}

int		is_sorted(t_elemt *list)
{
	while (list)
	{
		if (list->end)
			break ;
		if (list->number >= list->next->number)
			return (0);
		list = list->next;
	}
	return (1);
}

int		check_digits(char *string)
{
	int					i;
	long long int		limit;

	limit = ft_atoi_signed(string);
	if (limit > 2147483647 || limit < -2147483648)
		return (0);
	i = 0;
	if (*string == '-')
		string++;
	while (ft_isdigit(string[i]) || string[i] == ' ')
		i++;
	if (string[i] != '\0' || i == 0)
		return (0);
	else
		return (1);
}

int		fill_elements(t_elemt **list, int new)
{
	t_elemt	*element;

	if (!(element = (t_elemt*)malloc(sizeof(t_elemt))))
		return (0);
	element->end = 1;
	element->number = new;
	if (*list)
	{
		element->next = *list;
		element->previous = (*list)->previous;
		(*list)->previous->next = element;
		(*list)->previous = element;
		element->previous->end = 0;
	}
	else
	{
		*list = element;
		element->next = element;
		element->previous = element;
	}
	return (1);
}

t_data	*create_table(t_elemt *list)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	data->a = list;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->count = 0;
	data->steps = NULL;
	data->visual = 0;
	data->offsets = 0;
	return (data);
}
