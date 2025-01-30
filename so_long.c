/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/30 00:32:25 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{

	parsing();
	/*
	void *mlx;
	void *window;
	// Initialize connection to the graphical system
	mlx = mlx_init();
	if (mlx == NULL) {
		printf("Failed to initialize MiniLibX\n");
		return (EXIT_FAILURE);
	}
	
	// Create a window of size 800x600
	window = mlx_new_window(mlx, 800, 600, "MinilibX Test Window");
	if (window == NULL) {
		printf("Failed to create window\n");
		return (EXIT_FAILURE);
	}

	// Draw a red pixel at coordinates (400, 300)
	mlx_pixel_put(mlx, window, 400, 300, 0xFF0000);

	// Keep the window open and listen for events
	mlx_loop(mlx);
	*/

	return (EXIT_SUCCESS);
}
