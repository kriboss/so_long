/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:29 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/31 12:20:15 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (i < 5 || map[i - 4] != '.' || map[i - 3] != 'b'
		|| map[i - 2] != 'e' || map[i - 1] != 'r')
		return (1);
	return (0);
}

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
		return (write(2, "Error\nFailed to load images", 28), -1);
	return (0);
}

void	put_img(t_list *list, t_img *img, int j, int i)
{
	if (list->map[i][j] == '1')
		mlx_put_image_to_window(list->mlx, list->wnd,
			img->bg, j * 50, i * 50);
	if (list->map[i][j] == '0')
		mlx_put_image_to_window(list->mlx, list->wnd,
			img->tile, j * 50, i * 50);
	if (list->map[i][j] == 'C')
		mlx_put_image_to_window(list->mlx, list->wnd,
			img->obj, j * 50, i * 50);
	else if (list->map[i][j] == 'E')
		mlx_put_image_to_window(list->mlx, list->wnd,
			img->exit, j * 50, i * 50);
	else if (list->map[i][j] == 'P')
		mlx_put_image_to_window(list->mlx, list->wnd,
			img->ply[0], j * 50, i * 50);
	else if (list->map[i][j] == 'X')
		mlx_put_image_to_window(list->mlx, list->wnd,
			img->en[0], j * 50, i * 50);
}

int	render_all(t_list *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (get_img(list->mlx, list->img) == -1)
		return (ft_free(list), exit(EXIT_FAILURE), 1);
	while (i < list->y)
	{
		j = 0;
		while (j < list->x)
		{
			put_img(list, list->img, j, i);
			j++;
		}
		i++;
	}
	return (0);
}
