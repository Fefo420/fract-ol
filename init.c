/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:20:45 by fileonar          #+#    #+#             */
/*   Updated: 2025/01/31 20:42:11 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definition = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_handle, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask,
			 mouse_handle, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask,
			 close_handle, fractol);
	
	mlx_hook(fractol->mlx_window, MotionNotify, PointerMotionMask,
			 track_julia, fractol);
}

void fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
	{
		ft_putstr_fd("Error: mlx_init() failed\n", 2);
		exit(EXIT_FAILURE);
	}
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT,
											 fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, 
											WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractol->img.pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr,
												&fractol->img.bits_per_pixel,
												&fractol->img.line_length,
												&fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}