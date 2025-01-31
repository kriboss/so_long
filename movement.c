/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:09:03 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/01 00:50:07 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(char c, t_list *list, t_img *img)
{
	list->moves++;
	mlx_string_put(list->mlx, list->wnd, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(list->mlx, list->wnd, 60, 10, 0x00FFFFFF, ft_itoa(list->moves));
	printf("x: %d y: %d\n", list->px, list->py);
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg, list->px*100, list->py*100);
	mlx_put_image_to_window(list->mlx, list->wnd, img->tile, list->px*100, list->py*100);
	if (c == 'w')
	{
		list->py -= 1;
	}
	else if (c == 'a')
	{
		list->px -= 1;	
	}
	else if (c == 's')
	{
		list->py += 1;
	}
	else if (c == 'd')
	{
		list->px += 1;
	}
	if (list->map[list->py][list->px] == 'C')
	{
		list->c--;
		mlx_put_image_to_window(list->mlx, list->wnd, img->bg, list->px*100, list->py*100);
		mlx_put_image_to_window(list->mlx, list->wnd, img->tile, list->px*100, list->py*100);
	}
	else if (list->map[list->py][list->px] == 'E')
	{
		if (list->c == 0)
		{
			ft_free(list);
			printf("You win!\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("You need to collect all the collectibles\n");
			return (0);
		}
	}
	else if (list->map[list->py][list->px] == '1')
	{
		if (c == 'w')
			list->py += 1;
		else if (c == 'a')
			list->px += 1;
		else if (c == 's')
			list->py -= 1;
		else if (c == 'd')
			list->px -= 1;
	}
	else if (list->map[list->py][list->px] == 'P')
	{
		if (c == 'w')
			list->py += 1;
		else if (c == 'a')
			list->px += 1;
		else if (c == 's')
			list->py -= 1;
		else if (c == 'd')
			list->px -= 1;
	}
	mlx_put_image_to_window(list->mlx, list->wnd, img->ply[0], list->px*100, list->py*100);
	return (0);
}