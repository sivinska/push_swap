
#include "push_swap.h"
#include<stdio.h>

void	sort_50(t_data *data)
{
	int 		median;
	int		total;

	median = ft_median(data->a, data->size_a);
	total = data->size_a;
	while (data->size_a > (total / 2) + (total % 2))
	{
		if (data->a->number < median)
		{
			push_to_b(data);
			write(1, "pb\n", 3); 
		}
		else
		{
			rotate_a(data);
			write(1, "ra\n", 3);
		}
	}
	int printed_a;
	int printed_b;
	while (!(is_sorted(data->a)) || !(is_reverse_sorted(data->b)))
	{
		printed_a = 0;
		printed_b = 0;
		if (!(is_sorted(data->a)))
		{
			if (data->a->number > data->a->next->number)
			{
				printed_a = 1;
				swap_a(data);
				write(1, "sa\n", 3);
			}
			else if (data->a->number < data->a->previous->number)
			{	
				reverse_rotate_a(data);
				write(1, "rra\n", 4);
			}
			else
			{
				rotate_a(data);
				write(1, "ra\n", 3);
			}
		}
		if (!(is_reverse_sorted(data->b)))
		{
			if (data->b->number < data->b->next->number)
			{
				swap_b(data);
				write(1, "sb\n", 3);
			}
			else if (data->b->number > data->b->previous->number)
			{
				reverse_rotate_b(data);
				write(1, "rrb\n", 4);
			}
			else
			{
				printed_b = 1;
				rotate_b(data);
				write(1, "rb\n", 3);
			}
		}
		/*if (printed_a && printed_b)
			write (1, "ss\n", 3);
		else
		{
			if (printed_a)
				write(1, "sa\n", 3);
			if (printed_b)
				write(1, "sb\n", 3);
		}*/
		printed_a = 0;
		printed_b = 0;
		/*if (!(is_sorted(data->a)))
		{
			printed_a = 1;
			rotate_a(data);
			write(1, "ra\n", 3);
		}*/
			/*else
			{
				printed_b = 1;
				rotate_b(data);
				write(1, "rb\n", 3);
			}*/
		/*if (printed_a && printed_b)
		{
			write(1, "rr\n", 3);
		}
		else
		{
			if (printed_a)
				write(1, "ra\n", 3);
			if (printed_b)
				write(1, "rb\n", 3);
		}*/			
	}
	while (data->b)
	{
		push_to_a(data);
		write(1, "pa\n", 3);
	}
}