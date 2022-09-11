/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:00:50 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/11 15:47:39 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_enemy(unsigned int row_dst, unsigned int col_dst,
    t_data *sl, t_char *enemy)
{
    char    c;

    if (enemy->direction == 'u')
        c = 'V';
    else if (enemy->direction == 'd')
        c = 'v';
    else if (enemy->direction == 'r')
        c = 'H';
    else
        c = 'h';
    
    sl->map[row_dst][col_dst] = c;
    sl->map[enemy->row][enemy->col] = '0';
    enemy->row = row_dst;
    enemy->col = col_dst;
}

static void change_direction(t_data *sl, t_char *enemy)
{
    if (enemy->direction == 'u')
    {
        enemy->direction = 'd';
        sl->map[enemy->row][enemy->col] = 'v';
    }
    else if (enemy->direction == 'd')
    {
        enemy->direction = 'u';
        sl->map[enemy->row][enemy->col] = 'V';
    }
    else if (enemy->direction == 'r')
    {
        enemy->direction = 'l';
        sl->map[enemy->row][enemy->col] = 'h';
    }
    else if (enemy->direction == 'l')
    {
        enemy->direction = 'r';
        sl->map[enemy->row][enemy->col] = 'H';
    }
}

static int check_enemy_move(unsigned int row_dst, unsigned int col_dst,
    t_data *sl, t_char *enemy)
{
    if (sl->map[row_dst][col_dst] == '0')
        move_enemy(row_dst, col_dst, sl, enemy);
    else if (sl->map[row_dst][col_dst] == 'P')
    {
        lose_game(sl);
        return (1);
    }
    else
        change_direction(sl, enemy);
    return (0);
}

void    enemies_movement(t_data *sl)
{
    t_char  *tmp;
    int     end_game;

    if (sl->enemies)
    {
        end_game = 0;
        tmp = sl->enemies;
        while (tmp && !end_game)
        {
            if (tmp->direction == 'u')
                end_game = check_enemy_move(tmp->row - 1, tmp->col, sl, tmp);
            else if (tmp->direction =='d')
                end_game = check_enemy_move(tmp->row + 1, tmp->col, sl, tmp);
            else if (tmp->direction == 'r')
                end_game = check_enemy_move(tmp->row, tmp->col + 1, sl, tmp);
            else
                end_game = check_enemy_move(tmp->row, tmp->col - 1, sl, tmp);
            if (!end_game)
                tmp = tmp->next;
        }
    }
}