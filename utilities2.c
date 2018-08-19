
#include "push_swap.h"

void	shortest_path_b(t_data *data, int number)
{
	t_element	*cpy;
	int		path_len_right;
	int		path_len_left;

	cpy = data->b;
	path_len_right = path_right(cpy, number);
	path_len_left = path_left(cpy, number);

	if (path_len_right < path_len_left)
	{
		while (path_len_right--)
		{
			rotate_b(data);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (path_len_left--)
		{
			reverse_rotate_b(data);
			write(1, "rrb\n", 4);
		}
	}
	push_to_a(data);
	write(1, "pa\n", 3);
}
