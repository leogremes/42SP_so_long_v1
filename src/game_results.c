/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_results.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:54:37 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/11 16:57:14 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void close_game(t_data *sl)
{
	destroy_window(sl);
	free_static_images(sl);
	free_animated_images(sl);
	free_map(sl);
	free_enemies_list(sl);
}

int closed_by_user(t_data *sl)
{
    ft_putendl("Game closed by user!");
    close_game(sl);
    return (0);
}

void win_game(t_data *sl)
{
    ft_putchar('\n');
    ft_putstr(WIN_COLOR);
    ft_putendl("██╗   ██╗   ██████╗   ██╗   ██╗\
          ██╗    ██╗  ██╗  ███╗   ██╗  ██╗");
    ft_putendl("╚██╗ ██╔╝  ██╔═══██╗  ██║   ██║\
          ██║    ██║  ██║  ████╗  ██║  ██║");
    ft_putendl(" ╚████╔╝   ██║   ██║  ██║   ██║\
          ██║ █╗ ██║  ██║  ██╔██╗ ██║  ██║");
    ft_putendl("  ╚██╔╝    ██║   ██║  ██║   ██║\
          ██║███╗██║  ██║  ██║╚██╗██║  ╚═╝");
    ft_putendl("   ██║     ╚██████╔╝  ╚██████╔╝\
          ╚███╔███╔╝  ██║  ██║ ╚████║  ██╗");
    ft_putstr("   ╚═╝      ╚═════╝    ╚═════╝\
            ╚══╝╚══╝   ╚═╝  ╚═╝  ╚═══╝  ╚═╝");
    ft_putendl(DEF_COLOR);
    ft_putchar('\n');
    close_game(sl);
}

void    lose_game(t_data *sl)
{
    ft_putchar('\n');
    ft_putstr(LOSE_COLOR);
    ft_putendl("██╗   ██╗   ██████╗   ██╗   ██╗\
          ██╗        ██████╗   ███████╗  ███████╗  ██╗");
    ft_putendl("╚██╗ ██╔╝  ██╔═══██╗  ██║   ██║\
          ██║       ██╔═══██╗  ██╔════╝  ██╔════╝  ██║");
    ft_putendl(" ╚████╔╝   ██║   ██║  ██║   ██║\
          ██║       ██║   ██║  ███████╗  █████╗    ██║");
    ft_putendl("  ╚██╔╝    ██║   ██║  ██║   ██║\
          ██║       ██║   ██║  ╚════██║  ██╔══╝    ╚═╝");
    ft_putendl("   ██║     ╚██████╔╝  ╚██████╔╝\
          ███████╗  ╚██████╔╝  ███████║  ███████╗  ██╗");
    ft_putstr("   ╚═╝      ╚═════╝    ╚═════╝\
           ╚══════╝   ╚═════╝   ╚══════╝  ╚══════╝  ╚═╝");
    ft_putendl(DEF_COLOR);
    ft_putchar('\n');
    close_game(sl);
}
