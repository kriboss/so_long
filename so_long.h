/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:51:07 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/31 02:24:33 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		start;
	int		collect;
	int		exit;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	void	*subimg;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

int		parsing(t_map *map);
char	**mapdup(char **s);
void	render(t_mlx *mlx, t_map *map);

#endif