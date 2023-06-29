#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
	
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x0, int y0, int side_length, int color)
{
	int x, y;

	for (y = y0; y < y0 + side_length; y++)
	{
		for (x = x0; x < x0 + side_length; x++)
		{
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

int	main(void)
{
	void *mlx;
	void *mlx_win;
	int img_width;
	int img_height;
	t_data	img;
	int map[5][6] = {
		{1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 1}, 
		{1, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1}
	};
	int tile_size = 32;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//draw_square(&img, 50, 50, 100, 0x00FF0000);
	//my_mlx_pixel_put(&img, 5, 5, 0x00f0000);
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 6; x++) 
		{
			if (map[y][x] == 0)
			{
				img.img = mlx_xpm_file_to_image(mlx, "src/floor.xpm", &img_width, &img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, x * tile_size, y * tile_size);
			}
			if (map[y][x] == 1)
			{
				img.img = mlx_xpm_file_to_image(mlx, "src/wall.xpm", &img_width, &img_height);
				mlx_put_image_to_window(mlx, mlx_win, img.img, x * tile_size, y * tile_size);
			}
		}
	}
	//img.img = mlx_xpm_file_to_image(mlx, "src/floor.xpm", &img_width, &img_height);
	if (img.img == NULL)
	{
		printf("failed");
		return (1);
	}
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
