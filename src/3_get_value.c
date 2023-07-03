#include "so_long.h"

char get_value(t_map *map, int x, int y)
{
    char value;
    int index;

    index = y * map->x + x;
    value = map->map[index];
    return (value);
}