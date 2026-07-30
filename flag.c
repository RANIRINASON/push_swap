/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:51:27 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/29 23:30:13 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	wquotation(t_stack **a, char *arg, char **split, int *count)
{
	long	value;

	if (!is_valid_format(arg))
	{
		free(count);
		error_all(a, split);
	}
	value = l_atoi(arg);
	if (value > 2147483647 || value < -2147483648)
	{
		free(count);
		error_all(a, split);
	}
	if (ft_check_duplicate(*a, (int)value))
	{
		free(count);
		error_all(a, split);
	}
	add_back(a, new_node((int)value));
}

static void	quotation(t_context *ct, char *arg)
{
	int		j;
	char	**split;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		error_all(&ct->a, split);
	}
	j = 0;
	while (split[j])
	{
		if (is_flag(split[j]))
			handle_flag(split[j], ct);
		else
			wquotation(&ct->a, split[j], split, ct->count);
		j++;
	}
	ft_free_split(split);
}

void	parse_numbers(t_context *ct, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			quotation(ct, argv[i]);
		else if (is_flag(argv[i]))
			handle_flag(argv[i], ct);
		else
			wquotation(&ct->a, argv[i], NULL, ct->count);
		i++;
	}
}

void	execute(t_stack **a, t_stack **b, t_mode mode, int *count)
{
	if (!a || !*a)
		return ;
	else if (mode == ADAPTIVE)
		adaptive(a, b, count);
	else if (mode == SIMPLE)
		simple_sort(a, b, count);
	else if (mode == MEDIUM)
		chunk_sort(a, b, count);
	else if (mode == COMPLEX)
		radix_sort(a, b, count);
	else
		adaptive(a, b, count);
}
