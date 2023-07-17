#include "so_long.h"

char get_value(t_map *map, int x, int y)
{
    char value;
    int index;

    //what's if it's zero or less??
    index = (y - 1) * map->x + (x - 1);
    value = map->map[index];
    return (value);
}

void set_value(t_map *map, char value, int x, int y)
{
    int index;

    index = (y - 1) * map->x + (x - 1);
    map->map[index] = value;
}

