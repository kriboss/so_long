/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/19 13:29:08 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *list)
{
	int	i;

	i = 0;
	if (list->img->ply[0])
		mlx_destroy_image(list->mlx, list->img->ply[0]);
	if (list->img->ply[1])
		mlx_destroy_image(list->mlx, list->img->ply[1]);
	if (list->img->ply[2])
		mlx_destroy_image(list->mlx, list->img->ply[2]);
	if (list->img->ply[3])
		mlx_destroy_image(list->mlx, list->img->ply[3]);
	if (list->img->en[0])
		mlx_destroy_image(list->mlx, list->img->en[0]);
	if (list->img->en[1])
		mlx_destroy_image(list->mlx, list->img->en[1]);
	if (list->img->tile)
		mlx_destroy_image(list->mlx, list->img->tile);
	if (list->img->exit)
		mlx_destroy_image(list->mlx, list->img->exit);
	if (list->img->obj)
		mlx_destroy_image(list->mlx, list->img->obj);
	if (list->img->bg)
		mlx_destroy_image(list->mlx, list->img->bg);
	mlx_destroy_window(list->mlx, list->wnd);
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
	int	x;
	int	y;
	int	j;

	i = ++list->img->frame;
	j = list->en->n;
	if (j > 0 && (i == 200000 || i == 400000))
	{
		x = list->en->x[j];
		y = list->en->y[j];
		mlx_put_image_to_window(list->mlx, list->wnd, list->img->bg, x * 100, y * 100);
		mlx_put_image_to_window(list->mlx, list->wnd, list->img->tile, x * 100, y * 100);
		mlx_put_image_to_window(list->mlx, list->wnd, list->img->en[i / 400000], x * 100, y * 100);
		j--;
	}
	if (list->img->frame == 400000)
		list->img->frame = 0;
	return (0);
}

int	on_esc(int keycode, t_list *list)
{
	if (keycode == 65307)
	{
		ft_free(list);
		printf("Window closed with keycode: %d\n", keycode);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 119)
	{
		move('w', list, list->img);
		printf("up\n");
	}
	else if (keycode == 115)
	{
		move('s', list, list->img);
		printf("down\n");
	}
	else if (keycode == 97)
	{
		move('a', list, list->img);
		printf("left\n");
	}
	else if (keycode == 100)
	{
		move('d', list, list->img);
		printf("right\n");
	}
	return (0);
}

int	main(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->en = malloc(sizeof(t_en));
	list->img = malloc(sizeof(t_img));
	list->img->frame = 0;
	list->en->n = 0;
	list->map = NULL;
	list->px = 0;
	list->py = 0;
	list->moves = 0;
	if (parsing(list))
		return (free(list->en), free(list->img), free(list), write(1, "Error\n", 6), EXIT_FAILURE);
	printf("x: %d\ny: %d\n", list->px, list->py);
	printf("x: %d\ny: %d\n", list->x, list->y);
	list->mlx = mlx_init();
	if (list->mlx == NULL)
		return (write(1, "Failed to initialize MiniLibX\n", 30), EXIT_FAILURE);
	list->wnd = mlx_new_window(list->mlx, list->x * 100, list->y * 100, "so_long");
	if (list->wnd == NULL)
		return (write(1, "Failed to create wnd\n", 22), EXIT_FAILURE);
	render_all(list, list->img, list->mlx, list->wnd);
	mlx_loop_hook(list->mlx, render_en, list);
	mlx_hook(list->wnd, 2, 1L << 0, on_esc, list);
	mlx_loop(list->mlx);
	return (EXIT_SUCCESS);
}
