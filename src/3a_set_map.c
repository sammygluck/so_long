/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3a_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:47:49 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 12:47:52 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	strip_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

static int	add_line_to_map(char *line, t_map *map)
{
	int		error;
	char	*tmp;
	char	*new_line;

	error = 1;
	new_line = NULL;
	strip_newline(line);
	if (map->y == 0)
	{
		map->x = ft_strlen(line);
		map->map = ft_strdup(line);
		if (!map->map)
			error = 0;
	}
	else
	{
		tmp = map->map;
		new_line = ft_strjoin(map->map, line);
		if (ft_strlen(line) != (size_t)map->x || !new_line)
			error = 0;
		free(tmp);
		map->map = new_line;
	}
	return (error);
}

int	set_map(t_game *game, int fd)
{
	int		error;
	t_map	*map;
	char	*line;

	error = 1;
	map = game->map;
	map->x = 0;
	map->y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line_to_map(line, map))
			error = 0;
		free(line);
		map->y += 1;
	}
	return (error);
}
