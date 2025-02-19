/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:09:03 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/19 13:25:16 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(char c, t_list *list, t_img *img)
{
	void	*pl;
	char	*str;
	int		i;

	pl = img->ply[0];
	i = ++list->moves;
	str = ft_itoa(i);
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg, 0, 0);
	mlx_string_put(list->mlx, list->wnd, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(list->mlx, list->wnd, 60, 10, 0x00FFFFFF, str);
	free(str);
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg, list->px * 100, list->py * 100);
	mlx_put_image_to_window(list->mlx, list->wnd, img->tile, list->px * 100, list->py * 100);
	if (c == 'w')
	{
		list->py -= 1;
		pl = img->ply[1];
	}
	else if (c == 'a')
	{
		list->px -= 1;
		pl = img->ply[2];
	}
	else if (c == 's')
	{
		list->py += 1;
		pl = img->ply[0];
	}
	else if (c == 'd')
	{
		list->px += 1;
		pl = img->ply[3];
	}
	if (list->map[list->py][list->px] == 'X')
	{
		ft_free(list);
		printf("You lose!\n");
		exit(EXIT_SUCCESS);
	}
	if (list->map[list->py][list->px] == 'C')
	{
		list->c--;
		list->map[list->py][list->px] = '0';
		mlx_put_image_to_window(list->mlx, list->wnd, img->bg, list->px * 100, list->py * 100);
		mlx_put_image_to_window(list->mlx, list->wnd, img->tile, list->px * 100, list->py * 100);
		printf("Collectibles left: %d\n", list->c);
	}
	else if (list->map[list->py][list->px] == 'E')
	{
		if (list->c == 0)
		{
			ft_free(list);
			printf("You win!\n");
			exit(EXIT_SUCCESS);
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
	mlx_put_image_to_window(list->mlx, list->wnd, pl, list->px * 100, list->py * 100);
	return (0);
}
