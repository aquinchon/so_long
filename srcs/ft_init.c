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
	map->filename = NULL;
	map->map = ft_calloc(1, sizeof(char));
	map->fd = 0;
	map->width = 0;
	map->height = 0;
	map->pos_P = 0;
	map->pos_E = 0;
	map->item_cnt = 0;
	return (map);
}

t_game	*ft_initialize(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->mlx = NULL;
	game->map = ft_initialize_map();
	game->move_cnt = 0;
	game->width = 0;
	game->height = 0;
	game->item_collect = 0;
	return (game);
}
