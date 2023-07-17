/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_validate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:40:10 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 13:41:03 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (!validate_borders(map))
		return (0);
	if (!validate_contents(map))
		return (0);
	if (!check_all_reachable(game))
		return (0);
	return (1);
}
