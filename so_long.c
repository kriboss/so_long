/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/28 10:51:24 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *list)
{
	mlx_destroy_image(list->mlx, list->img->ply[0]);
	mlx_destroy_image(list->mlx, list->img->ply[1]);
	mlx_destroy_image(list->mlx, list->img->ply[2]);
	mlx_destroy_image(list->mlx, list->img->ply[3]);
	mlx_destroy_image(list->mlx, list->img->en[0]);
	mlx_destroy_image(list->mlx, list->img->en[1]);
	mlx_destroy_image(list->mlx, list->img->tile);
	mlx_destroy_image(list->mlx, list->img->exit);
	mlx_destroy_image(list->mlx, list->img->obj);
	mlx_destroy_image(list->mlx, list->img->bg);
	mlx_destroy_window(list->mlx, list->wnd);
	mlx_destroy_display(list->mlx);
	free(list->mlx);
	free_map(list->map);
	free(list->img);
	free(list->en->x);
	free(list->en->y);
	free(list->en);
	free(list);
}

int	render_en(t_list *l)
{
	int	i;
	int	j;

	i = ++l->img->frame;
	j = l->en->n - 1;
	if (i == 100000 || i == 200000)
	{
		while (j >= 0)
		{
			mlx_put_image_to_window(l->mlx, l->wnd,
				l->img->bg, l->en->x[j] * 50, l->en->y[j] * 50);
			mlx_put_image_to_window(l->mlx, l->wnd,
				l->img->tile, l->en->x[j] * 50, l->en->y[j] * 50);
			mlx_put_image_to_window(l->mlx, l->wnd,
				l->img->en[i / MF], l->en->x[j] * 50, l->en->y[j] * 50);
			j--;
		}
	}
	if (l->img->frame == MF)
		l->img->frame = 0;
	return (0);
}

int	key_hook(int keycode, t_list *list)
{
	if (keycode == 65307)
	{
		ft_free(list);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 119)
		game('w', list, list->img);
	else if (keycode == 115)
		game('s', list, list->img);
	else if (keycode == 97)
		game('a', list, list->img);
	else if (keycode == 100)
		game('d', list, list->img);
	return (0);
}

int	close_window(t_list *list)
{
	ft_free(list);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
		return (write(1, "Error\nMust include map", 23), EXIT_FAILURE);
	list = init();
	if (!list)
		return (write(1, "Error\nList init failed", 23), EXIT_FAILURE);
	if (parsing(list, argv[1]))
	{
		write(1, "Error\nParsing failed", 21);
		return (free(list->en), free(list->img), free(list), EXIT_FAILURE);
	}
	list->mlx = mlx_init();
	if (list->mlx == NULL)
		return (write(1, "Error\nMlx init failed", 22), EXIT_FAILURE);
	list->wnd = mlx_new_window(list->mlx,
			(list->x - 1) * 50, list->y * 50, "so_long");
	if (list->wnd == NULL)
		return (write(1, "Error\nMlx new window failed", 28), EXIT_FAILURE);
	render_all(list);
	mlx_loop_hook(list->mlx, render_en, list);
	mlx_hook(list->wnd, 17, 0, close_window, list);
	mlx_hook(list->wnd, 2, 1L << 0, key_hook, list);
	mlx_loop(list->mlx);
	return (EXIT_SUCCESS);
}
