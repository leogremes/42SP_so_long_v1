/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anim_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:18:41 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/10 00:00:14 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img_anim	*create_img_node0(t_data *sl)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_u0.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_d0.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_l0.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_r0.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_u0.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_d0.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_l0.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_r0.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(sl->mlx, "./sprites/col0.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_img_anim	*create_img_node1(t_data *sl)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_u1.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_d1.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_l1.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_r1.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_u1.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_d1.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_l1.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_r1.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(sl->mlx, "./sprites/col1.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_img_anim	*create_img_node2(t_data *sl)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_u2.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_d2.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_l2.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_r2.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_u2.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_d2.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_l2.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_r2.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(sl->mlx, "./sprites/col2.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_img_anim	*create_img_node3(t_data *sl)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_u1.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_d1.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_l1.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/p_r1.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_u1.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_d1.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_l1.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/e_r1.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(sl->mlx, "./sprites/col3.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

void	get_animated_nodes(t_data *sl)
{
	sl->img_head = create_img_node0(sl);
	sl->img_head->next = create_img_node1(sl);
	sl->img_anim = sl->img_head->next;
	sl->img_anim->next = create_img_node2(sl);
	sl->img_anim = sl->img_anim->next;
	sl->img_anim->next = create_img_node3(sl);
}
