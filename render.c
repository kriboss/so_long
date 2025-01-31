/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:29 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/31 00:01:03 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_mlx *mlx, char *sprite, int y, int x)
{
	t_img	img;
	int		img_width;
	int		img_height;

	img.img = mlx_xpm_file_to_image(mlx->mlx, sprite, &img_width, &img_height);
	if (img.img == NULL) {
		printf("Failed to load image\n");
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, img.img, x*100, y*100);
}

void	render(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			write(1, &map->map[i][j], 1);
			if (map->map[i][j] == '1')
				load_img(mlx, "./sprites/Background.xpm", i, j);
			else if (map->map[i][j] == '0')
				load_img(mlx, "./sprites/Tile.xpm", i, j);
			else if (map->map[i][j] == 'C')
				load_img(mlx, "./sprites/Collectible.xpm", i, j);
			else if (map->map[i][j] == 'E')
				load_img(mlx, "./sprites/Exit.xpm", i, j);
			else if (map->map[i][j] == 'P')
				load_img(mlx, "./sprites/Astronaut.xpm", i, j);
			j++;
		}
		i++;
	}
}
