/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:53:32 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/02 10:51:35 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//export DISPLAY=$(ip route | awk '/default/ {print $3}'):0
//use this command on the terminal to make the pop up window work

#include "fractol.h"

int main(int argc, char	**argv)
{
	t_fractol	fractol;
	
	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		||	(argc == 4 && ft_strcmp(argv[1], "julia") == 0))
	{
		fractol.name = argv[1];
		if (ft_strcmp(argv[1], "julia") == 0) 
		{
			fractol.julia_x = atodbl(argv[2]);
			fractol.julia_y = atodbl(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
		ft_putstr_fd("Usage: ./fractol julia [real] [imaginary]\n", 2);
		return (EXIT_FAILURE);
	}

}