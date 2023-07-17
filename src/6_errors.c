#include "so_long.h"

void init_error(t_map *map, char *string)
{
    free_map(map);
    ft_printf("Error\n%s\n", string);
    exit(EXIT_FAILURE);
}