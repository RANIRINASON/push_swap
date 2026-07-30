/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 22:26:54 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/16 23:44:37 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack		*first;
	t_stack		*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a, int *count)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
	count[RA]++;
}

void	rb(t_stack **b, int *count)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
	count[RB]++;
}

void	rr(t_stack **a, t_stack **b, int *count)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
	count[RR]++;
}
