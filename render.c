/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:29 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/09 15:13:27 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img(void *mlx, t_img *img)
{
	int	w;
	int	h;

	img->ply[0] = mlx_xpm_file_to_image(mlx, "./img/pl.xpm", &w, &h);
	img->ply[1] = mlx_xpm_file_to_image(mlx, "./img/pl-back.xpm", &w, &h);
	img->ply[2] = mlx_xpm_file_to_image(mlx, "./img/pl-left.xpm", &w, &h);
	img->ply[3] = mlx_xpm_file_to_image(mlx, "./img/pl-right.xpm", &w, &h);
	img->en[0] = mlx_xpm_file_to_image(mlx, "./img/en.xpm", &w, &h);
	img->en[1] = mlx_xpm_file_to_image(mlx, "./img/en1.xpm", &w, &h);
	img->tile = mlx_xpm_file_to_image(mlx, "./img/tile.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &w, &h);
	img->obj = mlx_xpm_file_to_image(mlx, "./img/obj.xpm", &w, &h);
	img->bg = mlx_xpm_file_to_image(mlx, "./img/bg.xpm", &w, &h);
	if (img->ply[0] == NULL || img->ply[1] == NULL || img->ply[2] == NULL
		|| img->ply[3] == NULL || img->en[0] == NULL || img->en[1] == NULL
		|| img->tile == NULL || img->exit == NULL
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
			mlx_put_image_to_window(mlx, wnd, img->bg, j * 100, i * 100);
			if (list->map[i][j] == '0')
				mlx_put_image_to_window(mlx, wnd, img->tile, j * 100, i * 100);
			if (list->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, wnd, img->obj, j * 100, i * 100);
			else if (list->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, wnd, img->exit, j * 100, i * 100);
			else if (list->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, wnd, img->ply[0], j * 100, i * 100);
			else if (list->map[i][j] == 'X')
				mlx_put_image_to_window(mlx, wnd, img->en[0], j * 100, i * 100);
			j++;
		}
		i++;
	}
	return (0);
}
