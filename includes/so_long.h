/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:28:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/07/02 11:29:24 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

typedef struct	s_data
{
	void	*img;
	char	*adrr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

#endif
