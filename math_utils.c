/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:20:35 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/01 13:23:34 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//map function to map a number from one range to another
//so since we have 800 800 window, we can map the x and y values to the range
//for the mandelbrot set for ex (-2 and 2)
double	map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max)
{
	return((new_max - new_min) * (unscaled_num - old_min) /
			(old_max - old_min) + new_min);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	
	t_complex result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

// real = x^2 - y^2
//imaginary = 2xy

t_complex square_complex(t_complex z)
{
	t_complex result;

	result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
