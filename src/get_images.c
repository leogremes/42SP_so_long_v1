/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:56:58 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/10 00:11:30 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_static_images(t_data *sl)
{
	t_img_st	*img;
	int			w;
	int			h;

	img = &sl->img_st;
	img->floor = mlx_xpm_file_to_image(sl->mlx, "./sprites/floor.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(sl->mlx, "./sprites/wall.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(sl->mlx, "./sprites/exit.xpm", &w, &h);
	img->moves = mlx_xpm_file_to_image(sl->mlx, "./sprites/moves.xpm", &w, &h);
	img->n0 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n0.xpm", &w, &h);
	img->n1 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n1.xpm", &w, &h);
	img->n2 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n2.xpm", &w, &h);
	img->n3 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n3.xpm", &w, &h);
	img->n4 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n4.xpm", &w, &h);
	img->n5 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n5.xpm", &w, &h);
	img->n6 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n6.xpm", &w, &h);
	img->n7 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n7.xpm", &w, &h);
	img->n8 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n8.xpm", &w, &h);
	img->n9 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n9.xpm", &w, &h);
}

void	get_images(t_data *sl)
{
	get_static_images(sl);
	get_animated_nodes(sl);
}
