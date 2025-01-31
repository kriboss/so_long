/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:51:07 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/01 00:46:34 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_img
{
	void	*img;
	void	*ply[4];
	void	*tile;
	void	*exit;
	void	*obj;
	void	*bg;
}	t_img;

typedef struct s_list
{
	void	*mlx;
	void	*wnd;
	char	**map;
	t_img	*img;
	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
	int		px;
	int		py;
	int		moves;
}	t_list;

void	ft_free(t_list *list);

int		parsing(t_list *list);
char	**mapdup(char **s);
int		render_all(t_list *list, t_img *img, void *mlx, void *wnd);
void	render(t_list *list);

int	move(char c, t_list *list, t_img *img);

#endif