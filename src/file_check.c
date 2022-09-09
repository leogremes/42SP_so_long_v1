/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:30:48 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/08 23:12:10 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_element_counter(char *c, t_data *sl)
{
	if (*c == 'C')
		sl->collectibles++;
	else if (*c == 'E')
		sl->exits++;
	else if (*c == 'P')
	{
		if (sl->starts == 0)
			sl->starts++;
		else
			*c = '0';
	}
	else if (*c == '#')
		sl->comment = 1;
}

static int	read_map(int fd, t_data *sl)
{
	char	*map_str;
	char	buffer;

	map_str = NULL;
	while (read(fd, &buffer, 1) > 0)
	{
		if ((sl->comment == 0 || buffer == '\n') && buffer != ' ')
		{
			map_element_counter(&buffer, sl);
			if (buffer != '#')
				map_str = ft_strappend(map_str, buffer);
		}
		if (sl->comment == 1 && buffer == '\n')
			sl->comment = 0;
	}
	if (sl->starts == 0 || sl->collectibles == 0 || sl->exits == 0)
	{
		ft_putendl("Error!\nInvalid map. Some elements are missing!");
		free(map_str);
		return (1);
	}
	sl->map = ft_split(map_str, '\n');
	free(map_str);
	close (fd);
	return (validate_map(sl));
}

int	file_check(t_data *sl, char *file)
{
	int		fd;
	char	*path;

	if (ft_strstr(file, ".ber\0") == NULL)
	{
		ft_putendl("Error!\nNot a .ber file!");
		return (1);
	}
	path = ft_strjoin("./maps/", file);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
	{
		ft_putendl("Error!\nCouldn't open this file");
		return (1);
	}
	return (read_map(fd, sl));
}
