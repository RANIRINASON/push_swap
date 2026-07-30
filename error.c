/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:02:50 by aranirin          #+#    #+#             */
/*   Updated: 2026/05/05 00:02:54 by aranirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	error_all(t_stack **a, char **split)
{
	if (split)
		ft_free_split(split);
	if (a)
		free_stack(a);
	error();
}
