/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4a_validate_borders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:46:23 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 13:46:26 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_borders(t_map *map)
{
	int		y;
	int		x;
	char	current_value;

	y = 1;
	while (y <= map->y)
	{
		x = 1;
		while (x <= map->x)
		{
			current_value = get_value(map, x, y);
			if (y == 1 && current_value != '1')
				return (0);
			else if (y == map->y && current_value != '1')
				return (0);
			else if (x == 1 && current_value != '1')
				return (0);
			else if (x == map -> x && current_value != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	print_map(t_map *map)
{
	int	y;
	int	x;

	y = 1;
	while (y <= map->y)
	{
		x = 1;
		while (x <= map->x)
		{
			ft_printf("%c", get_value(map, x, y));
			x++;
		}
		y++;
		ft_printf("\n");
	}
	return (1);
}
