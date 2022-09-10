/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: super_leo <super_leo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:30:56 by super_leo         #+#    #+#             */
/*   Updated: 2022/09/10 08:36:47 by super_leo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*point_to_player_image(t_data *sl)
{
	if (sl->player.direction == 'u')
		return (sl->img_anim->p_u);
	else if (sl->player.direction == 'u')
		return (sl->img_anim->p_d);
	else if (sl->player.direction == 'r')
		return (sl->img_anim->p_r);
	else if (sl->player.direction == 'l')
		return (sl->img_anim->p_l);
	else
		return (NULL);
}

void	*point_to_image(unsigned int row, unsigned int col, t_data *sl)
{
	if (sl->map[row][col] == '1')
		return (sl->img_st.wall);
	else if (sl->map[row][col] == '0')
		return (sl->img_st.floor);
	else if (sl->map[row][col] == 'E')
		return (sl->img_st.exit);
	else if (sl->map[row][col] == 'C')
		return (sl->img_anim->col);
	else if (sl->map[row][col] == 'H')
		return (sl->img_anim->e_u);
	else if (sl->map[row][col] == 'h')
		return (sl->img_anim->e_d);
	else if (sl->map[row][col] == 'V')
		return (sl->img_anim->e_r);
	else if (sl->map[row][col] == 'v')
		return (sl->img_anim->e_l);
	else if (sl->map[row][col] == 'P')
		return (point_to_player_image(sl));
	else
		return (NULL);
}

void	*point_to_number_image(int n, t_data *sl)
{
	if (n == 0)
		return (sl->img_st.n0);
	else if (n == 1)
		return (sl->img_st.n1);
	else if (n == 2)
		return (sl->img_st.n2);
	else if (n == 3)
		return (sl->img_st.n3);
	else if (n == 4)
		return (sl->img_st.n4);
	else if (n == 5)
		return (sl->img_st.n5);
	else if (n == 6)
		return (sl->img_st.n6);
	else if (n == 7)
		return (sl->img_st.n7);
	else if (n == 8)
		return (sl->img_st.n8);
	else if (n == 9)
		return (sl->img_st.n9);
	else
		return (NULL);
}
