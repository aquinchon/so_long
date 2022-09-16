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

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>
//# include <mlx_int.h>

#include <stdio.h>

# define K_ESC	65307
# define K_LT	65361
# define K_UP	65362
# define K_RT	65363
# define K_DN	65364

# define TEX_SIZE	32

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char	*filename;
	int		fd;
	char	*map;
	int		width;
	int		height;
	int		pos_P;
	int		pos_E;
	int		item_cnt;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*adrr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_pmx
{
	void	*img;
	char	*rel_path;
	int		width;
	int		height;
}	t_pmx;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	t_pmx	wall;
	t_pmx	ground;
	t_pmx	player;
	t_pmx	item;
	t_pmx	exit;
	int		move_cnt;
	int		item_collect;
	int		player_pos;
}	t_game;

/* Errors management ft_errors.c */
int		ft_error_arg(char *msg);
int		ft_errors_free(char *msg, t_game *game);
int		ft_errors(char *msg);
/* Free management ft_free.c*/
void	ft_free_map(t_map *map);
void	ft_free_mlx(t_game *game);
void	ft_free_game(t_game *game);
/* Initialization ft_init.c */
t_map	*ft_initialize_map(void);
t_game	*ft_initialize(void);
/* Initialization mlx ft_init_mlx.c */
int		ft_initialize_mlx(t_game *game);
/* Map reading ft_map.c*/
int		ft_read_map(char *filename, t_map *map);
/* Map checking ft_check_map.c*/
int		ft_check_map(t_map *map);
/* Draw utilities ft_draw_utils.c*/
void	ft_get_draw_size(t_map *map);
/* play game ft_game.c */
int		ft_game(t_game *game);


typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_pmx	wall;
	int			pos;
}	t_vars;

#endif
