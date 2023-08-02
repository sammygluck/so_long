/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5ab_image_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 07:25:29 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/02 07:25:34 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_game *game)
{
	t_img_types	images;

	images = game->images;
	if (!images.collectible || !images.exit || !images.floor || !images.player
		|| !images.wall)
		game_exit_failure(game, "failure to setup images");
}

void	open_exit(t_game *game)
{
	t_img_types	*images;
	int			w;
	int			h;

	images = &(game->images);
	mlx_destroy_image(game->mlx, game->images.exit);
	images->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/open-exit.xpm", &w, &h);
	if (!images->exit)
		game_exit_failure(game, "failure to setup open exit");
	game->exit_open = 1;
}

void	set_image_values(void *mlx, t_img_types *images)
{
	int	width;
	int	height;

	images->player = mlx_xpm_file_to_image(mlx,
			"assets/sprites/player/front.xpm", &width, &height);
	images->collectible = mlx_xpm_file_to_image(mlx,
			"assets/sprites/coin-bag.xpm", &width, &height);
	images->exit = mlx_xpm_file_to_image(mlx,
			"assets/sprites/exit-closed.xpm", &width, &height);
	images->floor = mlx_xpm_file_to_image(mlx,
			"assets/sprites/floor.xpm", &width, &height);
	images->wall = mlx_xpm_file_to_image(mlx,
			"assets/sprites/wall.xpm", &width, &height);
}

void	setup_image(t_game *game, int x, int y)
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_img_types	images;

	mlx = game->mlx;
	mlx_win = game->mlx_win;
	images = game->images;
	map = game->map;
	if (get_value(map, x + 1, y + 1) == '1')
		mlx_put_image_to_window(mlx, mlx_win, images.wall, x * 32, y * 32);
	else if (get_value(map, x + 1, y + 1) == '0')
		mlx_put_image_to_window(mlx, mlx_win, images.floor, x * 32, y * 32);
	else if (get_value(map, x + 1, y + 1) == 'C')
		mlx_put_image_to_window(mlx, mlx_win, images.collectible,
			x * 32, y * 32);
	else if (get_value(map, x + 1, y + 1) == 'P')
		mlx_put_image_to_window(mlx, mlx_win, images.player, x * 32, y * 32);
	else if (get_value(map, x + 1, y + 1) == 'E')
		mlx_put_image_to_window(mlx, mlx_win, images.exit, x * 32, y * 32);
	else
		ft_printf("error setup image %c\n", get_value(map, x, y));
}
