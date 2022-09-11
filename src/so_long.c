/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:39:47 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/11 17:32:07 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_struct(t_data *sl)
{
	sl->img_anim = NULL;
	sl->img_head = NULL;
	sl->comment = 0;
	sl->rows = 0;
	sl->cols = 0;
	sl->starts = 0;
	sl->collectibles = 0;
	sl->exits = 0;
	sl->map = NULL;
	sl->player.direction = 'r';
	sl->enemies = NULL;
	sl->moves = 0;
	sl->anim_tick = 1;
	sl->enem_tick = 1;
}

int	so_long(t_data *sl)
{
	int	window_width;

	window_width = sl->cols * SPRITE_SIZE;
	if (window_width < BANNER_HEIGHT * 10)
		window_width = BANNER_HEIGHT * 10;
	sl->mlx = mlx_init();
	if (sl->mlx)
	{
		sl->win = mlx_new_window(sl->mlx, window_width,
				sl->rows * SPRITE_SIZE + BANNER_HEIGHT, "so_long");
		if (sl->win)
		{
			get_images(sl);
			mlx_loop_hook(sl->mlx, &screen_update, sl);
			mlx_hook(sl->win, 2, (1L<<0), &keypress_handler, sl);
			mlx_hook(sl->win, 17, 0, &closed_by_user, sl);
			mlx_loop(sl->mlx);
		}		
		mlx_destroy_display(sl->mlx);
		free(sl->mlx);
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	t_data	sl;

	if (argc != 2)
		ft_putendl("Error!\nInvalid arguments!");
	else
	{
		set_struct(&sl);
		if (file_check(&sl, argv[1]) == 0)
			so_long(&sl);
	}
	return (0);
}*/

int	main(void)
{
	t_data	sl;

	set_struct(&sl);
	if (file_check(&sl, "map01.ber") == 0)
		so_long(&sl);
	return (0);
}