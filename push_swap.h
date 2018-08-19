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

#include "libft.h"

typedef struct	s_element
{
	int				number;
	struct s_element		*next;
	struct s_element		*previous;
	int				end;
}		t_element;

typedef struct	s_data
{
	struct s_element		*a;
	struct s_element		*b;
	int				count;
	int				size_a;
	int				size_b;
}		t_data;

int		check_digits(char *string);
int		fill_elements(t_element **list, int number);
int		duplicate(t_element *list);
int		is_sorted(t_element *list);
int		is_reverse_sorted(t_element *list);
int		commander(t_data *data, char *command);
t_data		*create_table(t_element *list);
void		swap_a(t_data *data);
void		swap_b(t_data *data);
void		swap_both(t_data *data);
void		push_to_a(t_data *data);
void		push_to_b(t_data *data);
void		rotate_a(t_data *data);
void		rotate_b(t_data *data);
void		rotate_both(t_data *data);
void		reverse_rotate_a(t_data *data);
void		reverse_rotate_b(t_data *data);
void		reverse_rotate_both(t_data *data);
void		sort_5(t_data *data);
void		sort_50(t_data *data);
int		ft_median(t_element *stack, int stack_size);
void		smart_sort(t_data *data);
int		path_right(t_element *stack, int number);
int		path_left(t_element *stack, int number);
int		biggest_number(t_element *stack);
void		shortest_path_b(t_data *data, int number);
#endif
