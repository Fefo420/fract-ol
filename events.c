/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:31:57 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/02 10:55:22 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int key_handle(int	keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handle(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_plus || keysym == XK_KP_Add)
		fractol->iterations_definition += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractol->iterations_definition -= 10;
	fractol_render(fractol);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	
    if (button == 5)
    {
        fractol->zoom *= 1.05;
    }
    else if (button == 4)
    {
        fractol->zoom *= 0.95;
    }
    fractol_render(fractol);
    return (0);	
}

int track_julia(int x, int y, t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "julia") == 0)
	{
		fractol->julia_x = (map(x, -2, 2, 0, WIDTH) * fractol->zoom) + 
							fractol->shift_x;
		fractol->julia_y = (map(y, 2, -2, 0, HEIGHT) * fractol->zoom) + 
							fractol->shift_y;
		fractol_render(fractol);
	}
	return (0);
}