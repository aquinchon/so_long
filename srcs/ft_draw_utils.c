/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:25:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/08/22 12:25:39 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_draw_size(t_map *map)
{
	(void)map;
}

/*
unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

static void	ft_draw_item(t_game *game, t_pmx *img)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < TEX_SIZE)
	{
		i = 0;
		while (i < TEX_SIZE)
		{
			color = mlx_color_value(img, i, j);
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}*/
