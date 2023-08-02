/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5a_image_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:00:58 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/02 07:16:47 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	place_images(t_game *game, t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			setup_image(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	place_images_loop(t_game *game)
{
	place_images(game, game->map);
	return (0);
}
