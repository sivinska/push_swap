/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:57:31 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/17 16:38:36 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int		main(int argc, char **argv)
{
	int			i;
	int			j;
	t_elemt		*list;
	t_data		*data;
	char		*command;

	list = 0;
	i = 1;
	j = 0;
	if (argc == 1)
		return (1);
	if (parser(argc, argv, &list) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	data = create_table(list);
	if (duplicate(list, data) == 0)
	{
		free(data);
		return (0);
	}
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
	free(command);
	(is_sorted(data->a) == 1 && data->b == NULL ? \
	ft_putendl("OK") : ft_putendl("KO"));
	wipe_data(&data);
	return (0);
}

