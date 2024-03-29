/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:34:35 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/25 15:25:24 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TYPE_SA 1
# define TYPE_SB 2
# define TYPE_RA 3
# define TYPE_RB 4
# define TYPE_PA 5
# define TYPE_PB 6
# define TYPE_RR 7
# define TYPE_RRA 8
# define TYPE_RRB 9
# define TYPE_RRR 10
# define TYPE_SS 11

# include "libft.h"

typedef struct		s_elemt
{
	int				number;
	struct s_elemt	*next;
	struct s_elemt	*previous;
	int				end;
}					t_elemt;

typedef struct		s_data
{
	t_elemt			*a;
	t_elemt			*b;
	int				count;
	int				size_a;
	int				size_b;
	int				visual;
	struct s_steps	*steps;
	int				offsets;
}					t_data;

typedef struct		s_steps
{
	int				type;
	struct s_steps	*next;
}					t_steps;

int					check_digits(char *string);
int					fill_elements(t_elemt **list, int number);
int					duplicate(t_elemt *list, t_data *data);
int					is_sorted(t_elemt *list);
int					commander(t_data *data, char *command);
t_data				*create_table(t_elemt *list);
void				swap_a(t_data *data);
void				swap_b(t_data *data);
void				swap_both(t_data *data);
void				push_to_a(t_data *data);
void				push_to_b(t_data *data);
void				rotate_a(t_data *data);
void				rotate_b(t_data *data);
void				rotate_both(t_data *data);
void				reverse_rotate_a(t_data *data);
void				reverse_rotate_b(t_data *data);
void				reverse_rotate_both(t_data *data);
int					ft_median(t_elemt *stack, int stack_size);
int					ft_average(t_elemt *stack, int number);
int					smallest_number(t_elemt *stack);
int					biggest_number(t_elemt *stack);
int					path_right(t_elemt *stack, int number);
int					path_left(t_elemt *stack, int number);
void				shortest_path_b(t_data *data, int biggest, int smallest);
int					path_finder(t_elemt *cpy, int biggest, int smallest, \
		int *path_len_r);
void				ft_add_step(t_data *data, int type);
void				optimize(t_data *data);
void				print_from_optimizer(t_data *data);
void				sorting_five(t_data *data);
void				smart_sort(t_data *data);
void				sort_big(t_data *data);
int					parser(int argc, char **argv, t_elemt **list, int *visual);
void				dummy_sort(int **list, int stack_size);
void				presort_b(t_data *data);
void				sort_a(t_data *data);
void				push_rotate_a(t_data *data);
void				smallest_infour(t_data *data);
int					exist_below(t_data *data, int nbr);
void				push_smallest(t_data *data, int smallest);
void				wipe_element(t_elemt *list);
void				wipe_data(t_data **data);
void				visual(t_data *data, char *command);
void				load_offsets(t_data *data);

#endif
