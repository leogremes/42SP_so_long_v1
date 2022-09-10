/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:32:07 by super_leo         #+#    #+#             */
/*   Updated: 2022/09/10 13:04:41 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player(int row_dst, int col_dst, t_data *sl)
{
    sl->map[row_dst][col_dst] = 'P';
    sl->map[sl->player.row][sl->player.col] = '0';
    sl->player.row = row_dst;
    sl->player.col = col_dst;
    sl->moves++;
}

static void check_player_movement(int row_dst, int col_dst, t_data *sl)
{
    char    c;

    c = sl->map[row_dst][col_dst];
    if (c == '0')
        move_player(row_dst, col_dst, sl);
    else if (c == 'C')
    {
        move_player(row_dst, col_dst, sl);
        sl->collectibles--;
    }
    else if (c == 'E')
    {
        if (sl->collectibles == 0)
            close_game(sl);
    }
    else if (c == 'h' || c == 'H' || c == 'v' || c == 'V')
            close_game(sl);
}

int keypress_handler(int keycode, t_data *sl)
{
    if (keycode == KEY_W || keycode == KEY_UP)
    {
        sl->player.direction = 'u';
        check_player_movement(sl->player.row - 1, sl->player.col, sl);
    }
    else if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        sl->player.direction = 'd';
        check_player_movement(sl->player.row + 1, sl->player.col, sl);
    }
    else if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        sl->player.direction = 'l';
        check_player_movement(sl->player.row, sl->player.col - 1, sl);
    }
    else if (keycode == KEY_D|| keycode == KEY_RIGHT)
    {
        sl->player.direction = 'r';
        check_player_movement(sl->player.row, sl->player.col + 1, sl);
    }
    else if (keycode == KEY_ESC)
        close_game(sl);
    return (0);
}