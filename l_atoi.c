/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:03:22 by aranirin          #+#    #+#             */
/*   Updated: 2026/05/05 00:03:28 by aranirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_space_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	l_atoi(const char *nptr)
{
	long	resultat;
	int		i;
	int		signe;

	i = 0;
	resultat = 0;
	signe = skip_space_sign(nptr, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (resultat > (LONG_MAX - (nptr[i] - '0')) / 10)
		{
			if (signe == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		resultat = resultat * 10 + (nptr[i] - '0');
		i++;
	}
	return (resultat * signe);
}
