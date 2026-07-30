/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:42:48 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/20 20:32:00 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}

void	adaptive(t_stack **a, t_stack **b, int *count)
{
	double	disorder;
	int		size;

	size = stack_size(*a);
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		simple_sort(a, b, count);
	else if (disorder < 0.5)
		chunk_sort(a, b, count);
	else
		radix_sort(a, b, count);
}
