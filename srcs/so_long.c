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
#include <unistd.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_win(t_vars *vars)
{
	write(1, "Bye...\n", 7);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

#include <stdio.h>
int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		i;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello");
	mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.adrr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	i = 0;
	while (++i < 31)
	{
		my_mlx_pixel_put(&img, 50 + i, 50 + i, 0x00FF0000);
		my_mlx_pixel_put(&img, 50 + i, 50 - i, 0x0000FF00);
		my_mlx_pixel_put(&img, 80, 20 + i, 0x000000FF);
		my_mlx_pixel_put(&img, 80, 80 - i, 0xFF0000FF);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

/*int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	
	if (argc != 2)
	{
		write(1, "Une seule carte possible!\n", 25);
		return (1);
	}
	(void)argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello");
	mlx_loop(mlx);
	return (0);
}
*/