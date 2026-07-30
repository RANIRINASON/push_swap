/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 00:02:07 by nambirak          #+#    #+#             */
/*   Updated: 2026/02/03 00:33:52 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*tmp;

	if (num != 0 && size > ((size_t) - 1) / num)
		return (NULL);
	tmp = (void *)malloc(num * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, num * size);
	return (tmp);
}
