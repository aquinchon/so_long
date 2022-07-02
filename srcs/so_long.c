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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello");
	img.img = mlx_new_image(mlx, 640, 480);
	img.adrr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	i = 0;
	while (++i < 31)
	{
		my_mlx_pixel_put(&img, 50 + i, 50 + i, 0x00FF0000);
		my_mlx_pixel_put(&img, 50 + i, 50 - i, 0x0000FF00);
		my_mlx_pixel_put(&img, 80, 20 + i, 0x000000FF);
		my_mlx_pixel_put(&img, 80, 80 - i, 0xFF0000FF);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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