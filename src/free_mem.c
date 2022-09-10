/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:54:17 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/10 12:43:48 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *sl)
{
	size_t	i;

	i = -1;
	while (sl->map[++i])
	{
		free(sl->map[i]);
	}
	free(sl->map);
	sl->map = NULL;
}

void	destroy_window(t_data *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	sl->win = NULL;
}
