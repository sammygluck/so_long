/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3c_map_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:29:58 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/02 06:56:33 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_value(t_map *map, int x, int y)
{
	int		index;
	char	value;

	index = (y - 1) * map->x + (x - 1);
	value = map->map[index];
	return (value);
}

void	set_value(t_map *map, char value, int x, int y)
{
	int	index;

	index = (y - 1) * map->x + (x - 1);
	map->map[index] = value;
}
