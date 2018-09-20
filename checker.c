/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:57:31 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/20 16:58:46 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_the_line(char *command, t_data *data)
{
	visual(data, NULL);
	while (get_next_line(0, &command) == 1)
	{
		if (commander(data, command) == 0)
		{
			ft_putendl_fd("Error: invalid command", 2);
			free(command);
			wipe_data(&data);
			return (1);
		}
		visual(data, command);
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
	int			visual;

	list = 0;
	visual = 0;
	command = NULL;
	if (argc == 1)
		return (1);
	if (parser(argc, argv, &list, &visual) == 0)
	{
		ft_putendl_fd("Error: invalid input", 2);
		wipe_element(list);
		return (1);
	}
	data = create_table(list);
	if (duplicate(list, data) == 0)
	{
		wipe_data(&data);
		return (0);
	}
	load_offsets(data);
	data->visual = visual;
	if (get_the_line(command, data) == 1)
		return (1);
	(is_sorted(data->a) == 1 && data->b == NULL ? \
	ft_putendl("OK") : ft_putendl("KO"));
	wipe_data(&data);
	return (0);
}
