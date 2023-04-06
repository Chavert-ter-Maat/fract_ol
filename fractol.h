/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 11:23:20 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/06 14:07:46 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// header
#ifndef FRACTOL_H
# define FRACTOL_H

// includes
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <string.h>

// defines
# define WIDTH 		500
# define HEIGHT		500
# define CORRECT	0
# define FAILURE	-1
# define MAX_ITTER	100

typedef enum e_choice
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
}	t_choice;

typedef enum e_color
{
	RAINBOW,
}	t_color;

// structures
typedef struct s_navigation
{
	int		width;
	int		height;
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	zoom_in;
	double	zoom_out;
	double	nav_step;
	double	zoom_multiplier;
	double	y_nav;
	double	x_nav;
}	t_nav;

typedef struct s_screen
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}	t_screen;

typedef struct 	s_fractol
{		
	mlx_image_t	*image;
	mlx_t		*mlx;
	t_screen	screen;
	t_nav		nav;
	int			choice;
	int			color;
	char		**argv;
} 	t_fractol;


// hooks
void	hook(void* param);
void	my_scrollhook(double x_offset, double y_offset, void *param);


// fractals
void	init_mandelbrot(t_fractol *generate);
void	init_burningship(t_fractol *generate);


// initialize mlx
void	init_mlx(t_fractol *generate);
void	open_screen(t_fractol *generate);
void	new_image(t_fractol *generate);
void	image_to_window(t_fractol *generate);
void	hooks(t_fractol *generate);


// initialize parameters
void	init_fractal_settings(t_fractol *generate, char **argv);
void	init_color_type(t_fractol *generate, char *argv);
void	reset_fractol_settings(t_fractol *generate);
void	init_fractal_type(t_fractol *generate, char *argv);
void	init_screen_settings(t_screen *screen);
void	init_navigation(t_nav *mods);

// utils
void 	init_fractal(t_fractol	*generate);
void 	error_message(void);

#endif
