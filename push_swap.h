/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:34:35 by sivinska          #+#    #+#             */
/*   Updated: 2018/09/12 13:35:59 by sivinska         ###   ########.fr       */
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
	int				count;
}					t_elemt;

typedef struct		s_data
{
	t_elemt			*a;
	t_elemt			*b;
	int				count;
	int				size_a;
	int				size_b;
	struct s_steps	*steps;
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
int					is_reverse_sorted(t_elemt *list);
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
void				sort_5(t_data *data);
void				sort_50(t_data *data);
int					ft_median(t_elemt *stack, int stack_size);
void				smart_sort(t_data *data);
int					path_right(t_elemt *stack, int number);
int					path_left(t_elemt *stack, int number);
int					biggest_number(t_elemt *stack);
void				shortest_path_b(t_data *data, int biggest, int smallest);
int					ft_average(t_elemt *stack, int number);
int					smallest_number(t_elemt *stack);
void				find_shortest_and_go(t_data *data, int number);
int					second_biggest(t_elemt *stack);
void				ft_add_step(t_data *data, int type);
void				print_from_optimizer(t_data *data);
void				optimize(t_data *data);
int					parser(int argc, char **argv, t_elemt **list);
void				free_tab(char ***str);
int					ft_isnumeric(const char *str);
#endif
