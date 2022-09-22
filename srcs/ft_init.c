/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:08:22 by aquincho          #+#    #+#             */
/*   Updated: 2022/08/22 14:08:26 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_initialize_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->filename = NULL;
	map->map = ft_calloc(1, sizeof(char));
	if (!map->map)
		return (NULL);
	map->fd = 0;
	map->width = 0;
	map->height = 0;
	map->pos_p = 0;
	map->pos_e = 0;
	map->item_cnt = 0;
	return (map);
}

t_game	*ft_initialize(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_errors_game("Cannot initialize game", NULL);
	game->mlx = NULL;
	game->win = NULL;
	game->map = ft_initialize_map();
	if (!game->map)
		ft_errors_game("Cannot initialize map", game);
	game->move_cnt = 0;
	game->width = 0;
	game->height = 0;
	game->item_collect = 0;
	game->wall.img = NULL;
	game->ground.img = NULL;
	game->player.img = NULL;
	game->item.img = NULL;
	game->exit.img = NULL;
	return (game);
}
