/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_map_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:37:36 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 14:39:29 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_to_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		game_exit_failure(game, "mlx_init failure");
	game->mlx_win = mlx_new_window(game->mlx, game->map->x * 32,
			game->map->y * 32, "so_long");
	if (!game->mlx_win)
		game_exit_failure(game, "mlx_win failure");
	set_image_values(game->mlx, &(game->images));
	check_images(game);
	place_images(game, game->map);
	mlx_key_hook(game->mlx_win, hook_actions, game);
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, place_images_loop, game);
	mlx_loop(game->mlx);
}
