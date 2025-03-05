/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/05 12:59:24 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *list)
{
	int	i;

	i = 0;
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
	while (list->map[i])
		free(list->map[i++]);
	free(list->map);
	free(list->img);
	free(list->en->x);
	free(list->en->y);
	free(list->en);
	free(list);
}

int	render_en(t_list *list)
{
	int	i;
	int	j;

	i = ++list->img->frame;
	j = list->en->n - 1;
	if (i == 100000 || i == 200000)
	{
		while (j >= 0)
		{
			mlx_put_image_to_window(list->mlx, list->wnd,
				list->img->bg, list->en->x[j] * 100, list->en->y[j] * 100);
			mlx_put_image_to_window(list->mlx, list->wnd,
				list->img->tile, list->en->x[j] * 100, list->en->y[j] * 100);
			mlx_put_image_to_window(list->mlx, list->wnd,
				list->img->en[i / 200000], list->en->x[j] * 100, list->en->y[j] * 100);
			j--;
		}
	}
	if (list->img->frame == 200000)
		list->img->frame = 0;
	return (0);
}

int	key_hook(int keycode, t_list *list)
{
	if (keycode == 65307)
	{
		ft_free(list);
		printf("Window closed with keycode: %d\n", keycode);
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
	printf("Window closed\n");
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_list	*list;

	list = init();
	if (!list)
		return (write(1, "Failed to initialize\n", 21), EXIT_FAILURE);
	if (parsing(list))
	{
		write(1, "Error\n", 6);
		return (free(list->en), free(list->img), free(list), EXIT_FAILURE);
	}
	list->mlx = mlx_init();
	if (list->mlx == NULL)
		return (write(1, "Failed to initialize MiniLibX\n", 30), EXIT_FAILURE);
	list->wnd = mlx_new_window(list->mlx,
			list->x * 100, list->y * 100, "so_long");
	if (list->wnd == NULL)
		return (write(1, "Failed to create wnd\n", 22), EXIT_FAILURE);
	render_all(list);
	mlx_loop_hook(list->mlx, render_en, list);
	mlx_hook(list->wnd, 17, 0, close_window, list);
	mlx_hook(list->wnd, 2, 1L << 0, key_hook, list);
	mlx_loop(list->mlx);
	return (EXIT_SUCCESS);
}
