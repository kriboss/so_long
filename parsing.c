/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:24 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/19 13:31:33 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	en_cord(t_list *list)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = list->en->n;
	list->en->x = malloc(sizeof(int) * (n + 1));
	if (!list->en->x)
		return (1);
	list->en->y = malloc(sizeof(int) * (n + 1));
	if (!list->en->y)
		return (free(list->en->x),1);
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == 'X')
			{
				list->en->x[n] = j;
				list->en->y[n] = i;
				n++;
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
	size_t	size;

	i = 0;
	size = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j] != '\0' && list->map[i][j] != '\n')
		{
			if ((i == 0 || list->map[i + 1] == NULL) && list->map[i][j] != '1')
				return (1);
			else if ((j == 0 || j == ft_strlen(list->map[i]) - 1)
				&& list->map[i][j] != '1')
				return (1);
			j++;
		}
		if (size != j && i != 0)
			return (1);
		size = j;
		i++;
	}
	list->x = j + 1;
	list->y = i;
	return (0);
}

int	flood(t_list *list, int y, int x, t_list *tmp)
{
	if (list->p == 1 && list->c >= 1 && list->e == 1)
		return (1);
	if (list->p > 1 || list->e > 1)
		return (write(1, "Error\n", 6), -1);
	if (tmp->map[y][x] == '1')
		return (0);
	if (tmp->map[y][x] == 'X')
		return (list->en->n++, 0);
	else if (tmp->map[y][x] == 'C')
		list->c++;
	else if (tmp->map[y][x] == 'E')
		list->e++;
	else if (tmp->map[y][x] == 'P')
	{
		list->p++;
		list->px = x;
		list->py = y;
	}
	tmp->map[y][x] = '1';
	if (flood(list, y + 1, x, tmp) || flood(list, y - 1, x, tmp)
		|| flood(list, y, x + 1, tmp) || flood(list, y, x - 1, tmp))
		return (1);
	return (0);
}

int	parsing(t_list *list)
{
	int		fd;
	int		i;
	int		j;
	t_list	tmp;

	i = 0;
	j = 0;
	tmp.p = 0;
	tmp.c = 0;
	tmp.e = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	list->map = malloc(sizeof(char *) * 100);
	if (!list->map)
		return (1);
	list->map[i] = get_next_line(fd);
	while (list->map[i])
	{
		printf("%s\n", list->map[i]);
		list->map[++i] = get_next_line(fd);
	}
	list->p = 0;
	list->c = 0;
	list->e = 0;
	if (check_walls(list) == 1)
		return (free_map(list->map),1);
	tmp.map = mapdup(list->map);
	i = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == '0')
			{
				if (flood(list, i, j, &tmp) != 1)
					return (free_map(tmp.map), free_map(list->map), 1);
				break ;
			}
			j++;
		}
		i++;
	}
	if (en_cord(list) == 1)
		return (free_map(tmp.map), free_map(list->map), 1);
	i = 0;
	while (tmp.map[i])
		free(tmp.map[i++]);
	free(tmp.map);
	close(fd);
	return (0);
}
