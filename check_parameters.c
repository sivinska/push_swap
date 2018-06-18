/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:07:12 by sivinska          #+#    #+#             */
/*   Updated: 2018/06/18 19:18:00 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_element *list)
{
	 while(list)
	 {
		 if (list->end)
			 break;
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
	while (ft_isdigit(string[i]))
		i++;
	if (string[i] != '\0' || i == 0 )
		return (0);
	else
		return (1);
}

int		fill_elements(t_element **list, int new)
{
	t_element	*element;

	if (!(element = (t_element*)malloc(sizeof(t_element))))
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

