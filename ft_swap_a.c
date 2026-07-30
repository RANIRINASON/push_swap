/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:35:38 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/18 20:55:36 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	int	tmp;

	if (!stack ||!*stack ||!(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_stack **a, int *count)
{
	ft_swap(a);
	write(1, "sa\n", 3);
	count[SA]++;
}

void	sb(t_stack **b, int *count)
{
	ft_swap(b);
	write(1, "sb\n", 3);
	count[SB]++;
}

void	ss(t_stack **a, t_stack **b, int *count)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
	count[SS]++;
}
