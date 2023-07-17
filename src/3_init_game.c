/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:44:31 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 12:41:51 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	fd;
	int	error;

	error = 1;
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
		init_error(game->map, strerror(errno));
	error = set_map(game, fd);
	set_player_start_position(game);
	set_collectible_count(game);
	if (!validate_map(game) || !error)
		init_error(game->map, "Map validation issue");
}
