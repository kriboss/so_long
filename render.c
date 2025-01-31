/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:29 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/01 00:40:12 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img(void *mlx, t_img *img)
{
	int width;
	int height;
	
	img->ply[0] = mlx_xpm_file_to_image(mlx, "./img/Astronaut.xpm", &width, &height);
	img->ply[1] = mlx_xpm_file_to_image(mlx, "./img/Astronaut-back.xpm", &width, &height);
	img->ply[2] = mlx_xpm_file_to_image(mlx, "./img/Astronaut-right.xpm", &width, &height);
	img->ply[3] = mlx_xpm_file_to_image(mlx, "./img/Astronaut-left.xpm", &width, &height);
	img->tile = mlx_xpm_file_to_image(mlx, "./img/Tile.xpm", &width, &height);
	img->exit = mlx_xpm_file_to_image(mlx, "./img/Exit.xpm", &width, &height);
	img->obj = mlx_xpm_file_to_image(mlx, "./img/Collectible.xpm", &width, &height);
	img->bg = mlx_xpm_file_to_image(mlx, "./img/Background.xpm", &width, &height);
	if (img->ply[0] == NULL || img->ply[1] == NULL || img->ply[2] == NULL
		|| img->ply[3] == NULL || img->tile == NULL || img->exit == NULL
		|| img->obj == NULL || img->bg == NULL)
	{
		printf("Failed to load image\n");
		return (-1);
	}
	return (0);
}

int	render_all(t_list *list, t_img *img, void *mlx, void *wnd)
{
	int	i;
	int	j;

	i = 0;
	get_img(list->mlx, list->img);
	while (i < list->y)
	{
		j = 0;
		while (j < list->x)
		{
			mlx_put_image_to_window(mlx, wnd, img->bg, j*100, i*100);
			if (list->map[i][j] == '0')
				mlx_put_image_to_window(mlx, wnd, img->tile, j*100, i*100);
			if (list->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, wnd, img->obj, j*100, i*100);
			else if (list->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, wnd, img->exit, j*100, i*100);
			else if (list->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, wnd, img->ply[0], j*100, i*100);
			j++;
		}
		i++;
	}
	return (0);
}
