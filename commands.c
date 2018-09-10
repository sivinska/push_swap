
#include "push_swap.h"

t_data		*create_table(t_element *list)
{
	t_data	*data;
	
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	data->a = list;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->count = 0;
	data->steps = NULL;
	return (data);
}

void	swap_a(t_data *data)
{	
	int	tmp;

	if (!(data->a) || data->a->end)
		return ;
	tmp = data->a->number;
	data->a->number = data->a->next->number;
	data->a->next->number = tmp;	
}

void	swap_b(t_data *data)
{	
	int	tmp;

	if (!(data->b) || data->b->end)
		return ;
	tmp = data->b->number;
	data->b->number = data->b->next->number;
	data->b->next->number = tmp;	
}

void	swap_both(t_data *data)
{
	swap_a(data);
	swap_b(data);
}

void	push_to_a(t_data *data)
{
	t_element	*first;
	t_element	*last;
	t_element	*current;

	if (!(data->b))
		return ;
	current = data->b;
	if (current->end == 1)
		data->b = NULL;
	else
	{
		first = current->next;
		last = current->previous;
		first->previous = last;
		last->next = first;
		data->b = first;
	}
	if (!(data->a))
	{
		data->a = current;
		data->a->next = current;
		data->a->previous = current;
		data->a->end = 1;
	}
	else
	{
		first = data->a;
		last = data->a->previous;
		first->previous = current;
		last->next = current;
		data->a = current;
		current->next = first;
		current->previous = last;
		current->end = 0;
	}
	data->size_a++;
	data->size_b--;
}

void	push_to_b(t_data *data)
{
	t_element	*first;
	t_element	*last;
	t_element	*current;

	if (!(data->a))
		return ;
	current = data->a;
	if (current->end == 1)
		data->a = NULL;
	else
	{
		first = current->next;
		last = current->previous;
		first->previous = last;
		last->next = first;
		data->a = first;
	}
	if (!(data->b))
	{
		data->b = current;
		data->b->next = current;
		data->b->previous = current;
		data->b->end = 1;
	}
	else
	{
		first = data->b;
		last = data->b->previous;
		first->previous = current;
		last->next = current;
		data->b = current;
		current->next = first;
		current->previous = last;
		current->end = 0;
	}
	data->size_b++;
	data->size_a--;
}

void	rotate_a(t_data *data)
{
	if (!(data->a))
		return ;
	data->a->previous->end = 0;
	data->a->end = 1;
	data->a = data->a->next;
}

void	rotate_b(t_data *data)
{
	if (!(data->b))
		return ;
	data->b->previous->end = 0;
	data->b->end = 1;
	data->b = data->b->next;	
}

void	rotate_both(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}

void	reverse_rotate_a(t_data *data)
{
	if (!(data->a))
		return ;
	data->a->previous->previous->end = 1;
	data->a->previous->end = 0;
	data->a = data->a->previous;
}

void	reverse_rotate_b(t_data *data)
{
	if (!(data->b))
		return ;
	data->b->previous->previous->end = 1;
	data->b->previous->end = 0;
	data->b = data->b->previous;
}

void	reverse_rotate_both(t_data *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
}
