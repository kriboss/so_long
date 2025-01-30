/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/30 13:57:20 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		printf("Window closed with keycode: %d\n", keycode);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int main()
{
	t_mlx	mlx;
	parsing();
	
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL) {
		printf("Failed to initialize MiniLibX\n");
		return (EXIT_FAILURE);
	}
	mlx.window = mlx_new_window(mlx.mlx, 800, 600, "MinilibX Test Window");
	if (mlx.window == NULL) {
		printf("Failed to create window\n");
		return (EXIT_FAILURE);
	}
	mlx_pixel_put(mlx.mlx, mlx.window, 400, 300, 0xFF0000);
	mlx_hook(mlx.window, 2, 1L<<0, on_esc, &mlx);
	mlx_loop(mlx.mlx);

	return (EXIT_SUCCESS);
}
