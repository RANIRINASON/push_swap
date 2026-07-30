/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambirak <nambirak@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:40:00 by nambirak          #+#    #+#             */
/*   Updated: 2026/02/17 22:45:39 by nambirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	k;

	if (!s)
		return (0);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (k);
}

static char	*get_word(const char *s, int start, int finish)
{
	char	*word;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*memory_free(char **tab, int i)
{
	if (!tab)
		return (NULL);
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	while (j < count_word(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result [j] = get_word(s, start, i);
		if (!result[j++])
			return (memory_free(result, j - 1));
	}
	result[j] = NULL;
	return (result);
}
