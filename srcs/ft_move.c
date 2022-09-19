/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:55:12 by aquincho          #+#    #+#             */
/*   Updated: 2022/09/19 10:55:16 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_game *game)
{
	if (game->map->map[game->player_pos - game->map->width] != '1')
	{
		game->player_pos = game->player_pos - game->map->width;
		game->move_cnt++;
		return (1);
	}
	return (0);
}

int	ft_move_down(t_game *game)
{
	if (game->map->map[game->player_pos + game->map->width] != '1')
	{
		game->player_pos = game->player_pos + game->map->width;
		game->move_cnt++;
		return (1);
	}
	return (0);
}

int	ft_move_left(t_game *game)
{
	if (game->map->map[game->player_pos - 1] != '1')
	{
		game->player_pos = game->player_pos - 1;
		game->move_cnt++;
		return (1);
	}
	return (0);
}

int	ft_move_right(t_game *game)
{
	if (game->map->map[game->player_pos + 1] != '1')
	{
		game->player_pos = game->player_pos + 1;
		game->move_cnt++;
		return (1);
	}
	return (0);
}
