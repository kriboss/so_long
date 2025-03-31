/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:24 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/31 12:31:50 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	en_cord(t_list *list, int i)
{
	int	j;

	i = 0;
	list->en->x = malloc(sizeof(int) * (list->en->n + 1));
	if (!list->en->x)
		return (1);
	list->en->y = malloc(sizeof(int) * (list->en->n + 1));
	if (!list->en->y)
		return (free(list->en->x), 1);
	list->en->n = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == 'X')
			{
				list->en->x[list->en->n] = j;
				list->en->y[list->en->n++] = i;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(t_list *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	list->x = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j] != '\0' && list->map[i][j] != '\n')
		{
			if ((i == 0 || list->map[i + 1] == NULL) && list->map[i][j] != '1')
				return (1);
			if ((j == 0 || list->map[i][j + 1] == '\0'
				|| list->map[i][j + 1] == '\n') && list->map[i][j] != '1')
				return (1);
			j++;
		}
		if ((list->x != j && i != 0) || j < 2)
			return (1);
		i++;
		list->x = j;
	}
	list->x = j + 1;
	list->y = i;
	return (0);
}

int	flood(t_list *list, int y, int x, t_list *tmp)
{
	if (list->p > 1 || list->e > 1)
		return (-1);
	if (tmp->map[y][x] == 'X')
		return (list->en->n++, 0);
	else if (tmp->map[y][x] == 'C')
		list->c++;
	else if (tmp->map[y][x] == 'E')
		return (tmp->map[y][x] = '1', list->e++, 0);
	else if (tmp->map[y][x] == 'P')
	{
		list->p++;
		list->px = x;
		list->py = y;
	}
	if (tmp->map[y][x] == '1')
		return (0);
	tmp->map[y][x] = '1';
	flood(list, y + 1, x, tmp);
	flood(list, y - 1, x, tmp);
	flood(list, y, x + 1, tmp);
	flood(list, y, x - 1, tmp);
	if (list->p == 1 && list->e == 1 && list->c > 0)
		return (1);
	return (0);
}

int	create_map(t_list *list, char *map, t_list *tmp)
{
	int	fd;
	int	i;

	i = 0;
	tmp->p = 0;
	tmp->c = 0;
	tmp->e = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (1);
	if (check_name(map) == 1)
		return (close(fd), 1);
	list->map = malloc(sizeof(char *) * 21);
	if (!list->map)
		return (close(fd), 1);
	list->map[i] = get_next_line(fd);
	while (i < 20 && list->map[i])
		list->map[++i] = get_next_line(fd);
	free_line(list, fd, i);
	if (i < 2 || (i >= 20 && list->map[i]) || check_walls(list) == 1)
		return (close(fd), free_map(list->map), 1);
	tmp->map = mapdup(list->map);
	if (!tmp->map)
		return (close(fd), free_map(list->map), 1);
	return (close(fd), 0);
}

int	parsing(t_list *list, char *map)
{
	int		i;
	int		j;
	t_list	tmp;

	i = 0;
	if (create_map(list, map, &tmp) == 1)
		return (1);
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j] != '\0' && list->map[i][j] != '\n')
		{
			if (check_map(list, &tmp, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	if (tmp.p != 1 || tmp.e != 1 || flood(list, tmp.py, tmp.px, &tmp) == -1
		|| list->p != 1 || list->e != 1 || list->c < 1 || list->c != tmp.c
		|| en_cord(list, i) == 1)
		return (free_map(tmp.map), free_map(list->map), 1);
	return (free_map(tmp.map), 0);
}
