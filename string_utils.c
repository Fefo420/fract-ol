/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:10:01 by fileonar          #+#    #+#             */
/*   Updated: 2025/01/31 19:49:42 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atodbl(char	*s)
{
	long	int_part;
	double	fractional_part;
	double	pow;
	int		sign;
	
	int_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;

	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
		|| *s == '\r')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign *= -1;
		else
			s++;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.') 
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return ((int_part + fractional_part) * sign);
}
