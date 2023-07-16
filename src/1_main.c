/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:37:41 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/12 10:37:44 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	check_input(argc, argv);
	map = malloc(sizeof (t_map));
	if (!map)
		init_error(map, "malloc map");
	game.map = map;
	game.filename = argv[1];
	init_map(&game);
	map_to_window(&game);
	ft_printf("\ndatamap: %s", game.map->map);
    //map_to_window();
}
