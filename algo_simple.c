/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:43:31 by nambirak          #+#    #+#             */
/*   Updated: 2026/05/04 23:23:42 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a, int *count)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, count);
	else if (x > y && y > z)
	{
		sa(a, count);
		rra(a, count);
	}
	else if (x > y && y < z && x > z)
		ra(a, count);
	else if (x < y && y > z && x < z)
	{
		sa(a, count);
		ra(a, count);
	}
	else if (x < y && y > z && x > z)
		rra(a, count);
}

static int	get_min_position(t_stack *a)
{
	int		i;
	int		pos;
	int		min;
	t_stack	*tmp;

	tmp = a;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int *count)
{
	int	pos;

	pos = get_min_position(*a);
	while (pos-- > 0)
		ra(a, count);
	pb(a, b, count);
}

static void	sort_five(t_stack **a, t_stack **b, int *count)
{
	while (stack_size(*a) > 3)
		push_min_to_b(a, b, count);
	sort_three(a, count);
	while (*b)
		pa(a, b, count);
}

void	simple_sort(t_stack **a, t_stack **b, int *count)
{
	int	size;

	if (!a || !(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, count);
	}
	else if (size == 3)
		sort_three(a, count);
	else
		sort_five(a, b, count);
}
