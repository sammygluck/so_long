/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5d_game_exit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:14:50 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 15:16:57 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_game *game)
{
	int	count;

	count = game->col.total;
	ft_printf("YOU WON!!!!\nYou've collected all %i collectibles\n", count);
	game_exit_success(game);
}

int	destroy_images(t_game *game)
{
	if (game->images.collectible)
		mlx_destroy_image(game->mlx, game->images.collectible);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.floor)
		mlx_destroy_image(game->mlx, game->images.floor);
	if (game->images.player)
		mlx_destroy_image(game->mlx, game->images.player);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	return (0);
}

void	free_map(t_map *map)
{
	if (map->map)
		free(map->map);
	if (map)
		free(map);
}
