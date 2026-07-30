/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:14:31 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/29 23:58:26 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i);
}

static void	start_chunk(t_chunk *c, t_stack *a)
{
	c->size = stack_size(a);
	c->nb_chunk = ft_sqrt(c->size);
	if (c->nb_chunk == 0)
		c->nb_chunk = 1;
	c->chunk_size = c->size / c->nb_chunk;
	c->chunk_max = c->chunk_size;
	c->chunk_mid = c->chunk_size / 2;
	c->pushed = 0;
}

static void	process_chunk(t_stack **a, t_stack **b,
		int *count, t_chunk *c)
{
	if ((*a)->index <= c->chunk_max)
	{
		pb(a, b, count);
		if ((*b)->index <= c->chunk_mid)
			rb(b, count);
		c->pushed++;
	}
	else
		ra(a, count);
}

void	push_to_b(t_stack **a, t_stack **b, int *count)
{
	t_chunk	c;

	start_chunk(&c, *a);
	if (c.size <= 5)
		return (simple_sort(a, b, count));
	while (*a)
	{
		process_chunk(a, b, count, &c);
		if (c.pushed == c.chunk_size)
		{
			c.chunk_max += c.chunk_size;
			c.chunk_mid = c.chunk_max - (c.chunk_size / 2);
			c.pushed = 0;
		}
	}
}
