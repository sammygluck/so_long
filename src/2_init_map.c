/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:44:31 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/12 10:48:01 by sgluck           ###   ########.fr       */
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

//have a look at the failures here for leaks very possible as we exit before freeing certain things
static void	add_line_to_map(char *line, t_map *map)
{
	char	*tmp;
	char	*new_line;

	strip_newline(line);
	if (map->y == 0)
    {
        map->x = ft_strlen(line);
        map->map = ft_strdup(line);
        if (!map->map)
            init_error(map, "strdup failure");
    }
    else
    {
        tmp = map->map;
        new_line = ft_strjoin(map->map, line);
        if (ft_strlen(line) != (size_t)map->x)
            init_error(map, "the map isn't a square");
        free(tmp);
        map->map = new_line;
    }    
}

void    init_map(t_game *game)
{
    char *line;
    int fd;
    t_map *map;

    map = game->map;
    fd = open(game->filename, O_RDONLY);
    if (fd < 0)
       init_error(game->map, strerror(errno));
    map->x = 0;
    map->y = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        add_line_to_map(line, map);
        free(line);
        map->y += 1;
    }
    set_player_start_position(game);
    set_collectible_count(game);
    print_map(map);
    if(!validate_map(game))
        init_error(game->map, "map hasn't validated");
}
