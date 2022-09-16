#include "so_long.h"

int ft_free(t_game *game)
{
	int res;

	res = 0;
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	return (res);
}

int	ft_init(t_game *game)
{
	int res;
	
	res = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		printf("mlx");
	game->win = mlx_new_window(game->mlx, 640, 480, "test");
	if (!game->win)
		printf("win");
	
	game->img.img = mlx_new_image(game->mlx, 640, 480);
	if (!game->img.img)
		printf("img");
	return (res);
}

int	main(int argc, char *argv[])
{

	t_game *game;
	int res;
	
	(void)argv;
	if (!argc)
		return (0);
	res = 0;
	game = malloc(sizeof(t_game));
	res = ft_init(game);
	sleep (2);
	res = ft_free(game);
	
	//free(game);
	mlx_loop(game->mlx);
	
	free(game->mlx);
	free(game);
	printf("fin\n");
	return (res);
}