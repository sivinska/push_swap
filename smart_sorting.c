
#include "push_swap.h"

void		smart_sort(t_data *data)
{
	int	median;

	// pushing
	while (data->size_a > 3)
	{
		median = ft_median(data->a, data->size_a);
		if (data->a->number < median)
		{
			if (data->a->number > data->a->previous->number)
			{
				reverse_rotate_a(data);
				write(1, "rra\n", 4);
			}
			else if (data->a->number > data->a->next->number)
			{
				swap_a(data);
				write(1, "sa\n", 3);
			}
			push_to_b(data);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate_a(data);
			write(1, "ra\n", 3);
		}
	}
	// sort stack a (3 elements)
	while (!(is_sorted(data->a)))
	{
		if (data->a->number > data->a->next->number)
		{
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
	// pushing to a
	int biggest;
	while (data->b)
	{
		biggest = biggest_number(data->b);
		shortest_path_b(data, biggest);
	}
}
