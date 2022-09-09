/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:54:52 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/08 12:54:10 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_nbrlen(int n)
{
	size_t	counter;

	counter = 1;
	if (n < 0)
		counter++;
	else
		n *= -1;
	while (n <= -10)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nbrlen(n);
	itoa = malloc(sizeof(char) * (i + 1));
	if (!itoa)
		return (NULL);
	if (n < 0)
		itoa[0] = '-';
	else
		n *= -1;
	itoa[i] = '\0';
	while (n < 0)
	{
		itoa[--i] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	return (itoa);
}
