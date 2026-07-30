/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:07:30 by nambirak          #+#    #+#             */
/*   Updated: 2026/02/17 22:40:14 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cmp;

	if (!lst)
		return (0);
	cmp = 0;
	while (lst)
	{
		lst = lst->next;
		cmp++;
	}
	return (cmp);
}
