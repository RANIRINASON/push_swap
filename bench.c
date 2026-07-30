/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:04:09 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/23 21:04:02 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_mode(t_mode mode, double disorder)
{
	if (mode == SIMPLE)
		return ("Simple / O(n^2)");
	if (mode == MEDIUM)
		return ("Medium / O(n√n)");
	if (mode == COMPLEX)
		return ("Complex / O(nlogn)");
	if (mode == ADAPTIVE)
	{
		if ((disorder < 0.2))
			return ("Adaptive / O(n^2)");
		else if (disorder >= 0.2 && (disorder < 0.5))
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlogn)");
	}
	return ("Unknown");
}

static void	float_disorder(double disorder)
{
	double	tmp;
	int		entier;
	int		decimal;

	tmp = disorder * 100;
	entier = (int)tmp;
	decimal = (int)((tmp - entier) * 100 + 0.5);
	if (decimal == 100)
	{
		entier++;
		decimal = 0;
	}
	ft_printf_fd(2, "%d.%d", entier, decimal);
	if (decimal <= 9 || decimal == 100)
		ft_printf_fd(2, "0");
	ft_printf_fd(2, "%%\n");
}

void	printf_bench(t_mode mode, int *count, double disorder)
{
	int	total_count;
	int	i;

	i = 0;
	total_count = 0;
	while (i < op_count)
	{
		total_count += count[i];
		i++;
	}
	ft_printf_fd(2, "[bench] disorder :");
	float_disorder(disorder);
	ft_printf_fd(2, "[bench] stategy  : %s\n", get_mode(mode, disorder));
	ft_printf_fd(2, "[bench] total_ops : %d\n", total_count);
	ft_printf_fd(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		count[SA], count[SB], count[SS],
		count[PA], count[PB]);
	ft_printf_fd(2,
		"[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		count[RA], count[RB], count[RR],
		count[RRA], count[RRB], count[RRR]);
}
