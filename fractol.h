/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 11:23:20 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/13 15:18:34 by cter-maa      ########   odam.nl         */
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

// defines
# define WIDTH 		600
# define HEIGHT		600
# define CORRECT	0
# define FAILURE	-1
# define false		0
# define MAX_ITTER	100
# define NUM_LAYERS 7
# define LAYER_RANGE (MAX_ITTER / NUM_LAYERS)

typedef enum e_choice
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
	NORMAL,
	RAINBOW,
	TRIPPY,
}	t_choice;

typedef struct s_colors
{
	int	color_type;
	int	red;
	int	black;
	int	color_set;
	int	color_set1;
	int	color_set2;
	int	color_set3;
	int	color_set4;
	int	color_set5;
	int	color_set6;
	int	color_set7;
}	t_colors;

// structures
typedef struct s_navigation
{
	int		width;
	int		height;
	double	zoom_factor;
	double	x_offset;
	double	y_offset;
	double	zoom_in;
	double	zoom_out;
	double	nav_step;
	double	y_nav;
	double	x_nav;
	double	c_real;
    double	c_imag;
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
	t_colors	colors;
	int			color;
	int			fractal_type;
	char		**argv;
} 	t_fractol;

// colors
void		get_color(t_fractol *generate, int x, int y, int iter);
uint32_t	ft_randomize(t_fractol *generate);

// hook_keys
void	hook_keys(void* param);
void	hook_navigation(t_fractol *generate);
void	hook_zoom(t_fractol *generate);
void	hook_colors(t_fractol *generate);

// hook_scroll
void	zoom_fractal(t_fractol *generate, double y_offset);
void	hook_scroll(double x_offset, double y_offset, void *param);


// fractals
void	mandelbrot(t_fractol *generate);
void	burningship(t_fractol *generate);
void	julia(t_fractol *generate) ;


// hook_mlx
void	init_mlx(t_fractol *generate);
void	open_screen(t_fractol *generate);
void	new_image(t_fractol *generate);
void	image_to_window(t_fractol *generate);
void	hooks(t_fractol *generate);


// initialize_parameters
void	init_fractal_settings(t_fractol *generate, char **argv);
void	init_color_type(t_colors *colors, char *argv);
void	reset_fractol_settings(t_fractol *generate);
void	init_fractal_type(t_fractol *generate, char *argv);
void	init_screen_settings_mandelbrot(t_screen *screen);
void	init_screen_settings_julia(t_screen *screen);
void	init_screen_settings_burningship(t_screen *screen);
void	init_navigation_mandelbrot(t_fractol *generate);
void	init_navigation_julia(t_fractol *generate);
void	init_navigation_burningship(t_fractol *generate);
void	init_trippy(t_colors *colors);
void	init_rainbow(t_colors *colors);
void	init_normal(t_colors *colors);
// void	init_colors(t_colors *colors, char *argv);

// utils
void 	update_fractal(t_fractol *generate);
void 	error_message(void);
void	put_inscription(t_fractol *generate);

#endif
