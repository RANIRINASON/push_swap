/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:38:18 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/16 21:49:06 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_convert(char s, va_list av, int fd)
{
	if (s == 's')
		ft_putstr_fd(va_arg(av, char *), fd);
	if (s == 'c')
		ft_putchar_fd(va_arg(av, int), fd);
	if (s == 'd' || s == 'i')
		ft_putnbr_fd(va_arg(av, int), fd);
	if (s == '%')
		ft_putchar_fd('%', fd);
	return (0);
}

void	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_convert(format[i], ap, fd);
		}
		else
			write (fd, &format[i], 1);
		i++;
	}
	va_end(ap);
}
