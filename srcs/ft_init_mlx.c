/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:08:22 by aquincho          #+#    #+#             */
/*   Updated: 2022/08/22 14:08:26 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_file(char *path, t_game *game)
{
	int	result;
	int	tmp_fd;

	result = 0;
	tmp_fd = open(path, O_RDONLY);
	if (tmp_fd > 0)
		close (tmp_fd);
	else
	{
		result = ft_errors_free("Fichier image introuvable.", game);
	}
	return (result);
}

static int	ft_initialize_items(t_game *game)
{
	int	result;

	result = ft_check_file("./img/dragon.xpm", game);
	game->player.rel_path = "./img/dragon.xpm";
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			game->player.rel_path, &game->player.width,
			&game->player.height);
	result = ft_check_file("./img/snake.xpm", game);
	if (!result)
	{
		game->item.rel_path = "./img/snake.xpm";
		game->item.img = mlx_xpm_file_to_image(game->mlx, game->item.rel_path,
				&game->item.width, &game->item.height);
	}
	result = ft_check_file("./img/door.xpm", game);
	if (!result)
	{
		game->exit.rel_path = "./img/door.xpm";
		game->exit.img = mlx_xpm_file_to_image(game->mlx, game->exit.rel_path,
				&game->exit.width, &game->exit.height);
	}
	return (result);
}

static int	ft_initialize_texture(t_game *game)
{
	int	result;

	result = ft_check_file("./img/wall.xpm", game);
	if (!result)
	{	
		game->wall.rel_path = "./img/wall.xpm";
		game->wall.img = mlx_xpm_file_to_image(game->mlx, game->wall.rel_path,
				&game->wall.width, &game->wall.height);
	}
	result = ft_check_file("./img/sand.xpm", game);
	if (!result)
	{
		game->ground.rel_path = "./img/sand.xpm";
		game->ground.img = mlx_xpm_file_to_image(game->mlx,
				game->ground.rel_path, &game->ground.width,
				&game->ground.height);
	}
	if (!result)
		result = ft_initialize_items(game);
	return (result);
}

int	ft_initialize_mlx(t_game *game)
{
	int	result;

	result = 0;
	game->width = game->map->width * TEX_SIZE;
	game->height = game->map->height * TEX_SIZE;
	game->player_pos = game->map->pos_p;
	if (!result)
		game->mlx = mlx_init();
	if (!game->mlx && !result)
		result = ft_errors_free("Cannot initialize mlx.", game);
	if (!result)
		game->win = mlx_new_window(game->mlx, game->width,
				game->height, "So_long");
	if (!game->win && !result)
		result = ft_errors_free("Cannot create window.", game);
	if (!result)
		game->img.img = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img.img && !result)
		result = ft_errors_free("Cannot create image.", game);
	else
		game->img.adrr = mlx_get_data_addr(game->img.img, &game->img.bpp,
				&game->img.line_len, &game->img.endian);
	if (!result)
		result = ft_initialize_texture(game);
	return (result);
}
