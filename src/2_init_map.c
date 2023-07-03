#include "so_long.h"

//is this the optimal solution?
static void strip_newline(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
            line[i] = '\0';
        i++;
    }
}

static void add_line_to_map(char *line, t_map *map)
{

    char *tmp;
    char *new_line;

    strip_newline(line);
    if (map->y == 0)
    {
        map->map = malloc(ft_strlen(line));
        //make sure we deal correctly with the error
        if (!(map->map))
            return ;
        map->x = ft_strlen(line);
        //validate the length (make sure it's the minimum required length) at least 4 if not more

        map->map = ft_strdup(line);
         //should we free line now or in the parent of this function (current implemenation: parent at the end)
         ft_printf("%i: first x\n", map->x);
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
        ft_printf("%i: subsequent x-es after\n", map->x);
    }

    //other lines
    //check if each x value is the same as first
    // join to the already existing string
    
}

void    init_map(t_map *map)
{
    
    char *line;
    int fd;

    fd = open("map.ber", O_RDONLY);
    //error check
 
    //might need to find a better place for this potentially:
    map->x = 0;
    map->y = 0;
    
    //call gnl until end
    //for every call we'll join unto the previous string
    //we also have to differentiate between the first, last and rest of the strings
    while (1)
    {
       
        line = get_next_line(fd);
        if (!line)
            break;
        add_line_to_map(line, map);
        free(line);
        //make sure to add to the y value each time
        map->y += 1;
    }
}