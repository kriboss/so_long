/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/01 00:24:17 by kbossio          ###   ########.fr       */
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
	free(list);
}

int on_esc(int keycode, t_list *list)
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

int main()
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->img = malloc(sizeof(t_img));
	list->map = NULL;
	list->px = 0;
	list->py = 0;
	parsing(list);
	printf("x: %d\ny: %d\n", list->px, list->py);
	printf("x: %d\ny: %d\n", list->x, list->y);
	list->mlx = mlx_init();
	if (list->mlx == NULL)
		return (write(1, "Failed to initialize MiniLibX\n", 30), EXIT_FAILURE);
	list->wnd = mlx_new_window(list->mlx, list->x * 100, list->y * 100, "so_long");
	if (list->wnd == NULL)
		return (write(1, "Failed to create wnd\n", 22), EXIT_FAILURE);
	render_all(list, list->img, list->mlx, list->wnd);
	mlx_hook(list->wnd, 2, 1L<<0, on_esc, list);
	mlx_loop(list->mlx);
	return (EXIT_SUCCESS);
}
