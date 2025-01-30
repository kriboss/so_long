/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:24 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/30 02:16:01 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_walls(t_map map)
{
	size_t i;
	size_t j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j + 1])
		{
			if (i == 0 || map.map[i + 1] == NULL)
			{
				if (map.map[i][j] != '1')
					return (write(1, "Error\n", 6), 1);
			}
			else if (j == 0 || j == ft_strlen(map.map[i]) - 1)
			{
				if (map.map[i][j] != '1')
					return (write(1, "Error\n", 6), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	flood(t_map *map, int y, int x)
{
	if (map->start == 1 && map->collect >= 1 && map->exit == 1)
		return (write(1, "Success\n", 8), 1);
	if (map->start > 1 || map->exit > 10)
	{
		return (write(1, "Error\n", 6), -1);
	}
	if (map->map[y][x] == '1')
		return (0);
	else if (map->map[y][x] == 'C')
		map->collect++;
	else if (map->map[y][x] == 'E')
		map->exit++;
	else if (map->map[y][x] == 'P')
		map->start++;
	map->map[y][x] = '1';
	if (flood(map, y + 1, x) || flood(map, y - 1, x)
		|| flood(map, y, x + 1) || flood(map, y, x - 1) == 1)
		return (1);
	return (0);
}

int parsing()
{
	int 	fd;
	int		i;
	int		j;
	t_map	map;

	i = 0;
	j = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file\n");
		return (1);
	}
	map.map = malloc(sizeof(char *) * 100);
	map.start = 0;
	map.collect = 0;
	map.exit = 0;
	map.map[i] = get_next_line(fd);
	while (map.map[i])
	{
		printf("%s\n", map.map[i]);
		map.map[++i] = get_next_line(fd);
	}
	i = 0;
	check_walls(map);
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '0')
			{
				if (flood(&map, i, j) != 1)
					return (write(1, "Error\n", 6), 1);
				break ;
			}
			j++;
		}
		i++;
	}
	while (i >= 0)
		free(map.map[i--]);
	free(map.map);
	close(fd);
	return (0);
}