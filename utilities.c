

#include "push_swap.h"

int	biggest_number(t_element *stack)
{
	int	max;

	max = stack->number;
	while (stack)
	{
		if (max < stack->number)
			max = stack->number;
		if (stack->end == 1)
			break ;
		stack = stack->next;
	}
	return (max);
}

int	path_right(t_element *stack, int number)
{
	t_element	*cpy;
	int		path_len;

	cpy = stack;
	path_len = 0;
	while (cpy)
	{
		if (cpy->number == number)
			break ;
		path_len++;
		cpy = cpy->next;
	}
	return (path_len);
}

int	path_left(t_element *stack, int number)
{
	t_element	*cpy;
	int		path_len;

	cpy = stack;
	path_len = 0;
	while (cpy)
	{
		if (cpy->number == number)
			break ;
		path_len++;
		cpy = cpy->previous;
	}
	return (path_len);
}

int	ft_average(t_element *stack, int stack_size)
{
	int			average;
	t_element *cpy;
	t_element *end;

	cpy = stack;
	end = stack;
	average = 0;
	while (cpy)
	{
		average += cpy->number;

		cpy = cpy->next;
		if (cpy == end)
			break ;
	}
	return (average / stack_size);
}

int	ft_median(t_element *stack, int stack_size)
{
	int		median;
	int		*list;
	int		i;
	int		j;
	int		temp;

	median = 0;
	if (!(list = (int*)malloc(sizeof(int) * stack_size)))
		return (0);
	i = 0;
	while (stack->next)
	{
		list[i++] = stack->number;
		if (stack->end)
			break ;
		stack = stack->next;
	}
	i = 0;
	while (i < stack_size - 1)
	{
		j = i + 1;
		while(j < stack_size)
		{
			if (list[i] > list[j])
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
			j++;
		}
		i++;
	}
	median = list[stack_size / 2];
	free (list);
	return (median);
}
