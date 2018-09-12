/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:57:31 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/12 15:24:42 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*int		ft_isnumeric(const char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	free_tab(char ***str)
{
	char	**cpy;

	cpy = *str;
	while (*cpy)
	{
		free(*cpy);
		cpy++;
	}
	free(*str);
	str = NULL;
}*/

/*int		parser(int argc, char **argv, t_elemt **list)
{
	char	**tab;
	int		i;
	int		j;
	
	i = 1;
	while (i < argc)
	{
		if (ft_isnumeric(argv[i]))
		{
			fill_elements(list, ft_atoi(argv[i]));
		}
		else
		{
			tab = ft_strsplit(argv[i], ' ');
			j = 0;
			while (tab[j])
			{
				if (check_digits(tab[j]))
					fill_elements(list, ft_atoi(tab[j]));
				else
				{
					free_tab(&tab);
					return (0);
				}
				j++;
			}
			free_tab(&tab);
		}
		i++;
	}
	return (1);
}*/

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

/*	t_elemt *cpy;
	t_elemt *end;
	end = list;
	cpy = list;
	while(cpy)
	{
		printf("item: %d\n", cpy->number);
		cpy = cpy->next;
		if (cpy == end)
			break ;
	}
	return (0);*/
	data = create_table(list);
	if (duplicate(list, data) == 0)
		return (0);
//	data = create_table(list);
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
	(is_sorted(data->a) == 1 && data->b == NULL ? \
	ft_putendl("OK") : ft_putendl("KO"));
	return (0);
}
