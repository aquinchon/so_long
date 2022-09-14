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
	free (map);
}

void	ft_free_game(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	free (game);
}
