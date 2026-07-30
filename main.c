/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 06:28:27 by aranirin          #+#    #+#             */
/*   Updated: 2026/05/07 20:45:59 by aranirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_context(t_context *ct, int argc, char **argv)
{
	int	i;

	*ct = init_global();
	ct->count = malloc(sizeof(int) * op_count);
	if (!ct->count)
		error_all(&ct->a, NULL);
	i = 0;
	while (i < op_count)
		ct->count[i++] = 0;
	if (argc < 2)
	{
		free(ct->count);
		return (0);
	}
	parse_numbers(ct, argc, argv);
	if (!ct->a)
	{
		free(ct->count);
		error_all(&ct->a, NULL);
	}
	ct->disorder = compute_disorder(ct->a);
	return (1);
}

static int	handle_sorted(t_context *ct)
{
	if (!is_sorted(ct->a))
		return (0);
	if (ct->bench)
		printf_bench(ct->mode, ct->count, ct->disorder);
	free_stack(&ct->a);
	return (1);
}

static void	cleanup(t_context *ct)
{
	if (ct->bench)
		printf_bench(ct->mode, ct->count, ct->disorder);
	free_stack(&ct->a);
	free_stack(&ct->b);
	free(ct->count);
}

int	main(int argc, char **argv)
{
	t_context	ct;

	if (!init_context(&ct, argc, argv))
		return (0);
	if (handle_sorted(&ct))
	{
		free(ct.count);
		return (0);
	}
	execute(&ct.a, &ct.b, ct.mode, ct.count);
	cleanup(&ct);
	return (0);
}
