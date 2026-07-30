/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 06:28:55 by aranirin          #+#    #+#             */
/*   Updated: 2026/05/05 00:02:29 by aranirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		++bits;
	return (bits);
}

static void	assign_index(t_stack *a)
{
	int	*tab;
	int	size;

	size = stack_size(a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	fill_tab(tab, a);
	ft_sort_int_tab(tab, size);
	set_index(a, tab, size);
	free(tab);
}

static void	process_bit(t_stack **a, t_stack **b,
	int *count, t_radix r)
{
	int	j;

	j = 0;
	while (j < r.size)
	{
		if ((((*a)->index >> r.bit) & 1) == 0)
			pb(a, b, count);
		else
			ra(a, count);
		j++;
	}
	while (*b)
		pa(a, b, count);
}

void	radix_sort(t_stack **a, t_stack **b, int *count)
{
	int		i;
	int		bits;
	int		size;
	t_radix	r;

	if (!a || !*a || !b)
		return ;
	assign_index(*a);
	size = stack_size(*a);
	if (size <= 5)
	{
		simple_sort(a, b, count);
		return ;
	}
	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		r.size = size;
		r.bit = i;
		process_bit(a, b, count, r);
		i++;
	}
}
