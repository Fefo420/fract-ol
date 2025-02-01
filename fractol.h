/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:46:57 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/01 10:27:32 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

//LOCAL LIBRARIES
# include "./minilibx-linux/mlx.h" //REMOVE THIS LINE ON MACOS AND ADD THE 
									//MINILIX FOR MACOS

# define WIDTH 800
# define HEIGHT 800

//COLORS
#define BLACK 		0x000000
#define CRIMSON 	0xDC143C
#define GOLD 		0xFFD700
#define TEAL 		0x008080
#define WHITE		0xFFFFFF

//IMG : basically pixel buffer
//values given from mlx_data_addr
typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}	t_img;

// FRACT-0L ID
typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	
	//IMG VARIABLE
	t_img	img;

	//HOOK MEMBER VARIABLES
	double escape_value; //this is the value that we will use to determine if
						//the point is in the set or not
	
	int		iterations_definition;
	double	shift_x;
	double 	shift_y;
	double 	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

//COMPLEX VALUES
typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

//PROTOTYPES
	//utils.c
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);

	//init.c
void	fractol_init(t_fractol *fractol);
int 	track_julia(int x, int y, t_fractol *fractol);

	//render.c
void 	fractol_render(t_fractol *fractol);

	//math_utils.c
double	map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex  sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

	//events.c
int		key_handle(int	keysym, t_fractol *fractol);
int		mouse_handle(int button, t_fractol *fractol);
int		close_handle(t_fractol *fractol);

	//string_utils.c
double	atodbl(char	*s);
#endif