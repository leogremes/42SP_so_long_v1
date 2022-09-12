/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:46:27 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/12 13:48:02 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_static_images(t_data *sl)
{
	mlx_destroy_image(sl->mlx, sl->img_st.floor);
	mlx_destroy_image(sl->mlx, sl->img_st.wall);
	mlx_destroy_image(sl->mlx, sl->img_st.exit);
	mlx_destroy_image(sl->mlx, sl->img_st.moves);
	mlx_destroy_image(sl->mlx, sl->img_st.n0);
	mlx_destroy_image(sl->mlx, sl->img_st.n1);
	mlx_destroy_image(sl->mlx, sl->img_st.n2);
	mlx_destroy_image(sl->mlx, sl->img_st.n3);
	mlx_destroy_image(sl->mlx, sl->img_st.n4);
	mlx_destroy_image(sl->mlx, sl->img_st.n5);
	mlx_destroy_image(sl->mlx, sl->img_st.n6);
	mlx_destroy_image(sl->mlx, sl->img_st.n7);
	mlx_destroy_image(sl->mlx, sl->img_st.n8);
	mlx_destroy_image(sl->mlx, sl->img_st.n9);
}

static void	free_animated_node(t_img_anim *node, t_data *sl)
{
	mlx_destroy_image(sl->mlx, node->p_u);
	mlx_destroy_image(sl->mlx, node->p_d);
	mlx_destroy_image(sl->mlx, node->p_r);
	mlx_destroy_image(sl->mlx, node->p_l);
	mlx_destroy_image(sl->mlx, node->e_u);
	mlx_destroy_image(sl->mlx, node->e_d);
	mlx_destroy_image(sl->mlx, node->e_r);
	mlx_destroy_image(sl->mlx, node->e_l);
	mlx_destroy_image(sl->mlx, node->col);
}

void	free_animated_images(t_data *sl)
{
	t_img_anim	*tmp;

	sl->img_anim = NULL;
	while (sl->img_head)
	{
		tmp = sl->img_head->next;
		free_animated_node(sl->img_head, sl);
		free(sl->img_head);
		sl->img_head = tmp;
	}
}
