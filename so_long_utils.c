/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:02:50 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/17 22:20:11 by kbossio          ###   ########.fr       */
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
	while (map[i])
		free(map[i++]);
	free(map);
}
