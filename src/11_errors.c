#include "so_long.h"

void init_error(t_map *map, char *string)
{
    free_map(map);
    ft_printf("Error\n%s\n", string);
    exit(EXIT_FAILURE);
}

void add_line_error(char *line, char *newline, t_map *map)
{
    free(line);
    if (newline)
        free(newline);
    free_map(map);
    ft_printf("Error\nmap creation error");
    exit(EXIT_FAILURE);
}