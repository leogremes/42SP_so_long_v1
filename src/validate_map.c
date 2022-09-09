/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:29:18 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/08 23:18:56 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_data *sl)
{
	size_t	i;

	i = -1;
	while (++i < sl->cols)
	{
		if (sl->map[0][i] != '1' || sl->map[sl->rows - 1][i] != '1')
			return (1);
	}
	i = -1;
	while (++i < sl->rows)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->cols - 1] != '1')
			return (1);
	}
	return (0);
}

static void	set_player_position(t_data *sl, unsigned int row, unsigned int col)
{
	sl->player.row = row;
	sl->player.col = col;
}

static int	check_invalid(t_data *sl)
{
	unsigned int	row;
	unsigned int	col;

	row = -1;
	while (++row < sl->rows)
	{
		col = -1;
		while (++col < sl->cols)
		{
			if (sl->map[row][col] == 'P')
				set_player_position(sl, row, col);
			else if (sl->map[row][col] == 'H' || sl->map[row][col] == 'h'
				|| sl->map[row][col] == 'V' || sl->map[row][col] == 'v')
				create_enemy(sl, row, col);
			else if (sl->map[row][col] != 'C' && sl->map[row][col] != 'E'
				&& sl->map[row][col] != '1' && sl->map[row][col] != '0')
				return (1);
		}
	}
	return (0);
}

static int	free_map_error(t_data *sl, char *message)
{
	free_map(sl);
	free_enemies_list(sl);
	ft_putendl(message);
	return (1);
}

int	validate_map(t_data *sl)
{
	sl->cols = ft_strlen(sl->map[0]);
	while (sl->map[++sl->rows])
	{
		if (ft_strlen(sl->map[sl->rows]) != sl->cols)
			return (free_map_error(sl, "Error!\nMap is not rectangular!"));
	}
	if (check_walls(sl) == 1)
		return (free_map_error(sl, "Error!\nMap is not surrounded by walls!"));
	if (check_invalid(sl) == 1)
		return (free_map_error(sl, "Error!\nMap contains invalid characters!"));
	return (0);
}
