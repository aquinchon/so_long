/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:25:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/08/22 12:25:39 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw_items(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		(game->player_pos % game->map->width) * 32,
		(game->player_pos / game->map->width) * 32);
}

void	ft_draw_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map->width * game->map->height)
	{
		if (game->map->map[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
		else if (game->map->map[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->item.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
		else if (game->map->map[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
				(i % game->map->width) * 32, (i / game->map->width) * 32);
	}
	ft_draw_items(game);
}
