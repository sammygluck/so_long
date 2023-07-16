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

//is this the optimal solution?
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

static void	add_line_to_map(char *line, t_map *map)
{
	char	*tmp;
	char	*new_line;

	strip_newline(line);
	if (map->y == 0)
    {
        // //make sure we deal correctly with the error
        // if (!(map->map))
        //     return ;
        map->x = ft_strlen(line);
        //validate the length (make sure it's the minimum required length) at least 4 if not more
        map->map = ft_strdup(line);
         //should we free line now or in the parent of this function (current implemenation: parent at the end)
    }
    else
    {
        tmp = map->map;
        new_line = ft_strjoin(map->map, line);
        // need to cook a correct error formula for this
        if (ft_strlen(line) != (size_t)map->x)
            ft_printf("Error: x length not equal");
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
    fd = open("map.ber", O_RDONLY);
    //error check
 
    //might need to find a better place for this potentially:
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
        ft_printf("something wrong with map\n");
}
