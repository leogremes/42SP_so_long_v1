/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:01:20 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/11 16:03:19 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "defines.h"

typedef struct s_char
{
	char			direction;
	unsigned int	row;
	unsigned int	col;
	struct s_char	*next;
}	t_char;

typedef struct s_img_anim
{
	void				*p_u;
	void				*p_d;
	void				*p_l;
	void				*p_r;
	void				*e_u;
	void				*e_d;
	void				*e_r;
	void				*e_l;
	void				*col;
	struct s_img_anim	*next;
}	t_img_anim;

typedef struct s_img_st
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*moves;
	void	*n0;
	void	*n1;
	void	*n2;
	void	*n3;
	void	*n4;
	void	*n5;
	void	*n6;
	void	*n7;
	void	*n8;
	void	*n9;
}	t_img_st;

typedef struct s_data
{
	void					*mlx;
	void					*win;
	t_img_st				img_st;
	t_img_anim				*img_anim;
	t_img_anim				*img_head;
	unsigned int			comment;
	unsigned int			rows;
	unsigned int			cols;
	unsigned int			starts;
	unsigned int			collectibles;
	unsigned int			exits;
	char					**map;
	t_char					player;
	t_char					*enemies;
	unsigned int			moves;
	unsigned int			anim_tick;
	unsigned int			enem_tick;
}	t_data;

//SRC FUNCTIONS
int		file_check(t_data *sl, char *file);
int		validate_map(t_data *sl);
void	free_map(t_data *sl);
void	create_enemy(t_data *sl, unsigned int row, unsigned int col);
void	free_enemies_list(t_data *sl);
void	get_animated_nodes(t_data *sl);
void	get_images(t_data *sl);
int		screen_update(t_data *sl);
int		closed_by_user(t_data *sl);
void	win_game(t_data *sl);
void	lose_game(t_data *sl);
void	*point_to_image(unsigned int row, unsigned int col, t_data *sl);
void	*point_to_number_image(int n, t_data *sl);
int		keypress_handler(int keycode, t_data *sl);
void	enemies_movement(t_data *sl);
void	destroy_window(t_data *sl);
void	free_static_images(t_data *sl);
void	free_animated_images(t_data *sl);

//UTILS FUNCTIONS
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strappend(char *s, char c);
char	**ft_split(const char *s, char c);
size_t	ft_nbrlen(int n);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);

#endif