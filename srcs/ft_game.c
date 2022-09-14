/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:27:08 by aquincho          #+#    #+#             */
/*   Updated: 2022/07/02 11:28:11 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_win(t_game *game)
{
	printf("destroy\n");
	//write(1, "Bye...\n", 7);
	mlx_destroy_image(game->mlx, game->wall.img);
	//mlx_destroy_window(game->mlx, game->img.img);
	printf("images\n");
	mlx_destroy_window(game->mlx, game->win);
	printf("windows\n");
	mlx_destroy_display(game->mlx);
	printf("display\n");
	exit (0);
}

int	keypress(int keycode, t_game *game)
{
	
	if (keycode == K_ESC)
	{
		printf("%d\n", keycode);
		close_win(game);
	}
	game->map->item_cnt--;
	printf("key %d %d %s\n", keycode, game->map->item_cnt, ft_itoa(game->map->item_cnt));
	return (0);
}

void draw(t_img *img, t_game game)
{
	int	i;

	i = 0;
	while (++i < 31)
	{
		my_mlx_pixel_put(img, game.pos + i, game.pos + i, 0x00FF0000);
		my_mlx_pixel_put(img, game.pos + i, game.pos - i, 0x0000FF00);
		my_mlx_pixel_put(img, game.pos + 30, game.pos - 30 + i, 0x000000FF);
		my_mlx_pixel_put(img, game.pos + 30, game.pos + 30 - i, 0xFF0000FF);
	}
}

int	mouse_hook(int button, int x, int y, t_game *game)
{
	if (button == 1)
		printf("%d, %d\n", x, y);
	if (button == 2)
	{
		//mlx_destroy_image(game->mlx, &game->img);
		//mlx_clear_window(game->mlx, game->win);
		game->pos = 200;
		//draw(&game->img, game);
		//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	return (0);
}

int	render_next_frame(t_game *game)
{
	//mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, 300, 300);
	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, 100, 100);
	draw(&game->img, *game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	ft_game(t_game *game)
{

	game->width = game->map->width * TEX_SIZE;
	game->height = game->map->height * TEX_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "So_long");
	mlx_hook(game->win, 17, 1L << 17, close_win, &game);
	mlx_key_hook(game->win, keypress, &game);
	//mlx_hook(game->win, 2, 1L << 0, keypress, &game);
	mlx_mouse_hook(game->win, mouse_hook, &game);
	//draw(&game);
	game->img.img = mlx_new_image(game->mlx, 640, 480);
	game->img.adrr = mlx_get_data_addr(game->img.img, &game->img.bpp,
		&game->img.line_len, &game->img.endian);
	// draw(&game->img, game);
	game->wall.rel_path = "./img/wall.xpm";
	game->wall.img = mlx_xpm_file_to_image(game->mlx, game->wall.rel_path,
		&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		printf("png fail\n");

	game->pos = 200;
	//draw(&game->img, *game);
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	//sleep (3);
	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, 100, 100);
	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, 300, 300);
	mlx_string_put(game->mlx, game->win, 50, 50, 0x00FF0000, ft_itoa(game->map->item_cnt));
	
	
	
	//sleep (3);
	//free (game->img.img);
	//mlx_loop_hook(game->mlx, render_next_frame, &game);
	mlx_loop(game->mlx);
	return (0);
}
