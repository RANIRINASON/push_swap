/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 22:03:38 by nambirak          #+#    #+#             */
/*   Updated: 2026/04/30 00:28:13 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	parse_mode(int argc, char **argv)
{
	int		i;
	int		flag_count;
	t_mode	mode;

	i = 1;
	mode = ADAPTIVE;
	flag_count = 0;
	while (i < argc)
	{
		parse_utils(argv[i], &mode, &flag_count);
		i++;
	}
	if (flag_count > 1)
		error();
	return (mode);
}

int	is_flag(char *arg)
{
	if (ft_strncmp(arg, "--simple", 8) == 0 && arg[8] == '\0')
		return (1);
	if (ft_strncmp(arg, "--medium", 8) == 0 && arg[8] == '\0')
		return (1);
	if (ft_strncmp(arg, "--complex", 9) == 0 && arg[9] == '\0')
		return (1);
	if (ft_strncmp(arg, "--adaptive", 10) == 0 && arg[10] == '\0')
		return (1);
	if (ft_strncmp(arg, "--bench", 7) == 0 && arg[7] == '\0')
		return (1);
	return (0);
}

static int	set_mode(char *arg)
{
	if (ft_strncmp(arg, "--simple", 8) == 0 && arg[8] == '\0')
		return (SIMPLE);
	if (ft_strncmp(arg, "--medium", 8) == 0 && arg[8] == '\0')
		return (MEDIUM);
	if (ft_strncmp(arg, "--complex", 9) == 0 && arg[9] == '\0')
		return (COMPLEX);
	if (ft_strncmp(arg, "--adaptive", 10) == 0 && arg[10] == '\0')
		return (ADAPTIVE);
	return (-1);
}

void	handle_flag(char *arg, t_context *ct)
{
	int	mode;

	mode = set_mode(arg);
	if (mode != -1)
	{
		if (ct->mode != ADAPTIVE)
			error();
		ct->mode = mode;
	}
	else if (ft_strncmp(arg, "--bench", 7) == 0 && arg[7] == '\0')
		ct->bench = 1;
	else
		error();
}
