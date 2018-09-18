/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:57:31 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/18 10:09:01 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_the_line(char *command, t_data *data)
{
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
	return (0);
}

int			main(int argc, char **argv)
{
	t_elemt		*list;
	t_data		*data;
	char		*command;

	list = 0;
	command = NULL;
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
	get_the_line(command, data);
	(is_sorted(data->a) == 1 && data->b == NULL ? \
	ft_putendl("OK") : ft_putendl("KO"));
	wipe_data(&data);
	return (0);
}
