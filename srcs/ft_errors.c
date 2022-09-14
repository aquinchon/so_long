/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:00:22 by aquincho          #+#    #+#             */
/*   Updated: 2022/07/03 18:00:26 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_arg(char *msg)
{
	write(2, "\033[33;31mError\n", 14);
	write(2, msg, ft_strlen(msg));
	write(2, "\033[33;37m\n", 9);
	exit (1);
}

int	ft_errors_free(char *msg, t_game *game)
{
	write(2, "\033[33;31mError\n", 14);
	write(2, msg, ft_strlen(msg));
	write(2, "\033[33;37m\n", 9);
	ft_free_game(game);
	return (1);
}

int	ft_errors(char *msg)
{
	write(2, "\033[33;31mError\n", 14);
	write(2, msg, ft_strlen(msg));
	write(2, "\033[33;37m\n", 9);
	return (1);
}
