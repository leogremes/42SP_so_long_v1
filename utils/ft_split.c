/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:46:40 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/07 18:15:52 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_strings(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	if (s)
	{
		while (s[0])
		{
			while (s[0] == c)
				s++;
			if (s[0])
				counter++;
			while (s[0] && s[0] != c)
				s++;
		}
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	qty;
	size_t	i;

	qty = count_strings(s, c);
	split = malloc(sizeof(char *) * (qty + 1));
	if (!split)
		return (NULL);
	split[qty] = NULL;
	qty = 0;
	while (s[0])
	{
		while (s[0] == c)
			s++;
		if (s[0])
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			split[qty++] = ft_substr(s, 0, i);
			s += i;
		}
	}
	return (split);
}
