/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:41:44 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/10 00:21:43 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(unsigned int row, unsigned int col, t_data *sl)
{
	char			c;

	c = sl->map[row][col];
	if (c == '1')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_st.wall,
			col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
	if (c == '0')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_st.floor,
			col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
	if (c == 'E')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_st.exit,
			col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
	if (c == 'C')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_anim->col,
			col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
	if (c == 'H' || c == 'h' || c == 'V' || c == 'v')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_anim->e_d,
			col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
	if (c == 'P')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_anim->p_r,
			col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
}

int	screen_update(t_data *sl)
{
	unsigned int	row;
	unsigned int	col;

	if (sl->win)
	{
		row = -1;
		while (++row < sl->rows)
		{
			col = -1;
			while (++col < sl->cols)
			{
				put_image(row, col, sl);
			}
		}
	}
	return (0);
}
