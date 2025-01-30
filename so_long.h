/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:51:07 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/30 01:06:34 by kbossio          ###   ########.fr       */
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

int		parsing();

#endif