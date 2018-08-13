# include "push_swap.h"


int	commander(t_data *data, char *command)
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
	t_element *a = data->a;
	t_element *b = data->b;
	ft_putstr("Stack A: ");
	while (a)
	{
		ft_putnbr(a->number);
		ft_putchar(' ');
		if (a->end == 1)
			break ;
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("Stack B: ");
	while (b)
	{
		ft_putnbr(b->number);
		ft_putchar(' ');
		if (b->end == 1)
			break ;
		b = b->next;
	}
	ft_putchar('\n');
	return (1);
}
