/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:51:07 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/07 12:42:01 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MF 200000

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_img
{
	int		frame;
	void	*img;
	void	*ply[4];
	void	*en[2];
	void	*tile;
	void	*exit;
	void	*obj;
	void	*bg;
}	t_img;

typedef struct s_en
{
	int		*x;
	int		*y;
	int		n;
}	t_en;

typedef struct s_list
{
	void	*mlx;
	void	*wnd;
	char	**map;
	t_img	*img;
	t_en	*en;
	int		p;
	int		c;
	int		e;
	size_t	x;
	size_t	y;
	int		px;
	int		py;
	int		moves;
}	t_list;

void	ft_free(t_list *list);

t_list	*init(void);
int		parsing(t_list *list, char *map);
char	**mapdup(char **s);
int		check_map(t_list *list, t_list *tmp, int i, int j);
int		flood(t_list *list, int y, int x, t_list *tmp);
void	free_map(char **map);
int		render_all(t_list *list);
void	render(t_list *list);

int		game(char c, t_list *list, t_img *img);

#endif