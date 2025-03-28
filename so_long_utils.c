/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:02:50 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/28 13:01:39 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mapdup(char **s)
{
	char	**ptr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = ft_strdup(s[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i <= 20 && map[i])
		free(map[i++]);
	free(map);
}

t_list	*init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->en = malloc(sizeof(t_en));
	if (!list->en)
		return (free(list), NULL);
	list->img = malloc(sizeof(t_img));
	if (!list->img)
		return (free(list->en), free(list), NULL);
	list->img->frame = 0;
	list->en->n = 0;
	list->map = NULL;
	list->px = 0;
	list->py = 0;
	list->moves = 0;
	list->p = 0;
	list->c = 0;
	list->e = 0;
	return (list);
}

int	check_map(t_list *list, t_list *tmp, int i, int j)
{
	if ((list->map[i][j] == 'P' && flood(list, i, j, tmp) != 1)
		|| (list->map[i][j] != '1' && list->map[i][j] != '0'
		&& list->map[i][j] != 'C' && list->map[i][j] != 'E'
		&& list->map[i][j] != 'P' && list->map[i][j] != 'X'))
		return (free_map(tmp->map), free_map(list->map), 1);
	if (list->map[i][j] == 'P')
		tmp->p++;
	return (0);
}

void	free_line(t_list *list, int fd, int i)
{
	if (i >= 20 && list->map[i])
	{
		free(list->map[i]);
		while (list->map[i])
		{
			list->map[i] = get_next_line(fd);
			free(list->map[i]);
		}
	}
}
