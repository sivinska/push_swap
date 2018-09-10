/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:34:35 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/10 16:36:57 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define TYPE_SA 1
#define TYPE_SB 2
#define TYPE_RA 3
#define TYPE_RB 4
#define TYPE_PA 5
#define TYPE_PB 6
#define TYPE_RR 7
#define TYPE_RRA 8
#define TYPE_RRB 9
#define TYPE_RRR 10

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
	t_element		*a;
	t_element		*b;
	int				count;
	int				size_a;
	int				size_b;
	struct s_steps	*steps;
}		t_data;

typedef struct s_steps
{
	int				type;
	struct s_steps *next;
}				t_steps;


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
void		shortest_path_b(t_data *data, int biggest, int smallest);
int		ft_average(t_element *stack, int number);
int		smallest_number(t_element *stack);
void	find_shortest_and_go(t_data *data, int number);
int		second_biggest(t_element *stack);
void	ft_add_step(t_data *data, int type);
void	print_from_optimizer(t_data *data);
void	optimize(t_data *data);
#endif
