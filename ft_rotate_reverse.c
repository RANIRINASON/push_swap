/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 23:56:08 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/16 23:45:22 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_a;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp_a = *stack;
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	tmp = tmp_a->next;
	tmp_a->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_stack **a, int *count)
{
	ft_rotate_reverse(a);
	write(1, "rra\n", 4);
	count[RRA]++;
}

void	rrb(t_stack **b, int *count)
{
	ft_rotate_reverse(b);
	write(1, "rrb\n", 4);
	count[RRB]++;
}

void	rrr(t_stack **a, t_stack **b, int *count)
{
	ft_rotate_reverse(a);
	ft_rotate_reverse(b);
	write(1, "rrr\n", 4);
	count[RRR]++;
}
