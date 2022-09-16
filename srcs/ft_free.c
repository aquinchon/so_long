/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:37:42 by aquincho          #+#    #+#             */
/*   Updated: 2022/07/04 11:37:44 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_doubleptr(void **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

void	ft_free_map(t_map *map)
{
	if (map->filename)
		free(map->filename);
	if (map->map)
		free(map->map);
	if (map->fd > 0)
		close(map->fd);
	if (map)
		free (map);
}

void	ft_free_mlx(t_game *game)
{
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->ground.img)
		mlx_destroy_image(game->mlx, game->ground.img);
	if (game->item.img)
		mlx_destroy_image(game->mlx, game->item.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	//free(game->mlx);
}

void	ft_free_game(t_game *game)
{
	/*if (game->mlx)
		ft_free_mlx(game);*/
	if (game->map)
		ft_free_map(game->map);
	free (game);
}
