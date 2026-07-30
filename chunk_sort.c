/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:08:00 by nambirak          #+#    #+#             */
/*   Updated: 2026/05/01 00:21:48 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_stack(t_stack *a)
{
	int		index;
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	current = a;
	while (current)
	{
		index = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

static int	max_pos(t_stack *a)
{
	int		max;
	int		i;
	int		pos;
	t_stack	*tmp;

	if (!a)
		return (-1);
	tmp = a;
	max = tmp->index;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	push_max_to_a(t_stack **a, t_stack **b, int *count)
{
	int	pos;
	int	size;
	int	moves;

	if (!*b)
		return ;
	pos = max_pos(*b);
	if (pos == -1)
		return ;
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, count);
	}
	else
	{
		moves = size - pos;
		while (moves-- > 0)
			rrb(b, count);
	}
	pa(a, b, count);
}

void	chunk_sort(t_stack **a, t_stack **b, int *count)
{
	index_stack(*a);
	push_to_b(a, b, count);
	while (*b)
		push_max_to_a(a, b, count);
}
