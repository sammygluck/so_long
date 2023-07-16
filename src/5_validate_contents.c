#include "so_long.h"

int get_char_count(char *string, char character)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (string[i])
    {
        if (string[i] == character)
            count++;
        i++;
    }
    return (count);
}

static int all_valid_char(char *string)
{
    int i;

    i = 0;
    while (string[i])
    {
        if(!ft_strchr("CEP10", string[i]))
            return (0);
        i++;
    }
    return (1);
}

int validate_contents(t_map *map)
{
    if (!map->map)
        return (0);
    if (!all_valid_char(map->map))
        return (0);
    if (get_char_count(map->map, 'C') < 1)
        return (0);
    if (get_char_count(map->map, 'E') != 1)
        return (0);
    if (get_char_count(map->map, 'P') != 1)
        return (0);
    return (1);

}

int validate_map(t_game *game)
{
    t_map *map;

    map = game->map;
    if (!validate_borders(map))
        return (0);
    if (!validate_contents(map))
        return (0);
    if (!check_all_reachable(game))
        return (0);
    return (1);
}