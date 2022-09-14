/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:58:01 by aquincho          #+#    #+#             */
/*   Updated: 2022/08/21 09:58:06 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_items(int i, t_map *map, int *item)
{
	int	res;

	res = 0;
	if (map->map[i] == 'P')
	{
		item[0]++;
		map->pos_P = i;
	}
	else if (map->map[i] == 'E')
	{
		item[1]++;
		map->pos_E = i;
	}
	else if (map->map[i] == 'C')
		item[2]++;
	else if (!(map->map[i] == '0' || map->map[i] == '1'))
		res = ft_errors("Item not defined found in the map.");
	map->item_cnt = item[2];
	return (res);
}

static int	ft_find_exitpath(t_map *map, char *tmp, int pos, int *result)
{
	if (tmp[pos] == 'E')
		*result = 1;
	else
		tmp[pos] = '1';
	if (!*result)
	{
		if (pos + 1 < map->width * map->height && tmp[pos + 1] != '1')
			ft_find_exitpath(map, tmp, pos + 1, result);
		if (pos - 1 >= 0 && tmp[pos - 1] != '1')
			ft_find_exitpath(map, tmp, pos - 1, result);
		if (pos + map->width < map->width * map->height
			&& tmp[pos + map->width] != '1')
			ft_find_exitpath(map, tmp, pos + map->width, result);
		if (pos - map->width >= 0 && tmp[pos - map->width] != '1')
			ft_find_exitpath(map, tmp, pos - map->width, result);
	}
	return (*result);
}

static int	ft_check_exitpath(t_map *map, int pos)
{
	int		result;
	char	*tmp;

	result = 0;
	tmp = ft_strdup(map->map);
	result = ft_find_exitpath(map, tmp, pos, &result);
	free (tmp);
	return (result);
}

int	ft_check_map(t_map *map)
{
	int	i;
	int	item[3];
	int	res;

	res = 0;
	item[0] = 0;
	item[1] = 0;
	item[2] = 0;
	i = -1;
	while (!res && ++i < map->width * map->height)
	{
		if ((i < map->width || i >= map->width * (map->height -1))
			&& map->map[i] != '1')
			res = ft_errors("Map not surrounded by walls.");
		else if ((i % map->width == 0 || ((i + 1) % map->width == 0))
			&& map->map[i] != '1')
			res = ft_errors("Map not surrounded by walls.");
		else
			res = ft_check_items(i, map, item);
	}
	if (!res && (item[0] != 1 || item[1] != 1 || item[2] < 1))
		res = ft_errors("Wrong number of items.");
	if (!res && !ft_check_exitpath(map, map->pos_P))
		res = ft_errors("No way out.");
	return (res);
}
