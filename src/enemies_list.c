/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:05:37 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/08 23:17:59 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_char	*new_enemy_node(char dir, unsigned int row, unsigned int col)
{
	t_char	*new;

	new = malloc(sizeof(t_char));
	if (!new)
		return (NULL);
	new->direction = dir;
	new->row = row;
	new->col = col;
	new->next = NULL;
	return (new);
}

void	create_enemy(t_data *sl, unsigned int row, unsigned int col)
{
	t_char	*new;
	t_char	*tmp;
	char	c;

	c = sl->map[row][col];
	if (c == 'H')
		new = new_enemy_node('u', row, col);
	else if (c == 'h')
		new = new_enemy_node('d', row, col);
	else if (c == 'V')
		new = new_enemy_node ('r', row, col);
	else
		new = new_enemy_node ('l', row, col);
	if (!sl->enemies)
		sl->enemies = new;
	else
	{
		tmp = sl->enemies;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_enemies_list(t_data *sl)
{
	t_char	*tmp;

	if (sl->enemies)
	{
		while (sl->enemies)
		{
			tmp = sl->enemies->next;
			free(sl->enemies);
			sl->enemies = tmp;
		}
	}
}
