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

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc < 2)
		ft_error_arg("A map is needed.");
	else if (argc > 2)
		ft_error_arg("More than one map.");
	game = ft_initialize();
	if (ft_read_map(argv[1], game->map))
	{
		ft_free_game(game);
		return (0);
	}
	//FOR MAP TESTING
	if (game->map != NULL)
		printf("w: %d - h: %d\nP: %d (%d, %d) - E: %d (%d, %d) item: %d\n%s\n",
			game->map->width, game->map->height, game->map->pos_P, game->map->pos_P % game->map->width,
			game->map->pos_P / game->map->width, game->map->pos_E, game->map->pos_E % game->map->width,
			game->map->pos_E / game->map->width, game->map->item_cnt, game->map->map);
	ft_game(game);
	//ft_free_game(game);
	return (0);
}
