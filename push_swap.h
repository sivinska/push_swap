/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:34:35 by sivinska          #+#    #+#             */
/*   Updated: 2018/06/18 19:14:50 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct	s_element
{
	int						number;
	struct s_element		*next;
	struct s_element		*previous;
	int						end;
}				t_element;



int		check_digits(char *string);
int		fill_elements(t_element **list, int number);
int		duplicate(t_element *list);
int		is_sorted(t_element *list);


#endif
