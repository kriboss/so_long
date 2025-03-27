/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:09:03 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/27 12:22:59 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_str(t_list *list, t_img *img)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(list->moves);
	write(1, "Moves: ", 7);
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg, 0, 0);
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg, 50, 0);
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg, 64, 0);
	mlx_string_put(list->mlx, list->wnd, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(list->mlx, list->wnd, 60, 10, 0x00FFFFFF, str);
	free(str);
}

void	*move(char c, t_list *list, t_img *img, void *pl)
{
	if (c == 'w' && list->map[list->py - 1][list->px] != '1'
		&& (list->map[list->py - 1][list->px] != 'E' || list->c == 0))
		return (list->moves++, list->py -= 1, pl = img->ply[1]);
	else if (c == 'a' && (list->map[list->py][list->px - 1] != '1'
		&& (list->map[list->py][list->px - 1] != 'E' || list->c == 0)))
		return (list->moves++, list->px -= 1, pl = img->ply[2]);
	else if (c == 's' && (list->map[list->py + 1][list->px] != '1'
		&& (list->map[list->py + 1][list->px] != 'E' || list->c == 0)))
		return (list->moves++, list->py += 1, pl = img->ply[0]);
	else if (c == 'd' && (list->map[list->py][list->px + 1] != '1'
		&& (list->map[list->py][list->px + 1] != 'E' || list->c == 0)))
		return (list->moves++, list->px += 1, pl = img->ply[3]);
	return (pl);
}

void	check(t_list *list, t_img *img)
{
	if (list->map[list->py][list->px] == 'X')
	{
		ft_free(list);
		write(1, "You lose!\n", 10);
		exit(EXIT_SUCCESS);
	}
	if (list->map[list->py][list->px] == 'C')
	{
		list->c--;
		list->map[list->py][list->px] = '0';
		mlx_put_image_to_window(list->mlx, list->wnd, img->bg,
			list->px * 50, list->py * 50);
		mlx_put_image_to_window(list->mlx, list->wnd, img->tile,
			list->px * 50, list->py * 50);
	}
	else if (list->map[list->py][list->px] == 'E')
	{
		if (list->c == 0)
		{
			ft_free(list);
			write(1, "You win!\n", 9);
			exit(EXIT_SUCCESS);
		}
	}
}

int	game(char c, t_list *list, t_img *img)
{
	void	*pl;
	int		i;

	i = list->moves;
	pl = img->ply[0];
	mlx_put_image_to_window(list->mlx, list->wnd, img->bg,
		list->px * 50, list->py * 50);
	mlx_put_image_to_window(list->mlx, list->wnd, img->tile,
		list->px * 50, list->py * 50);
	pl = move(c, list, img, pl);
	if (i + 1 == list->moves)
		put_str(list, img);
	check(list, img);
	mlx_put_image_to_window(list->mlx, list->wnd, pl,
		list->px * 50, list->py * 50);
	return (0);
}
