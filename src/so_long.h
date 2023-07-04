#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../mlx_linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
    char *map;
    int x;
    int y;
} t_map;

void    init_map(t_map *map);
char get_value(t_map *map, int x, int y);
int print_map(t_map *map);
int validate_borders(t_map *map);
int validate_contents(t_map *map);
void check_input(int argc, char **argv);

#endif