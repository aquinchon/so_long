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

static void	ft_put_info(t_game *game)
{
	write(1, "Number of moves: ", 17);
	ft_putnbr_fd(game->move_cnt, 1);
	write(1, " Collected items: ", 18);
	ft_putnbr_fd(game->item_collect, 1);
	write(1, " / ", 3);
	ft_putnbr_fd(game->map->item_cnt, 1);
	write(1, "\r", 1);
}

static void	ft_update(t_game *game)
{
	if (game->map->map[game->player_pos] == 'C')
	{
		game->item_collect++;
		game->map->map[game->player_pos] = '0';
	}
	if (game->map->map[game->player_pos] == 'E')
	{
		ft_put_info(game);
		if (game->item_collect == game->map->item_cnt)
		{
			write(1, "\n", 1);
			write(1, "\033[33;32mYOU WIN!!!", 19);
			write(1, "\033[33;37m\n", 9);
		}
		else
		{
			write(1, "\n", 1);
			write(1, "\033[32;31mYou forgot some items!", 30);
			write(1, "\033[33;37m\n", 9);
		}
		ft_kill_win(game);
	}
	ft_put_info(game);
	ft_draw_map(game);
}

static int	ft_keypress(int keycode, t_game *game)
{
	int	player_move;

	if (keycode == K_ESC)
		ft_kill_win(game);
	else
	{
		if (keycode == K_UP || keycode == 119)
			player_move = ft_move_up(game);
		if (keycode == K_DN || keycode == 115)
			player_move = ft_move_down(game);
		if (keycode == K_LT || keycode == 97)
			player_move = ft_move_left(game);
		if (keycode == K_RT || keycode == 100)
			player_move = ft_move_right(game);
		if (player_move)
			ft_update(game);
	}
	return (0);
}

int	ft_game(t_game *game)
{
	int	result;

	result = ft_initialize_mlx(game);
	ft_draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, ft_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, ft_kill_win, game);
	mlx_loop(game->mlx);
	if (game->mlx)
		free(game->mlx);
	return (result);
}
