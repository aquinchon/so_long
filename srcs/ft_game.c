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

static void	ft_draw_items(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map->width * game->map->height)
	{
		if (game->map->map[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->item.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
		else if (game->map->map[i] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->player.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
		else if (game->map->map[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
	}
}

static void	ft_draw_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map->width * game->map->height)
	{
		if (game->map->map[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
	}
	ft_draw_items(game);
}

int ft_kill_win(t_game *game)
{
	ft_free_mlx(game);
	free(game->mlx);
	ft_free_game(game);
	exit (0);
}

int	ft_keypress(int keycode, t_game *game)
{
	
	if (keycode == K_ESC)
		ft_kill_win(game);
	else
	{
		game->map->item_cnt--;
		printf("key %d %d %s\n", keycode, game->map->item_cnt, ft_itoa(game->map->item_cnt));
	}
	return (0);
}

int	ft_game(t_game *game)
{
	int result;

	result = ft_initialize_mlx(game);
	ft_draw_map(game);
	sleep(1);
	mlx_hook(game->win, 2, 1L << 0, ft_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, ft_kill_win, game);

	//mlx_key_hook(game->win, ft_keypress, &game);
	//mlx_mouse_hook(game->win, mouse_hook, &game);

	//mlx_string_put(game->mlx, game->win, 50, 50, 0x00FF0000, ft_itoa(game->map->item_cnt));

	mlx_loop(game->mlx);
	if (game->mlx)
		free(game->mlx);
	return (result);
}
