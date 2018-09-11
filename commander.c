/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:44:23 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/11 15:01:06 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		commander(t_data *data, char *command)
{
	if (command == 0 || ft_strlen(command) < 2 || ft_strlen(command) > 3)
		return (0);
	if (ft_strcmp(command, "sa") == 0)
		swap_a(data);
	else if (ft_strcmp(command, "sb") == 0)
		swap_b(data);
	else if (ft_strcmp(command, "ss") == 0)
		swap_both(data);
	else if (ft_strcmp(command, "pa") == 0)
		push_to_a(data);
	else if (ft_strcmp(command, "pb") == 0)
		push_to_b(data);
	else if (ft_strcmp(command, "ra") == 0)
		rotate_a(data);
	else if (ft_strcmp(command, "rb") == 0)
		rotate_b(data);
	else if (ft_strcmp(command, "rr") == 0)
		rotate_both(data);
	else if (ft_strcmp(command, "rra") == 0)
		reverse_rotate_a(data);
	else if (ft_strcmp(command, "rrb") == 0)
		reverse_rotate_b(data);
	else if (ft_strcmp(command, "rrr") == 0)
		reverse_rotate_both(data);
	else
		return (0);
	return (1);
}
