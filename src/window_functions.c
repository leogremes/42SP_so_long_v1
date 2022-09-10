/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: super_leo <super_leo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:41:44 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/10 08:36:25 by super_leo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_banner(t_data *sl)
{
	void	*img_ptr;
	int		moves;
	int		len;
	int		i;	

	moves = sl->moves;
	len = ft_nbrlen(moves);
	if (len < 3)
		len = 3;
	if (sl->img_st.moves)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_st.moves, 0, 0);
	i = 0;
	while (++i <= len)
	{
		img_ptr = NULL;
		if (moves > 0 || i == 1)
			img_ptr = point_to_number_image(moves % 10, sl);
		if (img_ptr)
		{
			mlx_put_image_to_window(sl->mlx, sl->win, img_ptr, 
				(BANNER_HEIGHT * 7) + ((len - i) * BANNER_HEIGHT), 0);
			moves /= 10;
		}
	}	
}

static void	tick_counter(t_data *sl)
{
	if (sl->anim_tick == ANIM_TICKRATE)
	{
		if (!sl->img_anim->next)
			sl->img_anim = sl->img_head;
		else
			sl->img_anim = sl->img_anim->next;
		sl->anim_tick = 1;
	}
	else
		sl->anim_tick++;
	if (sl->enem_tick == ENEMY_MOVE_TICKRATE)
	{
		//enemy_moves(sl);
		sl->enem_tick = 1;
	}
	else
		sl->enem_tick++;
}

int	screen_update(t_data *sl)
{
	unsigned int	row;
	unsigned int	col;
	void			*img_ptr;

	tick_counter(sl);
	print_banner(sl);
	if (sl->win)
	{
		row = -1;
		while (++row < sl->rows)
		{
			col = -1;
			while (++col < sl->cols)
			{
				img_ptr = point_to_image(row, col, sl);
				if (img_ptr)
				{
					mlx_put_image_to_window(sl->mlx, sl->win, img_ptr,
						col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
				}
			}
		}
	}
	return (0);
}
