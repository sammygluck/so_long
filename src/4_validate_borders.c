#include "so_long.h"

int validate_borders(t_map *map)
{
    int y;
    int x;
    char current_value;

    y = 1;

    while(y <= map->y)
    {
        x = 1;
        while(x <= map->x)
        {
            current_value = get_value(map, x, y);
            if (y == 1 && current_value != '1')
                return (1);
            else if (y == map->y && current_value != '1')
                return (1);
            else if (x == 1 && current_value != '1')
                return (1);
            else if (x == map -> x && current_value != '1')
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}





int print_map(t_map *map)
{
    int y;
    int x;

    y = 1;

    while(y <= map->y)
    {
        x = 1;
        while(x <= map->x)
        {
            ft_printf("%c", get_value(map, x, y));
            x++;
        }
        y++;
        ft_printf("\n");
    }
    return (1);
}