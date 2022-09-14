/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:15:08 by aquincho          #+#    #+#             */
/*   Updated: 2022/07/04 12:15:12 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_format_next_line(t_map *map)
{
	char	*res;
	char	*tmp;

	tmp = get_next_line(map->fd);
	if (tmp && tmp[ft_strlen(tmp) - 1] == '\n')
		res = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
	else if (tmp)
		res = ft_strdup(tmp);
	else
		res = NULL;
	free(tmp);
	return (res);
}

static int	ft_get_line(t_map *map, char *tmp, char *buff, int *res)
{
	while (buff)
	{
		tmp = ft_strjoin(map->map, buff);
		free(map->map);
		map->map = ft_strdup(tmp);
		free(tmp);
		free(buff);
		map->height += 1;
		buff = ft_format_next_line(map);
		if (!*res && buff && ((int)ft_strlen(buff) != map->width))
			*res = ft_errors("Map shape inacurate (not a rectangle).");
	}
	return (*res);
}

static int	ft_read_lines(t_map *map)
{
	char	*tmp;
	char	*buff;
	int		res;

	res = 0;
	tmp = NULL;
	buff = ft_format_next_line(map);
	if (!buff)
	{
		res = ft_errors("Empty map.");
		return (res);
	}
	map->width = ft_strlen(buff);
	if (map->width < 3)
		res = ft_errors("Map width inacurate (too small).");
	res = ft_get_line(map, tmp, buff, &res);
	buff = NULL;
	free(buff);
	if (!res && map->height < 3)
		res = ft_errors("Map height inacurate (too small).");
	return (res);
}

int	ft_read_map(char *filename, t_map *map)
{
	int	res;

	res = 0;
	if (ft_strlen(filename) < 4
		|| ft_strncmp((filename + ft_strlen(filename)- 4), ".ber", 4))
	{
		res = ft_errors("Wrong map format.");
		return (res);
	}
	map->filename = ft_substr(filename, 0, ft_strlen(filename) - 4);
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 1)
		res = ft_errors("Cannot read map.");
	else
		res = ft_read_lines(map);
	if (!res)
		res = ft_check_map(map);
	return (res);
}
