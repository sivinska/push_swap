/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:05:01 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/19 11:01:18 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_parser(t_elemt **list, char **tab, int j)
{
	while (tab[j])
	{
		if (check_digits(tab[j]))
		{
			fill_elements(list, ft_atoi(tab[j]));
		}
		else
		{
			free_tab(&tab);
			return (0);
		}
		j++;
	}
	free_tab(&tab);
	return (1);
}

int		parser(int argc, char **argv, t_elemt **list)
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
			if (!help_parser(list, &tab[j], j))
				return (0);
		}
		i++;
	}
	return (1);
}
