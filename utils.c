/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 06:29:06 by aranirin          #+#    #+#             */
/*   Updated: 2026/05/05 00:49:03 by aranirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	free_stack(t_stack **stack)
{
	t_stack		*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	parse_utils(char *arg, t_mode *mode, int *flag_count)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		*mode = SIMPLE;
		(*flag_count)++;
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		*mode = MEDIUM;
		(*flag_count)++;
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		*mode = COMPLEX;
		(*flag_count)++;
	}
	else if (ft_strncmp (arg, "--adaptive", 11) == 0)
	{
		*mode = ADAPTIVE;
		(*flag_count)++;
	}
}

t_context	init_global(void)
{
	t_context	ct;

	ct.mode = ADAPTIVE;
	ct.bench = 0;
	ct.a = NULL;
	ct.b = NULL;
	ct.count = NULL;
	ct.disorder = 0;
	return (ct);
}
