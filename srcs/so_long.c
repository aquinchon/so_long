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
	ft_game(game);
	if (game)
		ft_free_game(game);
	return (0);
}
